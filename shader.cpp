#include "shader.h"

#include <glad/glad.h>
#include <iostream>
#include <sstream>
#include <fstream>

shader::shader()
{
    
}

shader::shader(const char* vertex_path, const char* fragment_path)
{
    std::string vertex_code;
    std::string fragment_code;
    std::ifstream vertex_shader;
    std::ifstream fragment_shader;

    vertex_shader.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    fragment_shader.exceptions(std::ifstream::failbit | std::ifstream::badbit);

    try
    {
        // open files
        vertex_shader.open(vertex_path);
        fragment_shader.open(fragment_path);
        std::stringstream vertex_stream, fragment_stream;
        // read buffer content into streams
        vertex_stream << vertex_shader.rdbuf();
        fragment_stream << fragment_shader.rdbuf();
        // close files
        vertex_shader.close();
        fragment_shader.close();
        // convert streams into strings
        vertex_code = vertex_stream.str();
        fragment_code = fragment_stream.str();
    }
    catch (std::ifstream::failure e)
    {
        std::cout << "ERROR::SHADER::FILE_NOT_SUCCESSFULLY_READ" << std::endl;
    }
    const char* vertex_shader_code = vertex_code.c_str();
    const char* fragment_shader_code = fragment_code.c_str();

    // compile shaders
    unsigned vertex, fragment;
    vertex = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertex, 1, &vertex_shader_code, NULL);
    glCompileShader(vertex);
    checkCompileErrors(vertex, "VERTEX");
    fragment = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragment, 1, &fragment_shader_code, NULL);
    glCompileShader(fragment);
    checkCompileErrors(fragment, "FRAGMENT");

    id = glCreateProgram();
    glAttachShader(id, vertex);
    glAttachShader(id, fragment);
    glLinkProgram(id);
    checkCompileErrors(id, "PROGRAM");

    glDeleteShader(vertex);
    glDeleteShader(fragment);
}

void shader::use()
{
    glUseProgram(id);
}

void shader::setBool(const std::string &name, bool value) const
{
    glUniform1i(glGetUniformLocation(id, name.c_str()), (int)value);
}

void shader::setInt(const std::string &name, int value) const
{
    glUniform1i(glGetUniformLocation(id, name.c_str()), value);
}

void shader::setFloat(const std::string &name, float value) const
{
    glUniform1f(glGetUniformLocation(id, name.c_str()), value);
}

void shader::setVec3(const std::string &name, const glm::vec3 &vec) const
{
    glUniform3fv(glGetUniformLocation(id, name.c_str()), 1, &vec[0]);
}

void shader::setVec4(const std::string &name, const glm::vec4 &vec) const
{
    glUniform4fv(glGetUniformLocation(id, name.c_str()), 1, &vec[0]);
}

void shader::setMat4(const std::string &name, const glm::mat4 &mat) const
{
    glUniformMatrix4fv(glGetUniformLocation(id, name.c_str()), 1, GL_FALSE, &mat[0][0]);
}

void shader::checkCompileErrors(unsigned int shader, std::string type)
{
	int success;
	char infoLog[1024];
	if (type != "PROGRAM")
	{
		glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(shader, 1024, NULL, infoLog);
			std::cout << "ERROR::SHADER_COMPILATION_ERROR of type: " << type << "\n" << infoLog << "\n -- --------------------------------------------------- -- " << std::endl;
		}
	}
	else
	{
		glGetProgramiv(shader, GL_LINK_STATUS, &success);
		if (!success)
		{
			glGetProgramInfoLog(shader, 1024, NULL, infoLog);
			std::cout << "ERROR:PROGRAM_LINKING_ERROR of type: " << type << "\n" << infoLog << "\n -- --------------------------------------------------- -- " << std::endl;
		}
	}
}