#include "Scene.h"

Scene::Scene()
    : _selected(0), _queue(Queue(100))
{
    _doodles.reserve(20);
    _models.reserve(20);
    _players.reserve(4);
    _input.AddController(&_keyboard);
}

void Scene::Draw(Shader &shader)
{
    _manager.Draw(shader);
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
    _manager.LoadLevel();

    unsigned int chopper = _manager.CreateDynamicDoodle("chopper", glm::vec3(-7.0f, 4.5f, 0.0f), glm::vec3(0.4f));
    _manager.CreateDynamicDoodle("tank", glm::vec3(9.0f, -7.0f, 0.0f), glm::vec3(0.2f));
    _manager.CreateDynamicDoodle("bullet", glm::vec3(0.0f), glm::vec3(0.2f), glm::vec3(0.0f, 0.0f, -135.0f));

    _manager.UpdateStaticAssets();

    _players.push_back(Player(_queue, _manager.GetDynamicDoodle(chopper), 9.0f, 0.25f));
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
    for (std::vector<Player>::iterator player = _players.begin(); player != _players.end(); ++player)
    {
        player->Update(deltaTime);
    }

    _manager.Update();
    _queue.Update();
}
