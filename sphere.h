#pragma once

#include "mesh.h"

const float PI 	= 3.14159265359f;
const float TAU	= 6.28318530717f;

class sphere : public mesh
{
public:
    sphere();
    sphere(unsigned int xSegments, unsigned int ySegments);
    sphere(unsigned int xSegments, unsigned int ySegments, Material material);
    sphere(unsigned int xSegments, unsigned int ySegments, std::vector<Texture> textures);
};
