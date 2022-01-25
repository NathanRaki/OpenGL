#include "cube.h"

cube::cube(std::vector<Texture> textures)
{
    Vertex vertex;

	// Front Face
	vertex.position = glm::vec3(-0.5f, -0.5f, -0.5f);
	vertex.normal = glm::vec3( 0.0f, 0.0f, -1.0f);
	vertex.tex_coords = glm::vec2(0.0f, 0.0f);
	this->vertices.push_back(vertex); // indice 0
	vertex.position = glm::vec3(0.5f, -0.5f, -0.5f);
	vertex.normal = glm::vec3( 0.0f, 0.0f, -1.0f);
	vertex.tex_coords = glm::vec2(1.0f, 0.0f);
	this->vertices.push_back(vertex); // indice 1
	vertex.position = glm::vec3(0.5f, 0.5f, -0.5f);
	vertex.normal = glm::vec3( 0.0f, 0.0f, -1.0f);
	vertex.tex_coords = glm::vec2(1.0f, 1.0f);
	this->vertices.push_back(vertex); // indice 2
	vertex.position = glm::vec3(-0.5f, 0.5f, -0.5f);
	vertex.normal = glm::vec3( 0.0f, 0.0f, -1.0f);
	vertex.tex_coords = glm::vec2(0.0f, 1.0f);
	this->vertices.push_back(vertex); // indice 3

	// Back Face
	vertex.position = glm::vec3(0.5f, -0.5f, 0.5f);
	vertex.normal = glm::vec3( 0.0f, 0.0f, 1.0f);
	vertex.tex_coords = glm::vec2(0.0f, 0.0f);
	this->vertices.push_back(vertex); // indice 4
	vertex.position = glm::vec3(-0.5f, -0.5f, 0.5f);
	vertex.normal = glm::vec3( 0.0f, 0.0f, 1.0f);
	vertex.tex_coords = glm::vec2(1.0f, 0.0f);
	this->vertices.push_back(vertex); // indice 5
	vertex.position = glm::vec3(-0.5f, 0.5f, 0.5f);
	vertex.normal = glm::vec3( 0.0f, 0.0f, 1.0f);
	vertex.tex_coords = glm::vec2(1.0f, 1.0f);
	this->vertices.push_back(vertex); // indice 6
	vertex.position = glm::vec3(0.5f, 0.5f, 0.5f);
	vertex.normal = glm::vec3( 0.0f, 0.0f, 1.0f);
	vertex.tex_coords = glm::vec2(0.0f, 1.0f);
	this->vertices.push_back(vertex); // indice 7

	// Left Face
	vertex.position = glm::vec3(-0.5f, -0.5f, 0.5f);
	vertex.normal = glm::vec3( -1.0f, 0.0f, 0.0f);
	vertex.tex_coords = glm::vec2(1.0f, 0.0f);
	this->vertices.push_back(vertex); // indice 8
	vertex.position = glm::vec3(-0.5f, -0.5f, -0.5f);
	vertex.normal = glm::vec3( -1.0f, 0.0f, 0.0f);
	vertex.tex_coords = glm::vec2(0.0f, 0.0f);
	this->vertices.push_back(vertex); // indice 9
	vertex.position = glm::vec3(-0.5f, 0.5f, -0.5f);
	vertex.normal = glm::vec3( -1.0f, 0.0f, 0.0f);
	vertex.tex_coords = glm::vec2(0.0f, 1.0f);
	this->vertices.push_back(vertex); // indice 10
	vertex.position = glm::vec3(-0.5f, 0.5f, 0.5f);
	vertex.normal = glm::vec3( -1.0f, 0.0f, 0.0f);
	vertex.tex_coords = glm::vec2(1.0f, 1.0f);
	this->vertices.push_back(vertex); // indice 11

	// Right Face
	vertex.position = glm::vec3(0.5f, -0.5f, -0.5f);
	vertex.normal = glm::vec3( 1.0f, 0.0f, 0.0f);
	vertex.tex_coords = glm::vec2(1.0f, 0.0f);
	this->vertices.push_back(vertex); // indice 12
	vertex.position = glm::vec3(0.5f, -0.5f, 0.5f);
	vertex.normal = glm::vec3( 1.0f, 0.0f, 0.0f);
	vertex.tex_coords = glm::vec2(0.0f, 0.0f);
	this->vertices.push_back(vertex); // indice 13
	vertex.position = glm::vec3(0.5f, 0.5f, 0.5f);
	vertex.normal = glm::vec3( 1.0f, 0.0f, 0.0f);
	vertex.tex_coords = glm::vec2(0.0f, 1.0f);
	this->vertices.push_back(vertex); // indice 14
	vertex.position = glm::vec3(0.5f, 0.5f, -0.5f);
	vertex.normal = glm::vec3( 1.0f, 0.0f, 0.0f);
	vertex.tex_coords = glm::vec2(1.0f, 1.0f);
	this->vertices.push_back(vertex); // indice 15

	// Bottom Face
	vertex.position = glm::vec3(-0.5f, -0.5f, 0.5f);
	vertex.normal = glm::vec3( 0.0f, -1.0f, 0.0f);
	vertex.tex_coords = glm::vec2(0.0f, 0.0f);
	this->vertices.push_back(vertex); // indice 16
	vertex.position = glm::vec3(0.5f, -0.5f, 0.5f);
	vertex.normal = glm::vec3( 0.0f, -1.0f, 0.0f);
	vertex.tex_coords = glm::vec2(1.0f, 0.0f);
	this->vertices.push_back(vertex); // indice 17
	vertex.position = glm::vec3(0.5f, -0.5f, -0.5f);
	vertex.normal = glm::vec3( 0.0f, -1.0f, 0.0f);
	vertex.tex_coords = glm::vec2(1.0f, 1.0f);
	this->vertices.push_back(vertex); // indice 18
	vertex.position = glm::vec3(-0.5f, -0.5f, -0.5f);
	vertex.normal = glm::vec3( 0.0f, -1.0f, 0.0f);
	vertex.tex_coords = glm::vec2(0.0f, 1.0f);
	this->vertices.push_back(vertex); // indice 19

	// Top Face
	vertex.position = glm::vec3(-0.5f, 0.5f, 0.5f);
	vertex.normal = glm::vec3( 0.0f, 1.0f, 0.0f);
	vertex.tex_coords = glm::vec2(0.0f, 0.0f);
	this->vertices.push_back(vertex); // indice 20
	vertex.position = glm::vec3(0.5f, 0.5f, 0.5f);
	vertex.normal = glm::vec3( 0.0f, 1.0f, 0.0f);
	vertex.tex_coords = glm::vec2(1.0f, 0.0f);
	this->vertices.push_back(vertex); // indice 21
	vertex.position = glm::vec3(0.5f, 0.5f, -0.5f);
	vertex.normal = glm::vec3( 0.0f, 1.0f, 0.0f);
	vertex.tex_coords = glm::vec2(1.0f, 1.0f);
	this->vertices.push_back(vertex); // indice 22
	vertex.position = glm::vec3(-0.5f, 0.5f, -0.5f);
	vertex.normal = glm::vec3( 0.0f, 1.0f, 0.0f);
	vertex.tex_coords = glm::vec2(0.0f, 1.0f);
	this->vertices.push_back(vertex); // indice 23

	unsigned int ind[] = {	0, 1, 2, 0, 2, 3,
							4, 5, 6, 4, 6, 7,
							8, 9, 10, 8, 10, 11,
							12, 13, 14, 12, 14, 15,
							16, 17, 18, 16, 18, 19,
							20, 21, 22, 20, 22, 23	};
	std::vector<unsigned int> vInd(ind, ind+36);
	this->indices = vInd;

	this->textures = textures;

	SetupMesh();
}

