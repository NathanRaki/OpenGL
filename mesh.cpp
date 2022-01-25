﻿#include "mesh.h"
#include <glad/glad.h>
#include <glm/ext/matrix_transform.hpp>
#define STB_IMAGE_IMPLEMENTATION
#include <stb/stb_image.h>
#include <iostream>

mesh::mesh()
{
    
}

mesh::mesh(std::vector<Vertex> vertices, std::vector<unsigned> indices, std::vector<Texture> textures)
{
    this->vertices = vertices;
    this->indices = indices;
    this->textures = textures;
    SetupMesh();
}

mesh::mesh(std::vector<Vertex> vertices, std::vector<unsigned> indices, Material material)
{
    this->vertices = vertices;
    this->indices = indices;
    this->material = material;
    SetupMesh();
}

void mesh::Draw(shader* shader, glm::vec3 position, glm::vec3 scale, glm::vec3 rotation)
{
    unsigned int diffuseNr	= 1;
    unsigned int specularNr = 1;
    unsigned int normalNr	= 1;
    unsigned int heightNr	= 1;

    if (textures.size() > 0)
    {
        for (unsigned int i = 0; i < textures.size(); i++)
        {
            glActiveTexture(GL_TEXTURE0 + i);
            std::string number;
            std::string name = textures[i].type;
            if (name == "texture_diffuse")
            {
                number = std::to_string(diffuseNr++);
                name = "material.diffuse";
            }
            else if (name == "texture_specular")
            {
                number = std::to_string(specularNr++);
                name = "material.specular";
            }
            else if (name == "texture_normal")
            {
                number = std::to_string(normalNr++);
            }
            else if (name == "texture_height")
            {
                number = std::to_string(heightNr++);
            }
            else if (name == "texture_skybox")
            {
                name = "skybox";
                number = "";
            }
            else if (name == "texture_light")
            {
                number = "";
            }
            glUniform1i(glGetUniformLocation(shader->id, (name+number).c_str()), i);
            shader->setFloat("material.shininess", 32.0f);
            glBindTexture(GL_TEXTURE_2D, textures[i].id);
        }
    }
    else if (material.untextured)
    {
        shader->setVec3("material.ambient", material.ambient);
        shader->setVec3("material.diffuse", material.diffuse);
        shader->setVec3("material.specular", material.specular);
        shader->setFloat("material.shininess", 32.0f);
    }

    glm::mat4 model = glm::mat4(1.0f);
    model = translate(model, position);
    model = rotate(model, glm::radians(rotation.x), glm::vec3(1.0f, 0.0f, 0.0f)); // Pitch
    model = rotate(model, glm::radians(rotation.y), glm::vec3(0.0f, 1.0f, 0.0f)); // Yaw
    model = rotate(model, glm::radians(rotation.z), glm::vec3(0.0f, 0.0f, 1.0f)); // Roll
    model = glm::scale(model, scale);
    shader->setMat4("model", model);

    // draw mesh
    glBindVertexArray(VAO);
    glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);

    // always good practice to set everything back to defaults once configured
    for (unsigned int i = 0; i < textures.size(); i++)
    {
        glActiveTexture(GL_TEXTURE0 + i);
        glBindTexture(GL_TEXTURE_2D, 0);
    }
}

void mesh::SetupMesh()
{
    // create buffers/arrays
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    glBindVertexArray(VAO);
    // load dat into vertex buffers
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    // a great thing about structs is that their memory layout is sequential for all its items
    // the effect is that we can simply pass a pointer to the struct and it translates perfectly to a glm::vec3/2 array which
    // again translates to 3/2 floats which translates to a byte array
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex), &vertices[0], GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), &indices[0], GL_STATIC_DRAW);

    // set the vertex attribute pointers
    // vertex Positions
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)0);
    // vertex Normals
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, normal));
    // vertex texture coords
    glEnableVertexAttribArray(2);
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, tex_coords));
    // vertex tangeant
    glEnableVertexAttribArray(3);
    glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, tangent));
    // vertex bitangeant
    glEnableVertexAttribArray(4);
    glVertexAttribPointer(4, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, bitangent));

    glBindVertexArray(0);
}

unsigned TextureFromFile(const char* path, const std::string& directory, bool gamma)
{
    std::string filename = std::string(path);
    filename = directory + '/' + filename;

    unsigned int textureID;
    glGenTextures(1, &textureID);

    int width, height, nrComponents;
    unsigned char *data = stbi_load(filename.c_str(), &width, &height, &nrComponents, 0);
    if (data)
    {
        GLenum format;
        if (nrComponents == 1)
            format = GL_RED;
        else if (nrComponents == 3)
            format = GL_RGB;
        else if (nrComponents == 4)
            format = GL_RGBA;

        glBindTexture(GL_TEXTURE_2D, textureID);
        glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

        stbi_image_free(data);
    }
    else
    {
        std::cout << "Texture failed to load at path: " << path << std::endl;
        stbi_image_free(data);
    }

    return textureID;
}

unsigned LoadCubemap(std::vector<std::string> faces, const std::string& directory)
{
    unsigned int textureID;
    std::string filename;
    glGenTextures(1, &textureID);
    glBindTexture(GL_TEXTURE_CUBE_MAP, textureID);

    int width, height, nrChannels;
    for (unsigned int i = 0; i < faces.size(); i++)
    {
        filename = directory + '/' + faces[i];
        unsigned char *data = stbi_load(filename.c_str(), &width, &height, &nrChannels, 0);
        if (data)
        {
            GLenum format;
            if (nrChannels == 1)
                format = GL_RED;
            else if (nrChannels == 3)
                format = GL_RGB;
            else if (nrChannels == 4)
                format = GL_RGBA;
            glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + i, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
            stbi_image_free(data);
        }
        else
        {
            std::cout << "Cubemap texture failed to load at path: " << filename << std::endl;
            stbi_image_free(data);
        }
    }
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    return textureID;
}



