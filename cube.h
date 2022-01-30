#pragma once

#include "mesh.h"

class cube : public mesh
{
public:
    explicit cube(std::vector<texture> textures);
    explicit cube(material mat);
};
