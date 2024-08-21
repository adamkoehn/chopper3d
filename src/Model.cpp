#define STB_IMAGE_IMPLEMENTATION
#include <stb/stb.h>

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

    _directory = path.substr(0, path.rfind("/"));

    processNode(scene->mRootNode, scene);
}

void Model::processNode(aiNode *node, const aiScene *scene)
{
    for (unsigned int i = 0; i < node->mNumMeshes; i++)
    {
        aiMesh *mesh = scene->mMeshes[i];
        _meshes.push_back(processMesh(mesh, scene));
    }

    for (unsigned int i = 0; i < node->mNumChildren; i++)
    {
        processNode(node->mChildren[i], scene);
    }
}

Mesh *Model::processMesh(aiMesh *mesh, const aiScene *scene)
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

        if (i == 0)
        {
            _max = position;
            _min = position;
        }
        else
        {
            if (_max.x < position.x)
                _max.x = position.x;
            if (_min.x > position.x)
                _min.x = position.x;
            if (_max.y < position.y)
                _max.y = position.y;
            if (_min.y > position.y)
                _min.y = position.y;
            if (_max.z < position.z)
                _max.z = position.z;
            if (_min.z > position.z)
                _min.z = position.z;
        }

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

    aiMaterial *material = scene->mMaterials[mesh->mMaterialIndex];
    std::vector<Texture> diffuse = loadMaterialTextures(material, aiTextureType_DIFFUSE, "texture_diffuse");
    textures.insert(textures.end(), diffuse.begin(), diffuse.end());

    Mesh *output = new Mesh(vertices, indices, textures);

    return output;
}

std::vector<Texture> Model::loadMaterialTextures(aiMaterial *material, aiTextureType type, std::string typeName)
{
    std::vector<Texture> textures;

    for (unsigned i = 0; i < material->GetTextureCount(type); i++)
    {
        aiString str;
        material->GetTexture(type, i, &str);

        Texture texture;
        texture.Id = loadTexture(str);
        texture.Type = typeName;

        textures.push_back(texture);
    }

    return textures;
}

GLuint Model::loadTexture(aiString file)
{
    int height, width, channels;

    std::string path(_directory);
    path.append("/");
    path.append(file.C_Str());

    unsigned char *data = stbi_load(path.c_str(), &width, &height, &channels, 0);

    GLuint id;
    glGenTextures(1, &id);
    glBindTexture(GL_TEXTURE_2D, id);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    if (data)
    {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(id);
        stbi_image_free(data);
    }
    else
    {
        std::cerr << "failed to load texture " << path << std::endl;
    }

    return id;
}
