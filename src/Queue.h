#ifndef SRC_QUEUE
#define SRC_QUEUE

#include <iostream>
#include "Command.h"

class Queue
{
public:
    Queue(unsigned int size);
    ~Queue();
    void Send(Command *command);
    void Update();

private:
    unsigned int _size;
    unsigned int _read;
    unsigned int _write;
    bool _full;
    Command **_commands;
};

#endif /* SRC_QUEUE */
