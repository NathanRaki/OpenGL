﻿#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

// Default values
const float YAW			= 0.0f;
const float PITCH		= 0.0f;
const float SPEED		= 2.5f;
const float SENSITIVITY = 0.1f;
const float ZOOM		= 45.0f;

enum camera_movement { forward, backward, left, right, up, down };

class camera
{
public:
    // Camera attributes
    glm::vec3 position, front, up, right, world_up;
    float yaw, pitch;
    float movement_speed, mouse_sensitivity, zoom;

    camera(glm::vec3 position = glm::vec3(0.0f),
            glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f),
            float yaw = YAW,
            float pitch = PITCH);

    glm::mat4 const GetViewMatrix();
    void inputCallback(GLFWwindow* window);
    void processMouseMovement(float xoffset, float yoffset, bool contrainPitch);
    void processMouseScroll(float yoffset);

private:
    void updateCameraVectors();
};