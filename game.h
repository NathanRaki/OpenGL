#pragma once

#include <string>
#include <GLFW/glfw3.h>
#include "camera.h"

class game
{
public:

    // Camera
    camera* currentCamera;

    // Shaders

    // Window information
    unsigned screen_width, screen_height;
    double last_x, last_y;
    bool first_mouse;
    

    // Path Variables
    std::string texturesPath;

    // Methods
    game(unsigned width, unsigned height, std::string tPath);
    GLFWwindow* initialize();
};

// glfw: callback functions
// ------------------------
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
void mouse_callback(GLFWwindow* window, double xpos, double ypos);
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);