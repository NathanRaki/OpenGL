#include "game.h"
#include "camera.h"

camera::camera(glm::vec3 position, glm::vec3 up, float yaw, float pitch)
{
    this->position = position;
    this->world_up = up;
    this->front = glm::vec3(0.0f, 0.0f, -1.0f);
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

void camera::inputCallback(GLFWwindow* window)
{
    game* game_instance = static_cast<game*>(glfwGetWindowUserPointer(window));
    
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



