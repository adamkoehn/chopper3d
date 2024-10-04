#include "Tank.h"

Tank::Tank() : _speed(4.0f)
{
}

bool Tank::IsActive(glm::vec3 &position)
{
    return position.x > -12.0f;
}

glm::vec3 Tank::Update(float deltaTime, glm::vec3 &position)
{
    return position + (glm::vec3(-1.0f, 0.0f, 0.0f) * _speed * deltaTime);
}
