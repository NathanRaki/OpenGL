#include "game.h"

#include <filesystem>
#include <iostream>

Game::Game(unsigned width, unsigned height, std::string tPath)
{
    this->screenWidth = width;
    this->screenHeight = height;

    this->texturesPath = std::filesystem::current_path().generic_string();

    this->lastX = width / 2.0f;
    this->lastY = height / 2.0f;
    this->firstMouse = true;
}

GLFWwindow* Game::Initialize()
{
    // glfw: initialize and configure
    // ------------------------------
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // glfw: window creation
    // --------------------
    GLFWwindow* window = glfwCreateWindow(screenWidth, screenHeight, "OpenGL", nullptr, nullptr);
    if (window == nullptr)
    {
        std::cout << "Failed to create GLFW window." << std::endl;
        glfwTerminate();
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    glfwSetKeyCallback(window, key_callback);
    glfwSetCursorPosCallback(window, mouse_callback);
    glfwSetScrollCallback(window, scroll_callback);

    // glfw: capture mouse
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

    // glad: load all OpenGL function pointers
    // ---------------------------------------
    if (!gladLoadGLLoader(reinterpret_cast<GLADloadproc>(glfwGetProcAddress)))
    {
        std::cout << "Failed to initialize GLAD." << std::endl;
        glfwTerminate();
    }

    // configure global opengl state
    // -----------------------------
    glEnable(GL_DEPTH_TEST);

    // build and compile shader programs
    // ---------------------------------

    glfwSetWindowUserPointer(window, this);

    return window;
}

// glfw: called when window size changes
// -------------------------------------
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    Game* game = static_cast<Game*>(glfwGetWindowUserPointer(window));
    glViewport(0, 0, width, height);
    game->screenWidth = width;
    game->screenHeight = height;
}

// glfw: called when simple press
// ------------------------------
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    Game* game = static_cast<Game*>(glfwGetWindowUserPointer(window));

    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) { glfwSetWindowShouldClose(window, true); }
}

// glfw:: called when mouse moves
// ------------------------------
void mouse_callback(GLFWwindow* window, double xpos, double ypos)
{
    Game* game = static_cast<Game*>(glfwGetWindowUserPointer(window));

    if (game->firstMouse)
    {
        game->lastX = xpos;
        game->lastY = ypos;
        game->firstMouse = false;
    }

    double xoffset = xpos - game->lastX;
    double yoffset = game->lastY - ypos;
    game->lastX = xpos;
    game->lastY = ypos;
}

// glfw:: called when scrolling mouse wheel
// ----------------------------------------
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
{
    Game* game = static_cast<Game*>(glfwGetWindowUserPointer(window));
}
