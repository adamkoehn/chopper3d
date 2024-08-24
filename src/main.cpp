#include <glm/glm.hpp>

#include "Camera.h"
#include "Window.h"
#include "Shader.h"
#include "Model.h"
#include "Scene.h"
#include "Input.h"
#include "Player.h"

int main()
{
    int width = 1024;
    int height = 768;

    Window window(width, height);
    Shader shader("shaders/doodle.vert.glsl", "shaders/doodle.frag.glsl");
    Camera camera(glm::radians(45.0f), (float)width / (float)height);

    shader.Use();
    shader.SetView(camera.GetView());
    shader.SetProjection(camera.GetProjection());
    shader.SetLightPosition(glm::vec3(20.0f, 20.0f, 20.0f));

    Scene scene;
    scene.Load();

    Uint32 last = SDL_GetTicks();
    Uint32 current = last;
    float delta = 0.0f;

    while (!scene.DidRequestStop())
    {
        last = current;
        current = SDL_GetTicks();
        delta = ((float)current - (float)last) / 1000.0f;

        scene.ProcessInput();
        scene.Update(delta);

        window.Clear();
        scene.Draw(shader);

        window.Swap();
    }

    SDL_Quit();
}