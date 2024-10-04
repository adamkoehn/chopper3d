#include "Doodle.h"

Doodle::Doodle()
    : _model(nullptr), _dynamic(nullptr)
{
}

void Doodle::SetUp(Model *model, glm::vec3 position, glm::vec3 scale, glm::vec3 rotation)
{
    _model = model;
    _position = position;
    _scale = scale;
    _rotation = rotation;
}

void Doodle::MakeDynamic(Dynamic *dynamic)
{
    _dynamic = dynamic;
}

void Doodle::Update(float deltaTime)
{
    if (!_dynamic)
    {
        return;
    }

    _position = _dynamic->Update(deltaTime, _position);
}

bool Doodle::IsActive()
{
    if (!_dynamic)
    {
        return true;
    }

    return _dynamic->IsActive(_position);
}

glm::vec3 &Doodle::GetPosition()
{
    return _position;
}

glm::vec3 Doodle::GetScale()
{
    return _scale;
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
    _norm = glm::inverseTranspose(_mat);
}

void Doodle::Draw(Shader &shader)
{
    shader.SetModel(_mat);
    shader.SetNormal(_norm);
    _model->Draw();
}
