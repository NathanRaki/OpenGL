# OpenGL Project - <u>[GitHub Repository](https://github.com/NathanRaki/OpenGL)</u>

## __Scene__

| White                                                      | Red                                                      | Green                                                      |
|----------------------------------------------------------|------------------------------------------------------------|------------------------------------------------------------|
| <p align="center"><img src="data/screenshots/white.png" alt="Scene Preview"></p> | <p align="center"><img src="data/screenshots/red.png" alt="Scene Preview"></p> | <p align="center"><img src="data/screenshots/green.png" alt="Scene Preview"></p> |

Both red and grey spheres have a material and are drawn with the *material shader*. <br>
The cube has a texture stored in data/textures and is drawn with the *texture shader*. <br>
The top sphere is the light source. It has a texture and is drown with the *light source shader*.

You can change the light color by pressing N. It cycles between white, red and green light.<br>

## __C++ classes__

- ### Game

   - Handles OpenGL initialization
   - Stores camera, shaders, file paths
   - Implements OpenGL callback functions
   - Implements scene core methods
 
- ### Shader

    - Convert shader code from file to OpenGL Shaders
    - Stores shader id for mesh drawing
    - Implements methods to modify shader variables

- ### Camera

    - Stores camera data (position, rotation, ...)
    - Implements keyboard inputs methods
    - Can return view matrix
    - Handles ImGui HUD content

- ### Mesh

   - Implements Vertex, Texture and Material structures
   - Stores vertices, indices and texture / material data
   - Calls OpenGL drawing methods with mesh data
   - Draws mesh based on textures or materials, sets its position, rotation and scale
   - Adds methods to read texture from image and to load cubemap texture

- ### Cube & Sphere

    - Derived from Mesh, constructors fill vertices and indices with cube and sphere data