#include "Scene.h"

Scene::Scene()
    : _tankFrequency(3.0f),
      _nextTank(0.0f),
      _selected(0),
      _activePlayers(1)
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

    Doodle *chopper = _manager.CreateDynamicDoodle("chopper", glm::vec3(-7.0f, 4.5f, 0.0f), glm::vec3(0.4f));

    _manager.UpdateStaticAssets();

    _players[0].SetUp(&_queue, &_keyboard, 9.0f, 0.25f);
    chopper->MakeDynamic(&_players[0]);
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
            _manager.CreateBullet(event->GetPosition());
        }
    }

    _nextTank -= deltaTime;
    if (_nextTank <= 0.0f)
    {
        _nextTank = _tankFrequency;
        Doodle *tank = _manager.CreateDynamicDoodle("tank", glm::vec3(13.0f, -7.0f, 0.0f), glm::vec3(0.2f));
        tank->MakeDynamic(&_tank);
    }

    _manager.Update(deltaTime);
}
