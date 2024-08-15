#include "Camera.h"
#include "Window.h"
#include "Shader.h"
#include "Model.h"

#include <glm/glm.hpp>

int main()
{
    int width = 1024;
    int height = 768;

    Window window(width, height);
    Shader shader("shaders/std.vert.glsl", "shaders/std.frag.glsl");
    Camera camera(glm::radians(45.0f), (float)width / (float)height);

    shader.Use();

    Model splash("models/cloud/cloud.obj");
    glm::mat4 splashModel = glm::mat4(1.0f);

    shader.SetView(camera.GetView());
    shader.SetProjection(camera.GetProjection());
    shader.SetModel(splashModel);
    shader.SetLightPosition(glm::vec3(20.0f, 20.0f, 20.0f));

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
        window.Clear();
        splash.Draw();
        window.Swap();
    }

    SDL_Quit();
}