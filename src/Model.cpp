#include "Model.h"

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
    Assimp::Importer import;
    const aiScene *scene = import.ReadFile(path, aiProcess_Triangulate | aiProcess_FlipUVs);

    if (!scene || scene->mFlags & AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode)
    {
        std::cerr << "Assimp import failed: " << import.GetErrorString() << std::endl;
        return;
    }

    _directory = path.substr(0, path.find_last_not_of('/'));

    processNode(scene->mRootNode, scene);
}

void Model::processNode(aiNode *node, const aiScene *scene)
{
    for (unsigned int i = 0; i < node->mNumMeshes; i++)
    {
        aiMesh *mesh = scene->mMeshes[i];
        _meshes.push_back(processMesh(mesh));
    }

    for (unsigned int i = 0; i < node->mNumChildren; i++)
    {
        processNode(node->mChildren[i], scene);
    }
}

Mesh *Model::processMesh(aiMesh *mesh)
{
    std::vector<Vertex> vertices;
    std::vector<unsigned int> indices;
    std::vector<Texture> textures;

    for (unsigned int i = 0; i < mesh->mNumVertices; i++)
    {
        Vertex vertex;

        glm::vec3 position;
        position.x = mesh->mVertices[i].x;
        position.y = mesh->mVertices[i].y;
        position.z = mesh->mVertices[i].z;
        vertex.Position = position;

        glm::vec3 normal;
        normal.x = mesh->mNormals[i].x;
        normal.y = mesh->mNormals[i].y;
        normal.z = mesh->mNormals[i].z;
        vertex.Normal = normal;

        if (mesh->mTextureCoords[0])
        {
            glm::vec2 coord;
            coord.x = mesh->mTextureCoords[0][i].x;
            coord.y = mesh->mTextureCoords[0][i].y;
            vertex.TexCoords = coord;
        }
        else
        {
            vertex.TexCoords = glm::vec2(0.0f);
        }

        vertices.push_back(vertex);
    }

    for (unsigned i = 0; i < mesh->mNumFaces; i++)
    {
        aiFace face = mesh->mFaces[i];
        for (unsigned int j = 0; j < face.mNumIndices; j++)
        {
            indices.push_back(face.mIndices[j]);
        }
    }

    // if (mesh->mMaterialIndex >= 0)
    // {
    //     aiMaterial *material = scene->mMaterials[mesh->mMaterialIndex];
    //     std::vector<Texture> diffuse = loadMaterialTextures(material, aiTextureType_DIFFUSE, "texture_diffuse");
    //     textures.insert(textures.end(), diffuse.begin(), diffuse.end());
    // }

    return new Mesh(vertices, indices);
}

// std::vector<Texture> Model::loadMaterialTextures(aiMaterial *material, aiTextureType type, std::string typeName)
// {
//     std::vector<Texture> textures;

//     for (unsigned i = 0; i < material->GetTextureCount(type); i++)
//     {
//         aiString str;
//         Texture texture;
//         material->GetTexture(type, i, &str);
//         // TODO: finish this later
//     }

//     return textures;
// }
