#ifndef SRC_EVENT
#define SRC_EVENT

#include <glm/glm.hpp>

enum EventType
{
    EVENT_TYPE_PEW,
};

class Event
{
public:
    void SetUp(EventType type, glm::vec3 position);
    EventType GetType();
    glm::vec3 GetPosition();

private:
    EventType _type;
    glm::vec3 _position;
};

#endif /* SRC_EVENT */
