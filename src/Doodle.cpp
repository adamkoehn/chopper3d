#include "Doodle.h"

Doodle::Doodle(Model &model, glm::vec3 position)
    : _model(model), _position(glm::vec3(0.0f)), _scale(glm::vec3(1.0f)), _rotation(glm::vec3(0.0f))
{
    SetPosition(position);
}

void Doodle::SetPosition(glm::vec3 position)
{
    _position = position;
}

void Doodle::SetScale(glm::vec3 scale)
{
    _scale = scale;
}

void Doodle::SetRotation(glm::vec3 rotation)
{
    _rotation = rotation;
}

void Doodle::Calculate()
{
    _mat = glm::mat4(1.0f);
    _mat = glm::translate(_mat, _position);
    _mat = glm::rotate(_mat, glm::radians(_rotation.x), glm::vec3(1.0f, 0.0f, 0.0f));
    _mat = glm::rotate(_mat, glm::radians(_rotation.y), glm::vec3(0.0f, 1.0f, 0.0f));
    _mat = glm::rotate(_mat, glm::radians(_rotation.z), glm::vec3(0.0f, 0.0f, 1.0f));
    _mat = glm::scale(_mat, _scale);
}

void Doodle::Draw(Shader &shader)
{
    shader.SetModel(_mat);
    _model.Draw();
}
