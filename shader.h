﻿#pragma once

#include <string>
#include <glm/glm.hpp>

class shader
{
public:
    unsigned int id;

    shader();
    shader(const char* vertex_path, const char* fragment_path);

    void use() const;
    void set_bool(const std::string &name, bool value) const;
    void set_int(const std::string &name, int value) const;
    void set_float(const std::string &name, float value) const;
    void set_vec3(const std::string &name, const glm::vec3 &value) const;
    void set_vec4(const std::string &name, const glm::vec4 &value) const;
    void set_mat4(const std::string &name, const glm::mat4 &value) const;
    
private:
    static void check_compile_errors(unsigned int shader, std::string type);
};
