#ifndef SRC_INPUT
#define SRC_INPUT

#include <SDL2/SDL.h>
#include <vector>

#include "Controller.h"

class Input
{
public:
    Input();
    void Process();
    bool DidRequestStop();
    void AddController(Controller *controller);

private:
    bool _stop;
    std::vector<Controller *> _controllers;
};

#endif /* SRC_INPUT */
