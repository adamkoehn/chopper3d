#include "Event.h"

void Event::SetUp(EventType type, glm::vec3 position)
{
    _type = type;
    _position = position;
}

EventType Event::GetType()
{
    return _type;
}

glm::vec3 Event::GetPosition()
{
    return _position;
}
