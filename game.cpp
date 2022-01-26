#include "game.h"

#include <filesystem>
#include <iostream>

game::game(unsigned width, unsigned height, std::string tPath)
{
    this->screen_width = width;
    this->screen_height = height;

    this->textures_path = std::filesystem::current_path().generic_string() + "/data/textures/";
    this->shaders_path = std::filesystem::current_path().generic_string() + "/data/shaders/";

    this->last_x = width / 2.0f;
    this->last_y = height / 2.0f;
    this->first_mouse = true;

    deltaTime = 0.0f;
    lastFrame = 0.0f;

    light_data.index = 0;
    light_data.position = glm::vec3(0.0f);
    light_data.color = glm::vec3(1.0f);
    light_data.diffuse = light_data.color * glm::vec3(0.8f);
    light_data.ambient = light_data.diffuse * glm::vec3(0.2f);
    light_data.specular = glm::vec3(1.0f);
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
    texture_shader = new shader((shaders_path + "textureShader.vs").c_str(), (shaders_path + "textureShader.fs").c_str());
    material_shader = new shader((shaders_path + "materialShader.vs").c_str(), (shaders_path + "materialShader.fs").c_str());
    light_source_shader = new shader((shaders_path + "lightSourceShader.vs").c_str(), (shaders_path + "lightSourceShader.fs").c_str());
    skybox_shader = new shader((shaders_path + "skyboxShader.vs").c_str(), (shaders_path + "skyboxShader.fs").c_str());

    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO();
    (void)io;
    ImGui::StyleColorsDark();
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init("#version 130");

    glfwSetWindowUserPointer(window, this);

    return window;
}

void game::Terminate()
{
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
}


void game::CalculateDeltaTime()
{
    double currentFrame = glfwGetTime();
    deltaTime = currentFrame - lastFrame;
    lastFrame = currentFrame;
}

void game::switchLight()
{
    light_data.index = (light_data.index + 1) % 3;
    lightSource->textures = std::vector<Texture>{light_textures[light_data.index]};
    switch(light_data.index)
    {
    case 0:
        light_data.color = glm::vec3(1.0f);
        light_data.diffuse = light_data.color * glm::vec3(0.8f);
        light_data.ambient = light_data.diffuse * glm::vec3(0.2f);
        break;
    case 1:
        light_data.color = glm::vec3(0.87f, 0.27f, 0.23f);
        light_data.diffuse = light_data.color * glm::vec3(0.8f);
        light_data.ambient = light_data.diffuse * glm::vec3(0.2f);
        break;
    case 2:
        light_data.color = glm::vec3(0.23f, 0.87f, 0.41f);
        light_data.diffuse = light_data.color * glm::vec3(0.8f);
        light_data.ambient = light_data.diffuse * glm::vec3(0.2f);
        break;
    }
}


// glfw: called when window size changes
// -------------------------------------
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    game* game_instance = static_cast<game*>(glfwGetWindowUserPointer(window));
    glViewport(0, 0, width, height);
    game_instance->screen_width = width;
    game_instance->screen_height = height;
}

// glfw: called when simple press
// ------------------------------
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) { glfwSetWindowShouldClose(window, true); }
    
    game* game_instance = static_cast<game*>(glfwGetWindowUserPointer(window));
    if (key == GLFW_KEY_N && action == GLFW_PRESS) { game_instance->switchLight(); }
}

// glfw:: called when mouse moves
// ------------------------------
void mouse_callback(GLFWwindow* window, double xpos, double ypos)
{
    game* game_instance = static_cast<game*>(glfwGetWindowUserPointer(window));

    if (game_instance->first_mouse)
    {
        game_instance->last_x = xpos;
        game_instance->last_y = ypos;
        game_instance->first_mouse = false;
    }

    double xoffset = xpos - game_instance->last_x;
    double yoffset = game_instance->last_y - ypos;
    game_instance->last_x = xpos;
    game_instance->last_y = ypos;
    game_instance->currentCamera->processMouseMovement(xoffset, yoffset);
}

// glfw:: called when scrolling mouse wheel
// ----------------------------------------
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
{
    game* game_instance = static_cast<game*>(glfwGetWindowUserPointer(window));
    game_instance->currentCamera->processMouseScroll(yoffset);
}
