#pragma once

#include "mesh.h"

class cube : public mesh
{
public:
    cube(std::vector<Texture> textures);
    cube(Material material);
};
