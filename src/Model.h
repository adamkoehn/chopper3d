#ifndef SRC_MODEL
#define SRC_MODEL

#include <tiny_gltf.h>
#include <GL/glew.h>
#include <string>
#include <vector>
#include <iostream>

#include "Mesh.h"

class Model
{
public:
    Model();
    Model(std::string path);
    void Draw();

private:
    void loadModel(std::string path);
    void processNode(tinygltf::Model &model, tinygltf::Node &node);

private:
    std::vector<Mesh *> _meshes;
    std::string _directory;
    glm::vec3 _max;
    glm::vec3 _min;
};

#endif /* SRC_MODEL */
