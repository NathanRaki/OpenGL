#include "game.h"
#include "camera.h"

camera::camera(glm::vec3 position, glm::vec3 up, float yaw, float pitch)
{
    this->position = position;
    this->world_up = up;
    this->front = glm::vec3(0.0f, 0.0f, 1.0f);
    this->yaw = yaw;
    this->pitch = pitch;
    this->zoom = ZOOM;
    this->movement_speed = SPEED;
    this->mouse_sensitivity = SENSITIVITY;
    updateCameraVectors();
}

glm::mat4 const camera::GetViewMatrix()
{
    return glm::lookAt(position, position + front, up);
}

void camera::handleInput(GLFWwindow* window, double deltaTime)
{
    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) { position += front * (float)deltaTime; }
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) { position += right * -(float)deltaTime; }
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) { position += front * -(float)deltaTime; }
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) { position += right * (float)deltaTime; }
    if (glfwGetKey(window, GLFW_KEY_R) == GLFW_PRESS) { position += up * (float)deltaTime; }
    if (glfwGetKey(window, GLFW_KEY_F) == GLFW_PRESS) { position += up * -(float)deltaTime; }
}

void camera::processMouseMovement(float xoffset, float yoffset, bool contrainPitch)
{
    xoffset *= mouse_sensitivity;
    yoffset *= mouse_sensitivity;

    yaw += xoffset;
    pitch += yoffset;

    if (contrainPitch)
    {
        if (pitch > 89.0f) { pitch = 89.0f; }
        else if (pitch < -89.0f) { pitch = -89.0f; }
    }
    updateCameraVectors();
}

void camera::processMouseScroll(float yoffset)
{
    if (zoom < 1.0f) { zoom = 1.0f; }
    else if (zoom > 45.0f) { zoom = 45.0f; }
    else { zoom -= yoffset; }
}

void camera::updateCameraVectors()
{
    glm::vec3 front;
    front.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
    front.y = sin(glm::radians(pitch));
    front.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
    this->front = glm::normalize(front);

    this->right = glm::normalize(glm::cross(this->front, this->world_up));
    this->up = glm::normalize(glm::cross(this->right, this->front));
}

void camera::gui(GLFWwindow* window)
{
    game* game_instance = static_cast<game*>(glfwGetWindowUserPointer(window));
    ImGui::SetNextWindowPos(ImVec2(game_instance->screen_width/100.0f*90.0f, game_instance->screen_height/100.0f*20.0f), ImGuiCond_Always, ImVec2(0.5, 0.5));
    
    ImGuiWindowFlags window_flags = 0;
    window_flags |= ImGuiWindowFlags_NoTitleBar;
    window_flags |= ImGuiWindowFlags_AlwaysAutoResize;
    ImGui::Begin("Inputs", 0, window_flags);
	
    ImGui::Text("Inputs: ");
    ImGui::Text("\tZ: Move Forward");
    ImGui::Text("\tS: Move Backward");
    ImGui::Text("\tQ: Move Left");
    ImGui::Text("\tD: Move Right");
    ImGui::Text("\tR: Move Up");
    ImGui::Text("\tF: Move Down");
    ImGui::Text("\n");
    ImGui::Text("\tMouse movement: Rotate");
    ImGui::Text("\tMouse scroll: Zoom");
    ImGui::Text("\tN: Switch light color");
    ImGui::Text("\tCurrent color: %i", game_instance->light_data.index);
    ImGui::Text("\n");
    ImGui::Text("\tECHAP: Exit game");

    ImGui::End();
}



