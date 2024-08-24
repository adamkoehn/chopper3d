#include "Mesh.h"

Mesh::Mesh(tinygltf::Model &model, tinygltf::Primitive &primitive)
{
    tinygltf::Accessor indices = model.accessors[primitive.indices];
    tinygltf::Accessor vertices = model.accessors[primitive.attributes["POSITION"]];
    tinygltf::Accessor normals = model.accessors[primitive.attributes["NORMAL"]];
    tinygltf::Accessor uvs = model.accessors[primitive.attributes["TEXCOORD_0"]];

    _eboCount = indices.count;
    _eboType = indices.componentType;
    _eboMode = primitive.mode;
    _eboOffset = indices.byteOffset;

    glGenVertexArrays(1, &_vao);
    glBindVertexArray(_vao);

    GLuint vvbo;
    GLuint nvbo;
    GLuint uvbo;

    tinygltf::BufferView vertexView = model.bufferViews[vertices.bufferView];
    tinygltf::Buffer &vertexBuffer = model.buffers[vertexView.buffer];
    glGenBuffers(1, &vvbo);
    glBindBuffer(vertexView.target, vvbo);
    glBufferData(vertexView.target, vertexView.byteLength, &vertexBuffer.data.at(0) + vertexView.byteOffset, GL_STATIC_DRAW);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, vertices.type, vertices.componentType, vertices.normalized ? GL_TRUE : GL_FALSE, vertices.ByteStride(vertexView), (void *)vertices.byteOffset);

    tinygltf::BufferView normalsView = model.bufferViews[normals.bufferView];
    tinygltf::Buffer &normalsBuffer = model.buffers[normalsView.buffer];
    glGenBuffers(1, &nvbo);
    glBindBuffer(normalsView.target, nvbo);
    glBufferData(normalsView.target, normalsView.byteLength, &normalsBuffer.data.at(0) + normalsView.byteOffset, GL_STATIC_DRAW);
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, normals.type, normals.componentType, normals.normalized ? GL_TRUE : GL_FALSE, normals.ByteStride(normalsView), (void *)normals.byteOffset);

    tinygltf::BufferView uvsView = model.bufferViews[uvs.bufferView];
    tinygltf::Buffer &uvsBuffer = model.buffers[uvsView.buffer];
    glGenBuffers(1, &uvbo);
    glBindBuffer(uvsView.target, uvbo);
    glBufferData(uvsView.target, uvsView.byteLength, &uvsBuffer.data.at(0) + uvsView.byteOffset, GL_STATIC_DRAW);
    glEnableVertexAttribArray(2);
    glVertexAttribPointer(2, uvs.type, uvs.componentType, uvs.normalized ? GL_TRUE : GL_FALSE, uvs.ByteStride(uvsView), (void *)uvs.byteOffset);

    _vbos.push_back(vvbo);
    _vbos.push_back(nvbo);
    _vbos.push_back(uvbo);

    tinygltf::BufferView indicesView = model.bufferViews[indices.bufferView];
    tinygltf::Buffer indicesBuffer = model.buffers[indicesView.buffer];
    glGenBuffers(1, &_ebo);
    glBindBuffer(indicesView.target, _ebo);
    glBufferData(indicesView.target, indicesView.byteLength, &indicesBuffer.data.at(indicesView.byteOffset), GL_STATIC_DRAW);

    glGenTextures(1, &_texture);
    glBindTexture(GL_TEXTURE_2D, _texture);
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    tinygltf::Texture &texture = model.textures[0];
    tinygltf::Image &image = model.images[texture.source];

    GLenum format = GL_RGBA;
    if (image.component == 1)
    {
        format = GL_RED;
    }
    if (image.component == 2)
    {
        format = GL_RG;
    }
    if (image.component == 3)
    {
        format = GL_RGB;
    }

    GLenum type = GL_UNSIGNED_BYTE;
    if (image.bits == 16)
    {
        type = GL_UNSIGNED_SHORT;
    }

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image.width, image.height, 0, format, type, &image.image.at(0));

    glBindVertexArray(0);
}

Mesh::~Mesh()
{
    glDeleteBuffers(1, &_ebo);
    for (std::vector<GLuint>::iterator vbo = _vbos.begin(); vbo != _vbos.end(); ++vbo)
    {
        glDeleteBuffers(1, &(*vbo));
    }
    glDeleteVertexArrays(1, &_vao);
}

void Mesh::Draw()
{
    glBindTexture(GL_TEXTURE_2D, _texture);
    glBindVertexArray(_vao);
    glDrawElements(_eboMode, _eboCount, _eboType, (void *)_eboOffset);
}
