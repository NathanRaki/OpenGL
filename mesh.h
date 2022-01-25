#pragma once

#include <glm/glm.hpp>
#include <string>
#include <vector>
#include "shader.h"

struct Vertex
{
    glm::vec3 position;
    glm::vec3 normal;
    glm::vec2 tex_coords;
    glm::vec3 tangent;
    glm::vec3 bitangent;
};

struct Texture
{
    unsigned int id;
    std::string type;
    std::string path;
};

struct Material
{
    bool untextured = false;
    glm::vec3 ambient;
    glm::vec3 diffuse;
    glm::vec3 specular;
    float shininess;
};

unsigned int TextureFromFile(const char* path, const std::string &directory, bool gamma = false);
unsigned int LoadCubemap(std::vector<std::string> faces, const std::string &directory);

class mesh
{
public:
    std::vector<Vertex> vertices;
    std::vector<unsigned int> indices;
    std::vector<Texture> textures;
    Material material;

    unsigned int VAO;

    mesh();
    mesh(std::vector<Vertex> vertices, std::vector<unsigned int> indices, std::vector<Texture> textures);
    mesh(std::vector<Vertex> vertices, std::vector<unsigned int> indices, Material material);

    void Draw(shader* shader, glm::vec3 position = glm::vec3(0.0f), glm::vec3 scale = glm::vec3(1.0f), glm::vec3 rotation = glm::vec3(0.0f));
    void SetupMesh();
    
private:
    unsigned int VBO, EBO;
};
