#include "Shader.h"

Shader::Shader(std::string vertPath, std::string fragPath)
{
    _program = createProgram(
        createShader(GL_VERTEX_SHADER, readFile(vertPath)),
        createShader(GL_FRAGMENT_SHADER, readFile(fragPath)));
}

Shader::~Shader()
{
    glDeleteProgram(_program);
}

void Shader::Use()
{
    glUseProgram(_program);
}

std::string Shader::readFile(std::string path)
{
    std::stringstream buf;
    std::ifstream file(path);

    if (file.is_open())
    {
        buf << file.rdbuf();
        file.close();
    }
    else
    {
        std::cerr << "Cannot open file: " << path << std::endl;
    }

    return buf.str();
}

GLuint Shader::createProgram(GLuint vertShader, GLuint fragShader)
{
    GLint success;
    GLchar message[512];
    GLuint program = glCreateProgram();

    glAttachShader(program, vertShader);
    glAttachShader(program, fragShader);
    glLinkProgram(program);
    glGetProgramiv(program, GL_LINK_STATUS, &success);
    if (!success)
    {
        glGetProgramInfoLog(program, 512, 0, message);
        std::cerr << "Program link error: " << message << std::endl;
    }

    glDeleteShader(vertShader);
    glDeleteShader(fragShader);

    return program;
}

GLuint Shader::createShader(GLenum type, std::string code)
{
    GLint success;
    GLchar message[512];
    const GLchar *source = code.c_str();
    GLuint shader = glCreateShader(type);

    glShaderSource(shader, 1, &source, 0);
    glCompileShader(shader);
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(shader, 512, 0, message);
        std::cerr << "Shader compile error: " << message << std::endl;
    }

    return shader;
}
