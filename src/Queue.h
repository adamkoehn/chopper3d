#ifndef SRC_QUEUE
#define SRC_QUEUE

#include <glm/glm.hpp>

#include "Event.h"

#define QUEUE_SIZE 200

class Queue
{
public:
    Queue();
    void Send(EventType type, glm::vec3 position);
    Event *GetNext();

private:
    unsigned int _read;
    unsigned int _write;
    bool _full;
    Event _events[QUEUE_SIZE];
};

#endif /* SRC_QUEUE */
