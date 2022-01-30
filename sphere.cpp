#include "sphere.h"

sphere::sphere()
{
    
}

sphere::sphere(unsigned x_segments, unsigned y_segments)
{
	for (unsigned int y = 0; y <= y_segments; ++y)
    {
        for (unsigned int x = 0; x <= x_segments; ++x)
        {
	        vertex vertex;
	        float x_segment 	= static_cast<float>(x) / static_cast<float>(x_segments);
            float y_segment 	= static_cast<float>(y) / static_cast<float>(y_segments);
            float x_pos		= std::cos(x_segment * tau) * std::sin(y_segment * pi); // TAU is 2PI
            float y_pos		= std::cos(y_segment * pi);
            float z_pos		= std::sin(x_segment * tau) * std::sin(y_segment * pi);

            vertex.position 	= glm::vec3(x_pos, y_pos, z_pos);
            vertex.normal		= glm::vec3(x_pos, y_pos, z_pos);
            vertex.tex_coords	= glm::vec2(x_segment, y_segment);
            this->vertices.push_back(vertex);
        }
    }
	
    for (unsigned int y = 0; y < y_segments; ++y)
    {
        for (unsigned int x = 0; x < x_segments; ++x)
        {
            this->indices.push_back((y+1) * (x_segments+1) + x);
            this->indices.push_back(  y   * (x_segments+1) + x);
            this->indices.push_back(  y   * (x_segments+1) + x + 1);

            this->indices.push_back((y+1) * (x_segments+1) + x);
            this->indices.push_back(  y   * (x_segments+1) + x + 1);
            this->indices.push_back((y+1) * (x_segments+1) + x + 1);
        }
    }

    setup_mesh();
}

sphere::sphere(unsigned x_segments, unsigned y_segments, std::vector<texture> textures)
{
	for (unsigned int y = 0; y <= y_segments; ++y)
    	{
    		for (unsigned int x = 0; x <= x_segments; ++x)
    		{
	            vertex vertex;
	            float x_segment 	= static_cast<float>(x) / static_cast<float>(x_segments);
    			float y_segment 	= static_cast<float>(y) / static_cast<float>(y_segments);
    			float x_pos		= std::cos(x_segment * tau) * std::sin(y_segment * pi); // TAU is 2PI
    			float y_pos		= std::cos(y_segment * pi);
    			float z_pos		= std::sin(x_segment * tau) * std::sin(y_segment * pi);
    
    			vertex.position 	= glm::vec3(x_pos, y_pos, z_pos);
    			vertex.normal		= glm::vec3(x_pos, y_pos, z_pos);
    			vertex.tex_coords	= glm::vec2(x_segment, y_segment);
    			this->vertices.push_back(vertex);
    		}
    	}
	
    	for (unsigned int y = 0; y < y_segments; ++y)
    	{
    		for (unsigned int x = 0; x < x_segments; ++x)
    		{
    			this->indices.push_back((y+1) * (x_segments+1) + x);
    			this->indices.push_back(  y   * (x_segments+1) + x);
    			this->indices.push_back(  y   * (x_segments+1) + x + 1);
    
    			this->indices.push_back((y+1) * (x_segments+1) + x);
    			this->indices.push_back(  y   * (x_segments+1) + x + 1);
    			this->indices.push_back((y+1) * (x_segments+1) + x + 1);
    		}
    	}
    
    	this->textures = textures;
    
    	setup_mesh();
}

sphere::sphere(unsigned x_segments, unsigned y_segments, material mat)
{
	for (unsigned int y = 0; y <= y_segments; ++y)
	{
		for (unsigned int x = 0; x <= x_segments; ++x)
		{
			vertex vertex;
			float x_segment 	= static_cast<float>(x) / static_cast<float>(x_segments);
			float y_segment 	= static_cast<float>(y) / static_cast<float>(y_segments);
			float x_pos		= std::cos(x_segment * tau) * std::sin(y_segment * pi); // TAU is 2PI
			float y_pos		= std::cos(y_segment * pi);
			float z_pos		= std::sin(x_segment * tau) * std::sin(y_segment * pi);

			vertex.position 	= glm::vec3(x_pos, y_pos, z_pos);
			vertex.normal		= glm::vec3(x_pos, y_pos, z_pos);
			vertex.tex_coords	= glm::vec2(x_segment, y_segment);
			this->vertices.push_back(vertex);
		}
	}

	for (unsigned int y = 0; y < y_segments; ++y)
	{
		for (unsigned int x = 0; x < x_segments; ++x)
		{
			this->indices.push_back((y+1) * (x_segments+1) + x);
			this->indices.push_back(  y   * (x_segments+1) + x);
			this->indices.push_back(  y   * (x_segments+1) + x + 1);

			this->indices.push_back((y+1) * (x_segments+1) + x);
			this->indices.push_back(  y   * (x_segments+1) + x + 1);
			this->indices.push_back((y+1) * (x_segments+1) + x + 1);
		}
	}

	this->mat = mat;

	setup_mesh();
}


