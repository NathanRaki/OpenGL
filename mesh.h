#pragma once

#include <glm/glm.hpp>
#include <string>
#include <vector>
#include "shader.h"

struct vertex
{
    glm::vec3 position;
    glm::vec3 normal;
    glm::vec2 tex_coords;
    glm::vec3 tangent;
    glm::vec3 bitangent;
};

struct texture
{
    unsigned int id;
    std::string type;
    std::string path;
};

struct material
{
    bool untextured = false;
    glm::vec3 ambient;
    glm::vec3 diffuse;
    glm::vec3 specular;
    float shininess;
};

unsigned int texture_from_file(const char* path, const std::string &directory, bool gamma = false);
unsigned int LoadCubemap(std::vector<std::string> faces, const std::string &directory);

class mesh
{
public:
    std::vector<vertex> vertices;
    std::vector<unsigned int> indices;
    std::vector<texture> textures;
    material mat;

    unsigned int vao;

    mesh();
    mesh(std::vector<vertex> vertices, std::vector<unsigned int> indices, std::vector<texture> textures);
    mesh(std::vector<vertex> vertices, std::vector<unsigned int> indices, material mat);

    void draw(shader* shader, glm::vec3 position = glm::vec3(0.0f), glm::vec3 scale = glm::vec3(1.0f), glm::vec3 rotation = glm::vec3(0.0f)) const;
    void setup_mesh();
    
private:
    unsigned int vbo_, ebo_;
};
