#include "Shader.h"

Shader::Shader(std::string vertPath, std::string fragPath)
{
    _program = createProgram(
        createShader(GL_VERTEX_SHADER, readFile(vertPath)),
        createShader(GL_FRAGMENT_SHADER, readFile(fragPath)));

    _model = glGetUniformLocation(_program, "Model");
    _view = glGetUniformLocation(_program, "View");
    _projection = glGetUniformLocation(_program, "Projection");
}

Shader::~Shader()
{
    glDeleteProgram(_program);
}

void Shader::Use()
{
    glUseProgram(_program);
}

void Shader::SetModel(glm::mat4 model)
{
    glUniformMatrix4fv(_model, 1, GL_FALSE, glm::value_ptr(model));
}

void Shader::SetView(glm::mat4 view)
{
    glUniformMatrix4fv(_view, 1, GL_FALSE, glm::value_ptr(view));
}

void Shader::SetProjection(glm::mat4 projection)
{
    glUniformMatrix4fv(_projection, 1, GL_FALSE, glm::value_ptr(projection));
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
