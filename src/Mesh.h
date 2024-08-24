#ifndef SRC_MESH
#define SRC_MESH

#include <tiny_gltf.h>
#include <GL/glew.h>
#include <glm/glm.hpp>
#include <string>
#include <vector>
#include <iostream>

class Mesh
{
public:
    Mesh(tinygltf::Model &model, tinygltf::Primitive &primitive);
    ~Mesh();
    void Draw();

private:
    void setupMesh();

private:
    GLuint _vao;
    std::vector<GLuint> _vbos;
    GLuint _ebo;
    GLsizei _eboCount;
    GLenum _eboType;
    GLenum _eboMode;
    size_t _eboOffset;
    GLuint _texture;
};

#endif /* SRC_MESH */
