#include <iostream>

#include "game.h"
#include "cube.h"
#include "sphere.h"
#include "shader.h"

int main(int argc, char* argv[])
{
    game game(1280, 720, "textures");
    game.currentCamera = new camera(glm::vec3(0.0f, 2.0f, 10.0f));
    
    GLFWwindow* window = game.initialize();

    // creating textures
    // -----------------
    std::vector<std::string> faces
    {
        "skybox/right.png",
        "skybox/left.png",
        "skybox/top.png",
        "skybox/bottom.png",
        "skybox/front.png",
        "skybox/back.png"
    };
    texture skybox_texture;
    skybox_texture.id = LoadCubemap(faces, game.textures_path);
    skybox_texture.type = "texture_skybox";
    skybox_texture.path = "skybox";
    texture cube_texture;
    cube_texture.id = texture_from_file("square.png", game.textures_path);
    cube_texture.type = "texture_diffuse";
    cube_texture.path = "square.png";
    
    texture white;
    white.id = texture_from_file("white.png", game.textures_path);
    white.type = "texture_light";
    white.path = "white.png";
    texture red;
    red.id = texture_from_file("red.png", game.textures_path);
    red.type = "texture_light";
    red.path = "red.png";
    texture green;
    green.id = texture_from_file("green.png", game.textures_path);
    green.type = "texture_light";
    green.path = "green.png";
    game.light_textures.push_back(white);
    game.light_textures.push_back(red);
    game.light_textures.push_back(green);
    
    std::vector<texture> skyboxTextures;
    skyboxTextures.push_back(skybox_texture);
    std::vector<texture> cubeTextures;
    cubeTextures.push_back(cube_texture);
    

    // lighting options
    // ----------------
    game.light_data.position = glm::vec3(0.0f, 5.0f, 0.0f); // create a distant light position

    // materials
    // ---------
    material chrome;
    chrome.untextured = true;
    chrome.ambient = glm::vec3(0.25f, 0.25f, 0.25f);
    chrome.diffuse = glm::vec3(0.4f, 0.4f, 0.4f);
    chrome.specular = glm::vec3(0.774597f, 0.774597f, 0.774597f);
    chrome.shininess = 76.8f;
    material ruby;
    ruby.untextured = true;
    ruby.ambient = glm::vec3(0.1745f, 0.01175f, 0.01175f);
    ruby.diffuse = glm::vec3(0.61424f, 0.04136f, 0.04136f);
    ruby.specular = glm::vec3(0.727811f, 0.626959f, 0.626959f);
    ruby.shininess = 76.8;

    // creating objects
    // ----------------
    cube skybox_mesh(skyboxTextures);
    auto textured_cube = new cube(cubeTextures);
    auto ruby_sphere = new sphere(50, 50, ruby);
    auto chrome_sphere = new sphere(50, 50, chrome);
    game.lightSource = new sphere(50, 50, std::vector<texture>{game.light_textures[0]});

    // render loop, called every frame
    // -------------------------------
    while (!glfwWindowShouldClose(window))
    {
        game.calculate_delta_time();
        // call inputs update
        // ------------------
        game.currentCamera->handle_input(window, game.deltaTime);
        
        // render
        // ------
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // our projection matrix is made using perspective, with the current camera and screen dimensions
        // the last two values are respectively the minimum distance view and the maximum
        glm::mat4 projection = glm::perspective(glm::radians(game.currentCamera->zoom), static_cast<float>(game.screen_width) / static_cast<float>(game.screen_height), 0.1f, 100.0f);
        // asking our camera to return the view matrix
        glm::mat4 view = game.currentCamera->get_view_matrix();

        // configuring light source shader
        // -------------------------------
        game.light_source_shader->use();
        game.light_source_shader->set_mat4("projection", projection);
        game.light_source_shader->set_mat4("view", view);

        // draw light sources here
        // -----------------------
        game.lightSource->draw(game.light_source_shader, game.light_data.position, glm::vec3(0.2f, 0.2f, 0.2f));

        // configuring texture shader
        // --------------------------
        game.texture_shader->use();
        game.texture_shader->set_mat4("projection", projection);
        game.texture_shader->set_mat4("view", view);
        game.texture_shader->set_vec3("light.position", game.light_data.position);
        game.texture_shader->set_vec3("light.ambient", game.light_data.ambient);
        game.texture_shader->set_vec3("light.diffuse", game.light_data.diffuse);
        game.texture_shader->set_vec3("light.specular", game.light_data.specular);
        game.texture_shader->set_vec3("viewPos", game.currentCamera->position);

        // draw textured objects here
        // --------------------------
        textured_cube->draw(game.texture_shader, glm::vec3(0.0f, 2.0f, 0.0f));

        // configuring the material shader
        // -------------------------------
        game.material_shader->use();
        game.material_shader->set_mat4("projection", projection);
        game.material_shader->set_mat4("view", view);
        game.material_shader->set_vec3("light.position", game.light_data.position);
        game.material_shader->set_vec3("light.ambient", game.light_data.ambient);
        game.material_shader->set_vec3("light.diffuse", game.light_data.diffuse);
        game.material_shader->set_vec3("light.specular", game.light_data.specular);
        game.material_shader->set_vec3("viewPos", game.currentCamera->position);

        // draw material objects here
        // --------------------------
        ruby_sphere->draw(game.material_shader, glm::vec3(-2.0f, 0.0f, 0.0f));
        chrome_sphere->draw(game.material_shader, glm::vec3(2.0f, 0.0f, 0.0f));

        // draw skybox at last
        // -------------------
        glDepthFunc(GL_LEQUAL);
        game.skybox_shader->use();
        view = glm::mat4(glm::mat3(game.currentCamera->get_view_matrix()));
        game.skybox_shader->set_mat4("view", view);
        game.skybox_shader->set_mat4("projection", projection);
        skybox_mesh.draw(game.skybox_shader);
        glDepthFunc(GL_LESS);

        // ImGui displaying
        // ----------------
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();
        game.currentCamera->gui(window);
        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());	

        // glfw: swap buffers and poll IO events
        // -------------------------------------
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    game.terminate();
    // glfw: terminate, clearing all previously allocated GLFW resources
    // -----------------------------------------------------------------
    glfwTerminate();
    
    return 0;
}
