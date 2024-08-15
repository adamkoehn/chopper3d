#ifndef SRC_MODEL
#define SRC_MODEL

#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
#include <stb/stb_image.h>
#include <GL/glew.h>
#include <string>
#include <vector>
#include <iostream>

#include "Mesh.h"

class Model
{
public:
    Model(std::string path);
    void Draw();

private:
    void loadModel(std::string path);
    void processNode(aiNode *node, const aiScene *scene);
    Mesh *processMesh(aiMesh *mesh, const aiScene *scene);
    std::vector<Texture> loadMaterialTextures(aiMaterial *material, aiTextureType type, std::string typeName);
    GLuint loadTexture(aiString file);

private:
    std::vector<Mesh *> _meshes;
    std::string _directory;
};

#endif /* SRC_MODEL */
