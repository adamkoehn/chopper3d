#include "Bullet.h"

Bullet::Bullet()
    : _speed(12.0f)
{
    _velocity = glm::normalize(glm::vec3(1.0f, -1.0f, 0.0f)) * _speed;
}

glm::vec3 Bullet::Update(float deltaTime, glm::vec3 &position)
{
    return position + (_velocity * deltaTime);
}

bool Bullet::IsActive(glm::vec3 &position)
{
    return position.x > -12.0f && position.x < 12.0f && position.y > -12.0f && position.y < 12.0f;
}
