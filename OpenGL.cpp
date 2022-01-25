#include "game.h"

int main(int argc, char* argv[])
{
    game game(1280, 720, "textures");
    game.currentCamera = new camera(glm::vec3(0.0f, 7.0f, 10.0f));
    
    GLFWwindow* window = game.initialize();

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
