#pragma once

#include <glad/glad.h>
#include <string>
#include <GLFW/glfw3.h>
#include <imgui/imgui.h>
#include <imgui/imgui_impl_glfw.h>
#include <imgui/imgui_impl_opengl3.h>
#include "camera.h"
#include "shader.h"
#include "sphere.h"

struct lightData
{
    unsigned int index;
    glm::vec3 position;
    glm::vec3 color;
    glm::vec3 ambient;
    glm::vec3 diffuse;
    glm::vec3 specular;
    texture texture;
};

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
    sphere* lightSource;
    lightData light_data;
    std::vector<texture> light_textures;
    
    // Methods
    game(unsigned width, unsigned height, std::string tPath);
    GLFWwindow* initialize();
    static void terminate();
    void calculate_delta_time();
    void switch_light();
};

// glfw: callback functions
// ------------------------
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
void mouse_callback(GLFWwindow* window, double x_pos, double y_pos);
void scroll_callback(GLFWwindow* window, double x_offset, double y_offset);