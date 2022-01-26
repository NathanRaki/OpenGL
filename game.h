#pragma once

#include <glad/glad.h>
#include <string>
#include <GLFW/glfw3.h>
#include "camera.h"
#include "shader.h"

class game
{
public:

    // Camera
    camera* currentCamera;

    // Shaders
    shader* texture_shader;
    shader* material_shader;
    shader* light_source_shader;
    shader* skybox_shader;

    // Window information
    unsigned screen_width, screen_height;
    double last_x, last_y;
    bool first_mouse;
    
    // Path Variables
    std::string textures_path;
    std::string shaders_path;

    // Game data
    double deltaTime;
    double lastFrame;
    
    // Methods
    game(unsigned width, unsigned height, std::string tPath);
    GLFWwindow* initialize();
    void CalculateDeltaTime();
};

// glfw: callback functions
// ------------------------
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
void mouse_callback(GLFWwindow* window, double xpos, double ypos);
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);