#include "Window.h"
#include "Shader.h"
#include "Triangle.h"

int main()
{
    Window window;
    Shader shader("shaders/std.vert.glsl", "shaders/std.frag.glsl");

    shader.Use();

    Triangle triangle;

    int run = 1;
    while (run)
    {
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_KEYDOWN)
            {
                if (event.key.keysym.sym == SDLK_ESCAPE)
                {
                    run = 0;
                }
            }
        }

        // update
        glClear(GL_COLOR_BUFFER_BIT);
        triangle.Draw();
        window.Swap();
    }

    SDL_Quit();
}