#include "cube.h"

cube::cube(std::vector<texture> textures)
{
    vertex vertex;

	// Front Face
	vertex.position = glm::vec3(-0.5f, -0.5f, -0.5f);
	vertex.normal = glm::vec3( 0.0f, 0.0f, -1.0f);
	vertex.tex_coords = glm::vec2(0.0f, 0.0f);
	this->vertices.push_back(vertex); // index 0
	vertex.position = glm::vec3(0.5f, -0.5f, -0.5f);
	vertex.normal = glm::vec3( 0.0f, 0.0f, -1.0f);
	vertex.tex_coords = glm::vec2(1.0f, 0.0f);
	this->vertices.push_back(vertex); // index 1
	vertex.position = glm::vec3(0.5f, 0.5f, -0.5f);
	vertex.normal = glm::vec3( 0.0f, 0.0f, -1.0f);
	vertex.tex_coords = glm::vec2(1.0f, 1.0f);
	this->vertices.push_back(vertex); // index 2
	vertex.position = glm::vec3(-0.5f, 0.5f, -0.5f);
	vertex.normal = glm::vec3( 0.0f, 0.0f, -1.0f);
	vertex.tex_coords = glm::vec2(0.0f, 1.0f);
	this->vertices.push_back(vertex); // index 3

	// Back Face
	vertex.position = glm::vec3(0.5f, -0.5f, 0.5f);
	vertex.normal = glm::vec3( 0.0f, 0.0f, 1.0f);
	vertex.tex_coords = glm::vec2(0.0f, 0.0f);
	this->vertices.push_back(vertex); // index 4
	vertex.position = glm::vec3(-0.5f, -0.5f, 0.5f);
	vertex.normal = glm::vec3( 0.0f, 0.0f, 1.0f);
	vertex.tex_coords = glm::vec2(1.0f, 0.0f);
	this->vertices.push_back(vertex); // index 5
	vertex.position = glm::vec3(-0.5f, 0.5f, 0.5f);
	vertex.normal = glm::vec3( 0.0f, 0.0f, 1.0f);
	vertex.tex_coords = glm::vec2(1.0f, 1.0f);
	this->vertices.push_back(vertex); // index 6
	vertex.position = glm::vec3(0.5f, 0.5f, 0.5f);
	vertex.normal = glm::vec3( 0.0f, 0.0f, 1.0f);
	vertex.tex_coords = glm::vec2(0.0f, 1.0f);
	this->vertices.push_back(vertex); // index 7

	// Left Face
	vertex.position = glm::vec3(-0.5f, -0.5f, 0.5f);
	vertex.normal = glm::vec3( -1.0f, 0.0f, 0.0f);
	vertex.tex_coords = glm::vec2(1.0f, 0.0f);
	this->vertices.push_back(vertex); // index 8
	vertex.position = glm::vec3(-0.5f, -0.5f, -0.5f);
	vertex.normal = glm::vec3( -1.0f, 0.0f, 0.0f);
	vertex.tex_coords = glm::vec2(0.0f, 0.0f);
	this->vertices.push_back(vertex); // index 9
	vertex.position = glm::vec3(-0.5f, 0.5f, -0.5f);
	vertex.normal = glm::vec3( -1.0f, 0.0f, 0.0f);
	vertex.tex_coords = glm::vec2(0.0f, 1.0f);
	this->vertices.push_back(vertex); // index 10
	vertex.position = glm::vec3(-0.5f, 0.5f, 0.5f);
	vertex.normal = glm::vec3( -1.0f, 0.0f, 0.0f);
	vertex.tex_coords = glm::vec2(1.0f, 1.0f);
	this->vertices.push_back(vertex); // index 11

	// Right Face
	vertex.position = glm::vec3(0.5f, -0.5f, -0.5f);
	vertex.normal = glm::vec3( 1.0f, 0.0f, 0.0f);
	vertex.tex_coords = glm::vec2(1.0f, 0.0f);
	this->vertices.push_back(vertex); // index 12
	vertex.position = glm::vec3(0.5f, -0.5f, 0.5f);
	vertex.normal = glm::vec3( 1.0f, 0.0f, 0.0f);
	vertex.tex_coords = glm::vec2(0.0f, 0.0f);
	this->vertices.push_back(vertex); // index 13
	vertex.position = glm::vec3(0.5f, 0.5f, 0.5f);
	vertex.normal = glm::vec3( 1.0f, 0.0f, 0.0f);
	vertex.tex_coords = glm::vec2(0.0f, 1.0f);
	this->vertices.push_back(vertex); // index 14
	vertex.position = glm::vec3(0.5f, 0.5f, -0.5f);
	vertex.normal = glm::vec3( 1.0f, 0.0f, 0.0f);
	vertex.tex_coords = glm::vec2(1.0f, 1.0f);
	this->vertices.push_back(vertex); // index 15

	// Bottom Face
	vertex.position = glm::vec3(-0.5f, -0.5f, 0.5f);
	vertex.normal = glm::vec3( 0.0f, -1.0f, 0.0f);
	vertex.tex_coords = glm::vec2(0.0f, 0.0f);
	this->vertices.push_back(vertex); // index 16
	vertex.position = glm::vec3(0.5f, -0.5f, 0.5f);
	vertex.normal = glm::vec3( 0.0f, -1.0f, 0.0f);
	vertex.tex_coords = glm::vec2(1.0f, 0.0f);
	this->vertices.push_back(vertex); // index 17
	vertex.position = glm::vec3(0.5f, -0.5f, -0.5f);
	vertex.normal = glm::vec3( 0.0f, -1.0f, 0.0f);
	vertex.tex_coords = glm::vec2(1.0f, 1.0f);
	this->vertices.push_back(vertex); // index 18
	vertex.position = glm::vec3(-0.5f, -0.5f, -0.5f);
	vertex.normal = glm::vec3( 0.0f, -1.0f, 0.0f);
	vertex.tex_coords = glm::vec2(0.0f, 1.0f);
	this->vertices.push_back(vertex); // index 19

	// Top Face
	vertex.position = glm::vec3(-0.5f, 0.5f, 0.5f);
	vertex.normal = glm::vec3( 0.0f, 1.0f, 0.0f);
	vertex.tex_coords = glm::vec2(0.0f, 0.0f);
	this->vertices.push_back(vertex); // index 20
	vertex.position = glm::vec3(0.5f, 0.5f, 0.5f);
	vertex.normal = glm::vec3( 0.0f, 1.0f, 0.0f);
	vertex.tex_coords = glm::vec2(1.0f, 0.0f);
	this->vertices.push_back(vertex); // index 21
	vertex.position = glm::vec3(0.5f, 0.5f, -0.5f);
	vertex.normal = glm::vec3( 0.0f, 1.0f, 0.0f);
	vertex.tex_coords = glm::vec2(1.0f, 1.0f);
	this->vertices.push_back(vertex); // index 22
	vertex.position = glm::vec3(-0.5f, 0.5f, -0.5f);
	vertex.normal = glm::vec3( 0.0f, 1.0f, 0.0f);
	vertex.tex_coords = glm::vec2(0.0f, 1.0f);
	this->vertices.push_back(vertex); // index 23

	unsigned int ind[] = {	0, 1, 2, 0, 2, 3,
							4, 5, 6, 4, 6, 7,
							8, 9, 10, 8, 10, 11,
							12, 13, 14, 12, 14, 15,
							16, 17, 18, 16, 18, 19,
							20, 21, 22, 20, 22, 23	};
	std::vector<unsigned int> vInd(ind, ind+36);
	this->indices = vInd;

	this->textures = textures;

	setup_mesh();
}

