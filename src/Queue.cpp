#include "Queue.h"

Queue::Queue(unsigned int size)
    : _size(size), _read(0), _write(0), _full(false)
{
    _commands = (Command **)::operator new(sizeof(Command *) * size);
}

Queue::~Queue()
{
    delete _commands;
}

void Queue::Send(Command *command)
{
    if (_full)
    {
        return; // discard
    }

    _commands[_write] = command;
    _write = (_write + 1) % _size;

    if (_write == _read)
    {
        _full = true;
    }
}

void Queue::Update()
{
    while (_read != _write)
    {
        Command *command = _commands[_read];

        command->Execute();
        delete command;

        _read = (_read + 1) % _size;
    }
}
