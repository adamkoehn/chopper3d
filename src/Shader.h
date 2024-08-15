#ifndef SRC_SHADER
#define SRC_SHADER

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
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
    void SetModel(glm::mat4 model);
    void SetView(glm::mat4 view);
    void SetProjection(glm::mat4 projection);
    void SetLightPosition(glm::vec3 light);

private:
    std::string readFile(std::string path);
    GLuint createShader(GLenum type, std::string code);
    GLuint createProgram(GLuint vertShader, GLuint fragShader);

private:
    GLuint _program;
    GLuint _model;
    GLuint _view;
    GLuint _projection;
    GLuint _light;
};

#endif /* SRC_SHADER */
