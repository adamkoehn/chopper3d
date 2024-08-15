#ifndef SRC_MESH
#define SRC_MESH

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <string>
#include <vector>
#include <iostream>

struct Vertex
{
    glm::vec3 Position;
    glm::vec3 Normal;
    glm::vec2 TexCoords;
};

struct Texture
{
    unsigned int Id;
    std::string Type;
};

class Mesh
{
public:
    Mesh(std::vector<Vertex> vertices, std::vector<unsigned int> indices);
    ~Mesh();
    void Draw();

private:
    void setupMesh();

private:
    GLuint _vao;
    GLuint _vbo;
    GLuint _ebo;
    GLsizei _size;
};

#endif /* SRC_MESH */
