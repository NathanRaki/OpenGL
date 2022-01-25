#pragma once

#include <string>
#include <vector>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

class Game
{
public:

    // Camera

    // Shaders

    // Window informations
    unsigned screenWidth, screenHeight;
    double lastX, lastY;
    bool firstMouse;
    

    // Path Variables
    std::string texturesPath;

    // Methods
    Game(unsigned width, unsigned height, std::string tPath);
    GLFWwindow* Initialize();
};

// glfw: callback functions
// ------------------------
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
void mouse_callback(GLFWwindow* window, double xpos, double ypos);
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);