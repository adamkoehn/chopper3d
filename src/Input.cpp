#include "Input.h"

Input::Input() : _stop(false)
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

        if (_controllers.size() < 1)
        {
            return;
        }

        glm::vec2 axis = _controllers[0]->GetAxis();

        if (event.type == SDL_KEYDOWN)
        {
            switch (event.key.keysym.sym)
            {
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
            case SDLK_SPACE:
                _controllers[0]->StartShooting();
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
            case SDLK_SPACE:
                _controllers[0]->StopShooting();
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
}

bool Input::DidRequestStop()
{
    return _stop;
}
