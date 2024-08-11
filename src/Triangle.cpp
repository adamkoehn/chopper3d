#include "Triangle.h"

Triangle::Triangle()
{
    float vertices[] = {
        -0.5f, -0.5f, 0.0f, // botton left
        0.5f, -0.5f, 0.0f,  // bottom right
        0.0f, 0.5f, 0.0f,   // top
    };

    glGenVertexArrays(1, &_vao);
    glBindVertexArray(_vao);
    glGenBuffers(1, &_vbo);
    glBindBuffer(GL_ARRAY_BUFFER, _vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(float) * 9, vertices, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 3, (void *)0);
    glEnableVertexAttribArray(0);
}

Triangle::~Triangle()
{
    glDeleteBuffers(1, &_vbo);
    glDeleteVertexArrays(1, &_vao);
}

void Triangle::Draw()
{
    glBindVertexArray(_vao);
    glDrawArrays(GL_TRIANGLES, 0, 3);
}
