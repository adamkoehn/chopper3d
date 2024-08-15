#include "Scene.h"

Scene::Scene(Shader &shader)
    : _shader(shader), _selected(0)
{
}

void Scene::AddDoodle(Doodle *doodle)
{
    _doodles.push_back(doodle);
}

void Scene::Update()
{
    for (std::vector<Doodle *>::iterator it = _doodles.begin(); it != _doodles.end(); ++it)
    {
        (*it)->Calculate();
    }
}

void Scene::Draw()
{
    for (std::vector<Doodle *>::iterator it = _doodles.begin(); it != _doodles.end(); ++it)
    {
        (*it)->Draw(_shader);
    }
}

void Scene::Up()
{
    MoveDoodle(glm::vec3(0.0f, 0.5f, 0.0f));
}

void Scene::Down()
{
    MoveDoodle(glm::vec3(0.0f, -0.5f, 0.0f));
}

void Scene::Left()
{
    MoveDoodle(glm::vec3(-0.5f, 0.0f, 0.0f));
}

void Scene::Right()
{
    MoveDoodle(glm::vec3(0.5f, 0.0f, 0.0f));
}

void Scene::Forward()
{
    MoveDoodle(glm::vec3(0.0f, 0.0f, 0.5f));
}

void Scene::Back()
{
    MoveDoodle(glm::vec3(0.0f, 0.0f, -0.5f));
}

void Scene::Select()
{
    _selected = (_selected + 1) % _doodles.size();
    std::cout << "doodle " << _selected << std::endl;
}

void Scene::ScaleUp()
{
    ScaleDoodle(glm::vec3(0.1f));
}

void Scene::ScaleDown()
{
    ScaleDoodle(glm::vec3(-0.1f));
}

void Scene::MoveDoodle(glm::vec3 move)
{
    Doodle *doodle = _doodles[_selected];
    glm::vec3 current = doodle->GetPosition();
    glm::vec3 updated = glm::vec3(current.x + move.x, current.y + move.y, current.z + move.z);
    doodle->SetPosition(updated);
    doodle->Calculate();

    std::cout << updated.x << " " << updated.y << " " << updated.z << std::endl;
}

void Scene::ScaleDoodle(glm::vec3 scale)
{
    Doodle *doodle = _doodles[_selected];
    glm::vec3 current = doodle->GetScale();
    glm::vec3 updated = glm::vec3(current.x + scale.x, current.y + scale.y, current.z + scale.z);
    doodle->SetScale(updated);
    doodle->Calculate();

    std::cout << updated.x << " " << updated.y << " " << updated.z << std::endl;
}
