#include "Scene.h"

Scene::Scene()
    : _selected(0)
{
    _doodles.reserve(100);
    _models.reserve(20);
    _players.reserve(4);
    _input.AddController(&_keyboard);
}

void Scene::Calculate()
{
    for (std::vector<Doodle>::iterator it = _doodles.begin(); it != _doodles.end(); ++it)
    {
        it->Calculate();
    }
}

void Scene::Draw(Shader &shader)
{
    for (std::vector<Doodle>::iterator it = _doodles.begin(); it != _doodles.end(); ++it)
    {
        it->Draw(shader);
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
    Doodle &doodle = _doodles[_selected];
    glm::vec3 current = doodle.GetPosition();
    glm::vec3 updated = glm::vec3(current.x + move.x, current.y + move.y, current.z + move.z);
    doodle.SetPosition(updated);
    doodle.Calculate();

    std::cout << updated.x << " " << updated.y << " " << updated.z << std::endl;
}

void Scene::ScaleDoodle(glm::vec3 scale)
{
    Doodle &doodle = _doodles[_selected];
    glm::vec3 current = doodle.GetScale();
    glm::vec3 updated = glm::vec3(current.x + scale.x, current.y + scale.y, current.z + scale.z);
    doodle.SetScale(updated);
    doodle.Calculate();

    std::cout << updated.x << " " << updated.y << " " << updated.z << std::endl;
}

void Scene::Load()
{
    _models.push_back(Model("models/cloud/cloud.glb"));       // 0
    _models.push_back(Model("models/sun/sun.glb"));           // 1
    _models.push_back(Model("models/mountain/mountain.glb")); // 2
    _models.push_back(Model("models/chopper/chopper.glb"));   // 3
    _models.push_back(Model("models/tank/tank.glb"));         // 4
    _models.push_back(Model("models/ground/ground.glb"));     // 5

    _doodles.push_back(Doodle(_models[3], glm::vec3(-7.0f, 4.5f, 0.0f), glm::vec3(0.4f)));                                   // chopper 0
    _doodles.push_back(Doodle(_models[4], glm::vec3(9.0f, -7.0f, 0.0f), glm::vec3(0.2f)));                                   // tank 1
    _doodles.push_back(Doodle(_models[0], glm::vec3(6.0f, 16.5f, -59.5f), glm::vec3(1.0f), glm::vec3(0.0f, 45.0f, 0.0f)));   // cloud 2
    _doodles.push_back(Doodle(_models[0], glm::vec3(-23.5f, 22.0f, -52.5f), glm::vec3(1.2f)));                               // cloud 3
    _doodles.push_back(Doodle(_models[1], glm::vec3(45.5f, 33.5f, -74.5f), glm::vec3(3.0f)));                                // sun 4
    _doodles.push_back(Doodle(_models[2], glm::vec3(-12.5f, -4.5f, -12.0f), glm::vec3(1.1f), glm::vec3(0.0f, 90.0f, 0.0f))); // mountain 5
    _doodles.push_back(Doodle(_models[2], glm::vec3(-2.5f, -6.0f, -14.0f), glm::vec3(1.1f)));                                // mountain 6
    _doodles.push_back(Doodle(_models[2], glm::vec3(9.0f, -5.0f, -13.0f), glm::vec3(1.4f)));                                 // mountain 7
    _doodles.push_back(Doodle(_models[5], glm::vec3(0.0f, -8.5f, -28.5f)));                                                  // ground 8

    Calculate();

    _players.push_back(Player(_doodles[0], 9.0f));
    _players[0].AttachController(&_keyboard);
}

bool Scene::DidRequestStop()
{
    return _input.DidRequestStop();
}

void Scene::ProcessInput()
{
    _input.Process();
}

void Scene::Update(float deltaTime)
{
    _players[0].Update(deltaTime);
    _doodles[0].Calculate();
}
