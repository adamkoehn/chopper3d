#include "Player.h"

void Player::SetUp(Queue *queue, Controller *controller, float flightSpeed, float gunFrequency)
{
    _queue = queue;
    _controller = controller;
    _flightSpeed = flightSpeed;
    _gunFrequency = gunFrequency;
    _timeUntilNextShot = 0.0f;
}

glm::vec3 Player::Update(float deltaTime, glm::vec3 &position)
{
    glm::vec3 updated = updateMove(deltaTime, position);
    updateShooting(deltaTime, position);

    return updated;
}

bool Player::IsActive(glm::vec3 &position)
{
    return position.x > -12.0f && position.x < 12.0f && position.y > -12.0f && position.y < 12.0f;
}

glm::vec3 Player::updateMove(float deltaTime, glm::vec3 &position)
{
    glm::vec2 axis = _controller->GetAxis();

    if (axis.x == 0.0f && axis.y == 0.0f)
    {
        return position;
    }

    glm::vec2 move = glm::normalize(axis) * _flightSpeed * deltaTime;

    return glm::vec3(position.x + move.x, position.y + move.y, 0.0f);
}

void Player::updateShooting(float deltaTime, glm::vec3 &position)
{
    if (!_controller->IsShooting())
    {
        _timeUntilNextShot = 0.0f;
        return;
    }

    _timeUntilNextShot -= deltaTime;

    if (_timeUntilNextShot <= 0.0f)
    {
        _queue->Send(EVENT_TYPE_PEW, position);
        _timeUntilNextShot += _gunFrequency;
    }
}
