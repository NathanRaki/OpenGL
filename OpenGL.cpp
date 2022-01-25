#include <iostream>

#include "game.h"
#include "shader.h"

int main(int argc, char* argv[])
{
    game game(1280, 720, "textures");
    game.currentCamera = new camera(glm::vec3(0.0f, 7.0f, 10.0f));
    
    GLFWwindow* window = game.initialize();
    std::cout << game.textures_path << std::endl;

    // lighting options
    // ----------------
    constexpr glm::vec3 light_color(1.0f); // rgb value, here it's white
    constexpr glm::vec3 light_diffuse = light_color * glm::vec3(0.8f); // adjusting the light diffuse value
    constexpr glm::vec3 light_ambient = light_diffuse * glm::vec3(0.2f); // adjusting the light ambient value
    constexpr glm::vec3 light_specular(1.0f, 1.0f, 1.0f);
    glm::vec3 light_pos(100.0f, 10.0f, 100.0f); // create a distant light position
    light_pos.x *= -0.64f; // scaling light position to match our skybox's sun
    light_pos.z *= -0.77f;

    // render loop, called every frame
    // -------------------------------
    while (!glfwWindowShouldClose(window))
    {
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

        // configuring texture shader
        // --------------------------
        game.texture_shader->use();
        game.texture_shader->setMat4("projection", projection);
        game.texture_shader->setMat4("view", view);
        game.texture_shader->setVec3("light.position", light_pos);
        game.texture_shader->setVec3("light.ambient", light_ambient);
        game.texture_shader->setVec3("light.diffuse", light_diffuse);
        game.texture_shader->setVec3("light.specular", light_specular);
        game.texture_shader->setVec3("viewPos", game.currentCamera->position);

        // draw textured objects here
        // --------------------------

        // glfw: swap buffers and poll IO events
        // -------------------------------------
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // glfw: terminate, clearing all previously allocated GLFW resources
    // -----------------------------------------------------------------
    glfwTerminate();
    
    return 0;
}
