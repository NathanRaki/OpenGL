#include "game.h"

#include <filesystem>
#include <iostream>

game::game(unsigned width, unsigned height, std::string tPath)
{
    this->screen_width = width;
    this->screen_height = height;

    this->texturesPath = std::filesystem::current_path().generic_string();

    this->last_x = width / 2.0f;
    this->last_y = height / 2.0f;
    this->first_mouse = true;
}

GLFWwindow* game::initialize()
{
    // glfw: initialize and configure
    // ------------------------------
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // glfw: window creation
    // --------------------
    GLFWwindow* window = glfwCreateWindow(screen_width, screen_height, "OpenGL", nullptr, nullptr);
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
    game* game = static_cast<game*>(glfwGetWindowUserPointer(window));
    glViewport(0, 0, width, height);
    game->screen_width = width;
    game->screen_height = height;
}

// glfw: called when simple press
// ------------------------------
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    game* game = static_cast<game*>(glfwGetWindowUserPointer(window));

    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) { glfwSetWindowShouldClose(window, true); }
}

// glfw:: called when mouse moves
// ------------------------------
void mouse_callback(GLFWwindow* window, double xpos, double ypos)
{
    game* game = static_cast<game*>(glfwGetWindowUserPointer(window));

    if (game->first_mouse)
    {
        game->last_x = xpos;
        game->last_y = ypos;
        game->first_mouse = false;
    }

    double xoffset = xpos - game->last_x;
    double yoffset = game->last_y - ypos;
    game->last_x = xpos;
    game->last_y = ypos;
}

// glfw:: called when scrolling mouse wheel
// ----------------------------------------
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
{
    game* game = static_cast<game*>(glfwGetWindowUserPointer(window));
}
