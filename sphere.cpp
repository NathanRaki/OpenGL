#include "sphere.h"

sphere::sphere()
{
    
}

sphere::sphere(unsigned xSegments, unsigned ySegments)
{
    Vertex vertex;

    for (unsigned int y = 0; y <= ySegments; ++y)
    {
        for (unsigned int x = 0; x <= xSegments; ++x)
        {
            float xSegment 	= (float)x / (float)xSegments;
            float ySegment 	= (float)y / (float)ySegments;
            float xPos		= std::cos(xSegment * TAU) * std::sin(ySegment * PI); // TAU is 2PI
            float yPos		= std::cos(ySegment * PI);
            float zPos		= std::sin(xSegment * TAU) * std::sin(ySegment * PI);

            vertex.position 	= glm::vec3(xPos, yPos, zPos);
            vertex.normal		= glm::vec3(xPos, yPos, zPos);
            vertex.tex_coords	= glm::vec2(xSegment, ySegment);
            this->vertices.push_back(vertex);
        }
    }

    bool oddRow = false;
    for (unsigned int y = 0; y < ySegments; ++y)
    {
        for (unsigned int x = 0; x < xSegments; ++x)
        {
            this->indices.push_back((y+1) * (xSegments+1) + x);
            this->indices.push_back(  y   * (xSegments+1) + x);
            this->indices.push_back(  y   * (xSegments+1) + x + 1);

            this->indices.push_back((y+1) * (xSegments+1) + x);
            this->indices.push_back(  y   * (xSegments+1) + x + 1);
            this->indices.push_back((y+1) * (xSegments+1) + x + 1);
        }
    }

    SetupMesh();
}

sphere::sphere(unsigned xSegments, unsigned ySegments, std::vector<Texture> textures)
{
    Vertex vertex;
    
    	for (unsigned int y = 0; y <= ySegments; ++y)
    	{
    		for (unsigned int x = 0; x <= xSegments; ++x)
    		{
    			float xSegment 	= (float)x / (float)xSegments;
    			float ySegment 	= (float)y / (float)ySegments;
    			float xPos		= std::cos(xSegment * TAU) * std::sin(ySegment * PI); // TAU is 2PI
    			float yPos		= std::cos(ySegment * PI);
    			float zPos		= std::sin(xSegment * TAU) * std::sin(ySegment * PI);
    
    			vertex.position 	= glm::vec3(xPos, yPos, zPos);
    			vertex.normal		= glm::vec3(xPos, yPos, zPos);
    			vertex.tex_coords	= glm::vec2(xSegment, ySegment);
    			this->vertices.push_back(vertex);
    		}
    	}
    
    	bool oddRow = false;
    	for (unsigned int y = 0; y < ySegments; ++y)
    	{
    		for (unsigned int x = 0; x < xSegments; ++x)
    		{
    			this->indices.push_back((y+1) * (xSegments+1) + x);
    			this->indices.push_back(  y   * (xSegments+1) + x);
    			this->indices.push_back(  y   * (xSegments+1) + x + 1);
    
    			this->indices.push_back((y+1) * (xSegments+1) + x);
    			this->indices.push_back(  y   * (xSegments+1) + x + 1);
    			this->indices.push_back((y+1) * (xSegments+1) + x + 1);
    		}
    	}
    
    	this->textures = textures;
    
    	SetupMesh();
}

sphere::sphere(unsigned xSegments, unsigned ySegments, Material material)
{
	Vertex vertex;

	for (unsigned int y = 0; y <= ySegments; ++y)
	{
		for (unsigned int x = 0; x <= xSegments; ++x)
		{
			float xSegment 	= (float)x / (float)xSegments;
			float ySegment 	= (float)y / (float)ySegments;
			float xPos		= std::cos(xSegment * TAU) * std::sin(ySegment * PI); // TAU is 2PI
			float yPos		= std::cos(ySegment * PI);
			float zPos		= std::sin(xSegment * TAU) * std::sin(ySegment * PI);

			vertex.position 	= glm::vec3(xPos, yPos, zPos);
			vertex.normal		= glm::vec3(xPos, yPos, zPos);
			vertex.tex_coords	= glm::vec2(xSegment, ySegment);
			this->vertices.push_back(vertex);
		}
	}

	bool oddRow = false;
	for (unsigned int y = 0; y < ySegments; ++y)
	{
		for (unsigned int x = 0; x < xSegments; ++x)
		{
			this->indices.push_back((y+1) * (xSegments+1) + x);
			this->indices.push_back(  y   * (xSegments+1) + x);
			this->indices.push_back(  y   * (xSegments+1) + x + 1);

			this->indices.push_back((y+1) * (xSegments+1) + x);
			this->indices.push_back(  y   * (xSegments+1) + x + 1);
			this->indices.push_back((y+1) * (xSegments+1) + x + 1);
		}
	}

	this->material = material;

	SetupMesh();
}


