#ifndef SRC_SHADER
#define SRC_SHADER

#include <GL/glew.h>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

class Shader
{
public:
    Shader(std::string vertPath, std::string fragPath);
    ~Shader();
    void Use();

private:
    std::string readFile(std::string path);
    GLuint createShader(GLenum type, std::string code);
    GLuint createProgram(GLuint vertShader, GLuint fragShader);

private:
    GLuint _program;
};

#endif /* SRC_SHADER */