cube::cube(Material material)
{
	Vertex vertex;

	// Front Face
	vertex.position = glm::vec3(-0.5f, -0.5f, -0.5f);
	vertex.normal = glm::vec3( 0.0f, 0.0f, -1.0f);
	vertex.tex_coords = glm::vec2(0.0f, 0.0f);
	this->vertices.push_back(vertex); // indice 0
	vertex.position = glm::vec3(0.5f, -0.5f, -0.5f);
	vertex.normal = glm::vec3( 0.0f, 0.0f, -1.0f);
	vertex.tex_coords = glm::vec2(1.0f, 0.0f);
	this->vertices.push_back(vertex); // indice 1
	vertex.position = glm::vec3(0.5f, 0.5f, -0.5f);
	vertex.normal = glm::vec3( 0.0f, 0.0f, -1.0f);
	vertex.tex_coords = glm::vec2(1.0f, 1.0f);
	this->vertices.push_back(vertex); // indice 2
	vertex.position = glm::vec3(-0.5f, 0.5f, -0.5f);
	vertex.normal = glm::vec3( 0.0f, 0.0f, -1.0f);
	vertex.tex_coords = glm::vec2(0.0f, 1.0f);
	this->vertices.push_back(vertex); // indice 3

	// Back Face
	vertex.position = glm::vec3(0.5f, -0.5f, 0.5f);
	vertex.normal = glm::vec3( 0.0f, 0.0f, 1.0f);
	vertex.tex_coords = glm::vec2(0.0f, 0.0f);
	this->vertices.push_back(vertex); // indice 4
	vertex.position = glm::vec3(-0.5f, -0.5f, 0.5f);
	vertex.normal = glm::vec3( 0.0f, 0.0f, 1.0f);
	vertex.tex_coords = glm::vec2(1.0f, 0.0f);
	this->vertices.push_back(vertex); // indice 5
	vertex.position = glm::vec3(-0.5f, 0.5f, 0.5f);
	vertex.normal = glm::vec3( 0.0f, 0.0f, 1.0f);
	vertex.tex_coords = glm::vec2(1.0f, 1.0f);
	this->vertices.push_back(vertex); // indice 6
	vertex.position = glm::vec3(0.5f, 0.5f, 0.5f);
	vertex.normal = glm::vec3( 0.0f, 0.0f, 1.0f);
	vertex.tex_coords = glm::vec2(0.0f, 1.0f);
	this->vertices.push_back(vertex); // indice 7

	// Left Face
	vertex.position = glm::vec3(-0.5f, -0.5f, 0.5f);
	vertex.normal = glm::vec3( -1.0f, 0.0f, 0.0f);
	vertex.tex_coords = glm::vec2(1.0f, 0.0f);
	this->vertices.push_back(vertex); // indice 8
	vertex.position = glm::vec3(-0.5f, -0.5f, -0.5f);
	vertex.normal = glm::vec3( -1.0f, 0.0f, 0.0f);
	vertex.tex_coords = glm::vec2(0.0f, 0.0f);
	this->vertices.push_back(vertex); // indice 9
	vertex.position = glm::vec3(-0.5f, 0.5f, -0.5f);
	vertex.normal = glm::vec3( -1.0f, 0.0f, 0.0f);
	vertex.tex_coords = glm::vec2(0.0f, 1.0f);
	this->vertices.push_back(vertex); // indice 10
	vertex.position = glm::vec3(-0.5f, 0.5f, 0.5f);
	vertex.normal = glm::vec3( -1.0f, 0.0f, 0.0f);
	vertex.tex_coords = glm::vec2(1.0f, 1.0f);
	this->vertices.push_back(vertex); // indice 11

	// Right Face
	vertex.position = glm::vec3(0.5f, -0.5f, -0.5f);
	vertex.normal = glm::vec3( 1.0f, 0.0f, 0.0f);
	vertex.tex_coords = glm::vec2(1.0f, 0.0f);
	this->vertices.push_back(vertex); // indice 12
	vertex.position = glm::vec3(0.5f, -0.5f, 0.5f);
	vertex.normal = glm::vec3( 1.0f, 0.0f, 0.0f);
	vertex.tex_coords = glm::vec2(0.0f, 0.0f);
	this->vertices.push_back(vertex); // indice 13
	vertex.position = glm::vec3(0.5f, 0.5f, 0.5f);
	vertex.normal = glm::vec3( 1.0f, 0.0f, 0.0f);
	vertex.tex_coords = glm::vec2(0.0f, 1.0f);
	this->vertices.push_back(vertex); // indice 14
	vertex.position = glm::vec3(0.5f, 0.5f, -0.5f);
	vertex.normal = glm::vec3( 1.0f, 0.0f, 0.0f);
	vertex.tex_coords = glm::vec2(1.0f, 1.0f);
	this->vertices.push_back(vertex); // indice 15

	// Bottom Face
	vertex.position = glm::vec3(-0.5f, -0.5f, 0.5f);
	vertex.normal = glm::vec3( 0.0f, -1.0f, 0.0f);
	vertex.tex_coords = glm::vec2(0.0f, 0.0f);
	this->vertices.push_back(vertex); // indice 16
	vertex.position = glm::vec3(0.5f, -0.5f, 0.5f);
	vertex.normal = glm::vec3( 0.0f, -1.0f, 0.0f);
	vertex.tex_coords = glm::vec2(1.0f, 0.0f);
	this->vertices.push_back(vertex); // indice 17
	vertex.position = glm::vec3(0.5f, -0.5f, -0.5f);
	vertex.normal = glm::vec3( 0.0f, -1.0f, 0.0f);
	vertex.tex_coords = glm::vec2(1.0f, 1.0f);
	this->vertices.push_back(vertex); // indice 18
	vertex.position = glm::vec3(-0.5f, -0.5f, -0.5f);
	vertex.normal = glm::vec3( 0.0f, -1.0f, 0.0f);
	vertex.tex_coords = glm::vec2(0.0f, 1.0f);
	this->vertices.push_back(vertex); // indice 19

	// Top Face
	vertex.position = glm::vec3(-0.5f, 0.5f, 0.5f);
	vertex.normal = glm::vec3( 0.0f, 1.0f, 0.0f);
	vertex.tex_coords = glm::vec2(0.0f, 0.0f);
	this->vertices.push_back(vertex); // indice 20
	vertex.position = glm::vec3(0.5f, 0.5f, 0.5f);
	vertex.normal = glm::vec3( 0.0f, 1.0f, 0.0f);
	vertex.tex_coords = glm::vec2(1.0f, 0.0f);
	this->vertices.push_back(vertex); // indice 21
	vertex.position = glm::vec3(0.5f, 0.5f, -0.5f);
	vertex.normal = glm::vec3( 0.0f, 1.0f, 0.0f);
	vertex.tex_coords = glm::vec2(1.0f, 1.0f);
	this->vertices.push_back(vertex); // indice 22
	vertex.position = glm::vec3(-0.5f, 0.5f, -0.5f);
	vertex.normal = glm::vec3( 0.0f, 1.0f, 0.0f);
	vertex.tex_coords = glm::vec2(0.0f, 1.0f);
	this->vertices.push_back(vertex); // indice 23

	unsigned int ind[] = {	0, 1, 2, 0, 2, 3,
							4, 5, 6, 4, 6, 7,
							8, 9, 10, 8, 10, 11,
							12, 13, 14, 12, 14, 15,
							16, 17, 18, 16, 18, 19,
							20, 21, 22, 20, 22, 23	};
	std::vector<unsigned int> vInd(ind, ind+36);
	this->indices = vInd;

	this->material = material;

	SetupMesh();
}

