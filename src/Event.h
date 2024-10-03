#ifndef SRC_EVENT
#define SRC_EVENT

enum EventType
{
    EVENT_TYPE_PEW,
};

class Event
{
public:
    void SetType(EventType type);
    EventType GetType();

private:
    EventType _type;
};

#endif /* SRC_EVENT */
