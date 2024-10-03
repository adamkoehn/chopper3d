#include "Queue.h"

Queue::Queue()
    : _read(0), _write(0), _full(false)
{
}

void Queue::Send(EventType type)
{
    if (_full)
    {
        return; // discard
    }

    _events[_write].SetType(type);
    _write = (_write + 1) % QUEUE_SIZE;

    if (_write == _read)
    {
        _full = true;
    }
}

Event *Queue::GetNext()
{
    if (_read == _write && !_full)
    {
        return nullptr;
    }

    Event *event = &_events[_read];
    _read = (_read + 1) % QUEUE_SIZE;

    if (_full)
    {
        _full = false;
    }

    return event;
}
