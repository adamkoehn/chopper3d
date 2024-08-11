#ifndef SRC_TRIANGLE
#define SRC_TRIANGLE

#include <GL/glew.h>

class Triangle
{
public:
    Triangle();
    ~Triangle();
    void Draw();

private:
    GLuint _vao;
    GLuint _vbo;
};

#endif /* SRC_TRIANGLE */