cube::cube(material mat)
{
	vertex vertex;

	// Front Face
	vertex.position = glm::vec3(-0.5f, -0.5f, -0.5f);
	vertex.normal = glm::vec3( 0.0f, 0.0f, -1.0f);
	vertex.tex_coords = glm::vec2(0.0f, 0.0f);
	this->vertices.push_back(vertex); // index 0
	vertex.position = glm::vec3(0.5f, -0.5f, -0.5f);
	vertex.normal = glm::vec3( 0.0f, 0.0f, -1.0f);
	vertex.tex_coords = glm::vec2(1.0f, 0.0f);
	this->vertices.push_back(vertex); // index 1
	vertex.position = glm::vec3(0.5f, 0.5f, -0.5f);
	vertex.normal = glm::vec3( 0.0f, 0.0f, -1.0f);
	vertex.tex_coords = glm::vec2(1.0f, 1.0f);
	this->vertices.push_back(vertex); // index 2
	vertex.position = glm::vec3(-0.5f, 0.5f, -0.5f);
	vertex.normal = glm::vec3( 0.0f, 0.0f, -1.0f);
	vertex.tex_coords = glm::vec2(0.0f, 1.0f);
	this->vertices.push_back(vertex); // index 3

	// Back Face
	vertex.position = glm::vec3(0.5f, -0.5f, 0.5f);
	vertex.normal = glm::vec3( 0.0f, 0.0f, 1.0f);
	vertex.tex_coords = glm::vec2(0.0f, 0.0f);
	this->vertices.push_back(vertex); // index 4
	vertex.position = glm::vec3(-0.5f, -0.5f, 0.5f);
	vertex.normal = glm::vec3( 0.0f, 0.0f, 1.0f);
	vertex.tex_coords = glm::vec2(1.0f, 0.0f);
	this->vertices.push_back(vertex); // index 5
	vertex.position = glm::vec3(-0.5f, 0.5f, 0.5f);
	vertex.normal = glm::vec3( 0.0f, 0.0f, 1.0f);
	vertex.tex_coords = glm::vec2(1.0f, 1.0f);
	this->vertices.push_back(vertex); // index 6
	vertex.position = glm::vec3(0.5f, 0.5f, 0.5f);
	vertex.normal = glm::vec3( 0.0f, 0.0f, 1.0f);
	vertex.tex_coords = glm::vec2(0.0f, 1.0f);
	this->vertices.push_back(vertex); // index 7

	// Left Face
	vertex.position = glm::vec3(-0.5f, -0.5f, 0.5f);
	vertex.normal = glm::vec3( -1.0f, 0.0f, 0.0f);
	vertex.tex_coords = glm::vec2(1.0f, 0.0f);
	this->vertices.push_back(vertex); // index 8
	vertex.position = glm::vec3(-0.5f, -0.5f, -0.5f);
	vertex.normal = glm::vec3( -1.0f, 0.0f, 0.0f);
	vertex.tex_coords = glm::vec2(0.0f, 0.0f);
	this->vertices.push_back(vertex); // index 9
	vertex.position = glm::vec3(-0.5f, 0.5f, -0.5f);
	vertex.normal = glm::vec3( -1.0f, 0.0f, 0.0f);
	vertex.tex_coords = glm::vec2(0.0f, 1.0f);
	this->vertices.push_back(vertex); // index 10
	vertex.position = glm::vec3(-0.5f, 0.5f, 0.5f);
	vertex.normal = glm::vec3( -1.0f, 0.0f, 0.0f);
	vertex.tex_coords = glm::vec2(1.0f, 1.0f);
	this->vertices.push_back(vertex); // index 11

	// Right Face
	vertex.position = glm::vec3(0.5f, -0.5f, -0.5f);
	vertex.normal = glm::vec3( 1.0f, 0.0f, 0.0f);
	vertex.tex_coords = glm::vec2(1.0f, 0.0f);
	this->vertices.push_back(vertex); // index 12
	vertex.position = glm::vec3(0.5f, -0.5f, 0.5f);
	vertex.normal = glm::vec3( 1.0f, 0.0f, 0.0f);
	vertex.tex_coords = glm::vec2(0.0f, 0.0f);
	this->vertices.push_back(vertex); // index 13
	vertex.position = glm::vec3(0.5f, 0.5f, 0.5f);
	vertex.normal = glm::vec3( 1.0f, 0.0f, 0.0f);
	vertex.tex_coords = glm::vec2(0.0f, 1.0f);
	this->vertices.push_back(vertex); // index 14
	vertex.position = glm::vec3(0.5f, 0.5f, -0.5f);
	vertex.normal = glm::vec3( 1.0f, 0.0f, 0.0f);
	vertex.tex_coords = glm::vec2(1.0f, 1.0f);
	this->vertices.push_back(vertex); // index 15

	// Bottom Face
	vertex.position = glm::vec3(-0.5f, -0.5f, 0.5f);
	vertex.normal = glm::vec3( 0.0f, -1.0f, 0.0f);
	vertex.tex_coords = glm::vec2(0.0f, 0.0f);
	this->vertices.push_back(vertex); // index 16
	vertex.position = glm::vec3(0.5f, -0.5f, 0.5f);
	vertex.normal = glm::vec3( 0.0f, -1.0f, 0.0f);
	vertex.tex_coords = glm::vec2(1.0f, 0.0f);
	this->vertices.push_back(vertex); // index 17
	vertex.position = glm::vec3(0.5f, -0.5f, -0.5f);
	vertex.normal = glm::vec3( 0.0f, -1.0f, 0.0f);
	vertex.tex_coords = glm::vec2(1.0f, 1.0f);
	this->vertices.push_back(vertex); // index 18
	vertex.position = glm::vec3(-0.5f, -0.5f, -0.5f);
	vertex.normal = glm::vec3( 0.0f, -1.0f, 0.0f);
	vertex.tex_coords = glm::vec2(0.0f, 1.0f);
	this->vertices.push_back(vertex); // index 19

	// Top Face
	vertex.position = glm::vec3(-0.5f, 0.5f, 0.5f);
	vertex.normal = glm::vec3( 0.0f, 1.0f, 0.0f);
	vertex.tex_coords = glm::vec2(0.0f, 0.0f);
	this->vertices.push_back(vertex); // index 20
	vertex.position = glm::vec3(0.5f, 0.5f, 0.5f);
	vertex.normal = glm::vec3( 0.0f, 1.0f, 0.0f);
	vertex.tex_coords = glm::vec2(1.0f, 0.0f);
	this->vertices.push_back(vertex); // index 21
	vertex.position = glm::vec3(0.5f, 0.5f, -0.5f);
	vertex.normal = glm::vec3( 0.0f, 1.0f, 0.0f);
	vertex.tex_coords = glm::vec2(1.0f, 1.0f);
	this->vertices.push_back(vertex); // index 22
	vertex.position = glm::vec3(-0.5f, 0.5f, -0.5f);
	vertex.normal = glm::vec3( 0.0f, 1.0f, 0.0f);
	vertex.tex_coords = glm::vec2(0.0f, 1.0f);
	this->vertices.push_back(vertex); // index 23

	unsigned int ind[] = {	0, 1, 2, 0, 2, 3,
							4, 5, 6, 4, 6, 7,
							8, 9, 10, 8, 10, 11,
							12, 13, 14, 12, 14, 15,
							16, 17, 18, 16, 18, 19,
							20, 21, 22, 20, 22, 23	};
	std::vector<unsigned int> v_ind(ind, ind+36);
	this->indices = v_ind;

	this->mat = mat;

	setup_mesh();
}

