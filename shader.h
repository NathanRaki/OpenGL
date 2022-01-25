﻿#pragma once

#include <string>
#include <glm/glm.hpp>

class shader
{
public:
    unsigned int id;

    shader();
    shader(const char* vertex_path, const char* fragment_path);

    void use();
    void setBool(const std::string &name, bool value) const;
    void setInt(const std::string &name, int value) const;
    void setFloat(const std::string &name, float value) const;
    void setVec3(const std::string &name, const glm::vec3 &value) const;
    void setVec4(const std::string &name, const glm::vec4 &value) const;
    void setMat4(const std::string &name, const glm::mat4 &value) const;
    
private:
    void checkCompileErrors(unsigned int shader, std::string type);
};
