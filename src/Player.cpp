#include "Player.h"

Player::Player(Doodle &doodle, float speed)
    : _doodle(doodle), _speed(speed), _controller(nullptr)
{
}

void Player::Update(float deltaTime)
{
    if (_controller == nullptr)
    {
        return;
    }

    glm::vec2 axis = _controller->GetAxis();

    if (axis.x == 0.0f && axis.y == 0.0f)
    {
        return;
    }

    glm::vec2 move = glm::normalize(axis) * _speed * deltaTime;
    glm::vec3 position = _doodle.GetPosition();
    glm::vec3 updated = glm::vec3(position.x + move.x, position.y + move.y, 0.0f);
    _doodle.SetPosition(updated);
}

void Player::AttachController(Controller *controller)
{
    _controller = controller;
}
