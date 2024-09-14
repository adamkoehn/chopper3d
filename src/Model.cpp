#include "Model.h"

Model::Model()
{
}

Model::Model(std::string path)
{
    loadModel(path);
}

void Model::Draw()
{
    for (unsigned int i = 0; i < _meshes.size(); i++)
    {
        _meshes[i]->Draw();
    }
}

void Model::loadModel(std::string path)
{
    tinygltf::TinyGLTF loader;
    tinygltf::Model model;
    std::string error;
    std::string warning;

    bool ok = loader.LoadBinaryFromFile(&model, &error, &warning, path);

    if (!warning.empty())
    {
        std::cerr << "gltf warning: " << warning << std::endl;
    }

    if (!error.empty())
    {
        std::cerr << "gltf error: " << error << std::endl;
    }

    if (!ok)
    {
        std::cerr << "gltf failed to load" << std::endl;
    }

    tinygltf::Scene scene = model.scenes[model.defaultScene];
    for (unsigned long int i = 0; i < scene.nodes.size(); i++)
    {
        processNode(model, model.nodes[scene.nodes[i]]);
    }
}

void Model::processNode(tinygltf::Model &model, tinygltf::Node &node)
{
    if (node.mesh >= 0)
    {
        tinygltf::Mesh mesh = model.meshes[node.mesh];
        for (std::vector<tinygltf::Primitive>::iterator primitive = mesh.primitives.begin(); primitive != mesh.primitives.end(); ++primitive)
        {
            _meshes.push_back(new Mesh(model, *primitive));
        }
    }

    for (unsigned long int i = 0; i < node.children.size(); i++)
    {
        processNode(model, model.nodes[node.children[i]]);
    }
}
