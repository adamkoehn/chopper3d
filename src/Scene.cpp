#include "Scene.h"

Scene::Scene(Shader &shader)
    : _shader(shader)
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
