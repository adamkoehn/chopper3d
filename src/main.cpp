#include <glm/glm.hpp>

#include "Camera.h"
#include "Window.h"
#include "Shader.h"
#include "Model.h"
#include "Scene.h"

int main()
{
    int width = 1024;
    int height = 768;

    Window window(width, height);
    Shader shader("shaders/std.vert.glsl", "shaders/std.frag.glsl");
    Camera camera(glm::radians(45.0f), (float)width / (float)height);

    shader.Use();

    Scene scene(shader);

    Model cloud("models/cloud/cloud.obj");
    Model sun("models/sun/sun.obj");
    Doodle cloudOne(cloud, glm::vec3(35.0f, 10.0f, -80.0f));
    Doodle cloudTwo(cloud, glm::vec3(-30.0f, 5.0f, -80.0f));
    Doodle theSun(sun, glm::vec3(50.0f, 40.0f, -80.0f));

    cloudOne.SetRotation(glm::vec3(0.0f, 45.0f, 0.0f));
    theSun.SetScale(glm::vec3(3.0f));

    scene.AddDoodle(&cloudOne);
    scene.AddDoodle(&cloudTwo);
    scene.AddDoodle(&theSun);

    scene.Update();

    shader.SetView(camera.GetView());
    shader.SetProjection(camera.GetProjection());
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
        scene.Draw();
        window.Swap();
    }

    SDL_Quit();
}