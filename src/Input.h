#ifndef SRC_INPUT
#define SRC_INPUT

#include <SDL2/SDL.h>
#include <vector>

#include "Controller.h"
#include "Scene.h"

enum InputMode
{
    MODE_GAME = 0,
    MODE_DESIGN = 1,
};

class Input
{
public:
    Input(Scene &scene);
    void Process();
    bool DidRequestStop();
    void AddController(Controller *controller);

private:
    void processDesignMode(SDL_Event &event);
    void processGameMode(SDL_Event &event);

private:
    Scene &_scene;
    bool _stop;
    InputMode _mode;
    std::vector<Controller *> _controllers;
};

#endif /* SRC_INPUT */
