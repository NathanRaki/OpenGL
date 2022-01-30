#pragma once

#include "mesh.h"

constexpr float pi 	= 3.14159265359f;
constexpr float tau	= 6.28318530717f;

class sphere : public mesh
{
public:
    sphere();
    sphere(unsigned int x_segments, unsigned int y_segments);
    sphere(unsigned int x_segments, unsigned int y_segments, material mat);
    sphere(unsigned int x_segments, unsigned int y_segments, std::vector<texture> textures);
};
