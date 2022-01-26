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
    Texture tSkybox;
    tSkybox.id = LoadCubemap(faces, game.textures_path);
    tSkybox.type = "texture_skybox";
    tSkybox.path = "skybox";
    Texture tCube;
    tCube.id = TextureFromFile("square.png", game.textures_path);
    tCube.type = "texture_diffuse";
    tCube.path = "square.png";
    Texture ruby;
    ruby.id = TextureFromFile("ruby.png", game.textures_path);
    ruby.type = "texture_diffuse";
    ruby.path = "ruby.png";
    
    Texture white;
    white.id = TextureFromFile("white.png", game.textures_path);
    white.type = "texture_light";
    white.path = "white.png";
    Texture red;
    red.id = TextureFromFile("red.png", game.textures_path);
    red.type = "texture_light";
    red.path = "red.png";
    Texture green;
    green.id = TextureFromFile("green.png", game.textures_path);
    green.type = "texture_light";
    green.path = "green.png";
    game.light_textures.push_back(white);
    game.light_textures.push_back(red);
    game.light_textures.push_back(green);
    
    std::vector<Texture> skyboxTextures;
    skyboxTextures.push_back(tSkybox);
    std::vector<Texture> cubeTextures;
    cubeTextures.push_back(tCube);
    std::vector<Texture> rubyTextures;
    rubyTextures.push_back(ruby);
    
    cube skyboxMesh(skyboxTextures);

    // lighting options
    // ----------------
    game.light_data.position = glm::vec3(0.0f, 5.0f, 0.0f); // create a distant light position

    // materials
    // ---------
    Material chrome;
    chrome.untextured = true;
    chrome.ambient = glm::vec3(0.25f, 0.25f, 0.25f);
    chrome.diffuse = glm::vec3(0.4f, 0.4f, 0.4f);
    chrome.specular = glm::vec3(0.774597f, 0.774597f, 0.774597f);
    chrome.shininess = 76.8f;
    Material rubyMaterial;
    rubyMaterial.untextured = true;
    rubyMaterial.ambient = glm::vec3(0.1745f, 0.01175f, 0.01175f);
    rubyMaterial.diffuse = glm::vec3(0.61424f, 0.04136f, 0.04136f);
    rubyMaterial.specular = glm::vec3(0.727811f, 0.626959f, 0.626959f);
    rubyMaterial.shininess = 76.8;

    // creating objects
    // ----------------
    cube* myCube = new cube(cubeTextures);
    sphere* mySphere = new sphere(50, 50, rubyMaterial);
    sphere* mySphere2 = new sphere(50, 50, chrome);
    game.lightSource = new sphere(50, 50, std::vector<Texture>{game.light_textures[0]});

    // render loop, called every frame
    // -------------------------------
    while (!glfwWindowShouldClose(window))
    {
        game.CalculateDeltaTime();
        // call inputs update
        // ------------------
        game.currentCamera->handleInput(window, game.deltaTime);
        
        // render
        // ------
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // our projection matrix is made using perspective, with the current camera and screen dimensions
        // the last two values are respectively the minimum distance view and the maximum
        glm::mat4 projection = glm::perspective(glm::radians(game.currentCamera->zoom), (float)game.screen_width / (float)game.screen_height, 0.1f, 100.0f);
        // asking our camera to return the view matrix
        glm::mat4 view = game.currentCamera->GetViewMatrix();

        // configuring light source shader
        // -------------------------------
        game.light_source_shader->use();
        game.light_source_shader->setMat4("projection", projection);
        game.light_source_shader->setMat4("view", view);

        // draw light sources here
        // -----------------------
        game.lightSource->Draw(game.light_source_shader, game.light_data.position);

        // configuring texture shader
        // --------------------------
        game.texture_shader->use();
        game.texture_shader->setMat4("projection", projection);
        game.texture_shader->setMat4("view", view);
        game.texture_shader->setVec3("light.position", game.light_data.position);
        game.texture_shader->setVec3("light.ambient", game.light_data.ambient);
        game.texture_shader->setVec3("light.diffuse", game.light_data.diffuse);
        game.texture_shader->setVec3("light.specular", game.light_data.specular);
        game.texture_shader->setVec3("viewPos", game.currentCamera->position);

        // draw textured objects here
        // --------------------------
        myCube->Draw(game.texture_shader, glm::vec3(0.0f, 2.0f, 0.0f));

        // configuring the material shader
        // -------------------------------
        game.material_shader->use();
        game.material_shader->setMat4("projection", projection);
        game.material_shader->setMat4("view", view);
        game.material_shader->setVec3("light.position", game.light_data.position);
        game.material_shader->setVec3("light.ambient", game.light_data.ambient);
        game.material_shader->setVec3("light.diffuse", game.light_data.diffuse);
        game.material_shader->setVec3("light.specular", game.light_data.specular);
        game.material_shader->setVec3("viewPos", game.currentCamera->position);

        // draw material objects here
        // --------------------------
        mySphere->Draw(game.material_shader, glm::vec3(-2.0f, 0.0f, 0.0f));
        mySphere2->Draw(game.material_shader, glm::vec3(2.0f, 0.0f, 0.0f));

        // draw skybox at last
        // -------------------
        glDepthFunc(GL_LEQUAL);
        game.skybox_shader->use();
        view = glm::mat4(glm::mat3(game.currentCamera->GetViewMatrix()));
        game.skybox_shader->setMat4("view", view);
        game.skybox_shader->setMat4("projection", projection);
        skyboxMesh.Draw(game.skybox_shader);
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

    game.Terminate();
    // glfw: terminate, clearing all previously allocated GLFW resources
    // -----------------------------------------------------------------
    glfwTerminate();
    
    return 0;
}
