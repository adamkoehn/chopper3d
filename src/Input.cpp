#include "Input.h"

Input::Input(Scene &scene)
    : _scene(scene), _stop(false), _mode(MODE_GAME)
{
}

void Input::Process()
{
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        if (event.type == SDL_KEYDOWN)
        {
            switch (event.key.keysym.sym)
            {
            case SDLK_ESCAPE:
                _stop = true;
                break;
            }
        }

        switch (_mode)
        {
        case MODE_GAME:
            processGameMode(event);
            break;
        case MODE_DESIGN:
            processDesignMode(event);
            break;
        }
    }
}

bool Input::DidRequestStop()
{
    return _stop;
}

void Input::processDesignMode(SDL_Event &event)
{
    if (event.type == SDL_KEYDOWN)
    {
        switch (event.key.keysym.sym)
        {
        case SDLK_UP:
            _scene.Up();
            break;
        case SDLK_DOWN:
            _scene.Down();
            break;
        case SDLK_LEFT:
            _scene.Left();
            break;
        case SDLK_RIGHT:
            _scene.Right();
            break;
        case SDLK_w:
            _scene.Back();
            break;
        case SDLK_s:
            _scene.Forward();
            break;
        case SDLK_SPACE:
            _scene.Select();
            break;
        case SDLK_d:
            _scene.ScaleUp();
            break;
        case SDLK_a:
            _scene.ScaleDown();
            break;
        case SDLK_m:
            _mode = MODE_GAME;
            break;
        }
    }
}

void Input::processGameMode(SDL_Event &event)
{
    if (event.type == SDL_KEYDOWN)
    {
        switch (event.key.keysym.sym)
        {
        case SDLK_m:
            _mode = MODE_DESIGN;
            break;
        }
    }
}
