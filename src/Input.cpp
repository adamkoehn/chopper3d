#include "Input.h"

Input::Input(Scene &scene)
    : _scene(scene), _stop(false), _mode(MODE_GAME)
{
}

void Input::AddController(Controller *controller)
{
    _controllers.push_back(controller);
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

        if (event.type == SDL_QUIT)
        {
            _stop = true;
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
    if (_controllers.size() < 1)
    {
        return;
    }

    glm::vec2 axis = _controllers[0]->GetAxis();

    if (event.type == SDL_KEYDOWN)
    {
        switch (event.key.keysym.sym)
        {
        case SDLK_m:
            _mode = MODE_DESIGN;
            break;
        case SDLK_w:
            axis.y += 1.0f;
            break;
        case SDLK_s:
            axis.y -= 1.0f;
            break;
        case SDLK_a:
            axis.x -= 1.0f;
            break;
        case SDLK_d:
            axis.x += 1.0f;
            break;
        }
    }

    if (event.type == SDL_KEYUP)
    {
        switch (event.key.keysym.sym)
        {
        case SDLK_w:
            axis.y -= 1.0f;
            break;
        case SDLK_s:
            axis.y += 1.0f;
            break;
        case SDLK_a:
            axis.x += 1.0f;
            break;
        case SDLK_d:
            axis.x -= 1.0f;
            break;
        }
    }

    if (axis.x > 1.0f)
    {
        axis.x = 1.0f;
    }

    if (axis.x < -1.0f)
    {
        axis.x = -1.0f;
    }

    if (axis.y > 1.0f)
    {
        axis.y = 1.0f;
    }

    if (axis.y < -1.0f)
    {
        axis.y = -1.0f;
    }

    _controllers[0]->SetAxis(glm::vec2(axis));
}
