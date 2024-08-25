#include "Player.h"

Player::Player(Queue &queue, Doodle &doodle, float flightSpeed, float gunFrequency)
    : _queue(queue),
      _doodle(doodle),
      _flightSpeed(flightSpeed),
      _gunFrequency(gunFrequency),
      _timeUntilNextShot(0.0f),
      _controller(nullptr)
{
}

void Player::Update(float deltaTime)
{
    if (_controller == nullptr)
    {
        return;
    }

    updateMove(deltaTime);
    updateShooting(deltaTime);
}

void Player::updateMove(float deltaTime)
{
    glm::vec2 axis = _controller->GetAxis();

    if (axis.x == 0.0f && axis.y == 0.0f)
    {
        return;
    }

    glm::vec2 move = glm::normalize(axis) * _flightSpeed * deltaTime;
    glm::vec3 position = _doodle.GetPosition();
    glm::vec3 updated = glm::vec3(position.x + move.x, position.y + move.y, 0.0f);
    _doodle.SetPosition(updated);
}

void Player::updateShooting(float deltaTime)
{
    if (_controller->IsShooting())
    {
        _timeUntilNextShot -= deltaTime;

        if (_timeUntilNextShot <= 0.0f)
        {
            _queue.Send(new Shoot());
            _timeUntilNextShot += _gunFrequency;
        }
    }
    else
    {
        _timeUntilNextShot = 0.0f;
    }
}

void Player::AttachController(Controller *controller)
{
    _controller = controller;
}
