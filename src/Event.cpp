#include "Event.h"

void Event::SetType(EventType type)
{
    _type = type;
}

EventType Event::GetType()
{
    return _type;
}
