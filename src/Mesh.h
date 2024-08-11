#ifndef SRC_MESH
#define SRC_MESH

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <string>
#include <vector>

struct Vertex
{
    glm::vec3 Position;
    glm::vec3 Normal;
    glm::vec2 TexCoords;
};

struct Texture
{
    unsigned Id;
    std::string Type;
};

class Mesh
{
public:
    Mesh(std::vector<Vertex> vertices, std::vector<unsigned> indices, std::vector<Texture> textures);
    ~Mesh();
    void Draw();

private:
    void setupMesh();

private:
    unsigned _vao;
    unsigned _vbo;
    unsigned _ebo;
    std::vector<Vertex> _vertices;
    std::vector<unsigned> _indices;
    std::vector<Texture> _textures;
};

#endif /* SRC_MESH */
