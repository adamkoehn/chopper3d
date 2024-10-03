#include "Scene.h"

Scene::Scene()
    : _selected(0), _activePlayers(1)
{
    _input.AddController(&_keyboard);
}

void Scene::Draw(Shader &shader)
{
    _manager.Draw(shader);
}

void Scene::Load()
{
    _manager.LoadLevel();

    Doodle &chopper = _manager.CreateDynamicDoodle("chopper", glm::vec3(-7.0f, 4.5f, 0.0f), glm::vec3(0.4f));
    _manager.CreateDynamicDoodle("tank", glm::vec3(9.0f, -7.0f, 0.0f), glm::vec3(0.2f));
    _manager.CreateDynamicDoodle("bullet", glm::vec3(0.0f), glm::vec3(0.2f), glm::vec3(0.0f, 0.0f, -135.0f));

    _manager.UpdateStaticAssets();

    _players[0].SetUp(&_queue, &chopper, &_keyboard, 9.0f, 0.25f);
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
    while (Event *event = _queue.GetNext())
    {
        if (event->GetType() == EVENT_TYPE_PEW)
        {
            std::cout << "shooting" << std::endl;
        }
    }

    for (int i = 0; i < _activePlayers; i++)
    {
        _players[i].Update(deltaTime);
    }

    _manager.Update();
}
