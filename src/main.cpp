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
    Shader shader("shaders/std.vert.glsl", "shaders/std.frag.glsl");
    Camera camera(glm::radians(45.0f), (float)width / (float)height);

    shader.Use();

    Scene scene(shader);

    Model cloud("models/cloud/cloud.obj");
    Model sun("models/sun/sun.obj");
    Model mountain("models/mountain/mountain.obj");
    Model chopper("models/chopper/chopper.obj");
    Model tank("models/tank/tank.obj");

    Doodle hero(chopper, glm::vec3(-7.0f, 4.5f, 0.0f));
    Doodle sampleTank(tank, glm::vec3(9.0f, -7.0f, 0.0f));
    Doodle cloudOne(cloud, glm::vec3(13.5f, 11.5f, -59.5f));
    Doodle cloudTwo(cloud, glm::vec3(-20.5f, 16.0f, -52.5f));
    Doodle theSun(sun, glm::vec3(45.5f, 33.5f, -74.5f));
    Doodle mountainOne(mountain, glm::vec3(-12.5f, -11.0f, -12.0f));
    Doodle mountainTwo(mountain, glm::vec3(-1.0f, -11.5f, -14.0f));
    Doodle mountainThree(mountain, glm::vec3(10.0f, -11.0f, -9.5f));

    hero.SetScale(glm::vec3(0.4f));
    sampleTank.SetScale(glm::vec3(0.2f));
    cloudOne.SetRotation(glm::vec3(0.0f, 45.0f, 0.0f));
    cloudTwo.SetScale(glm::vec3(1.2f));
    theSun.SetScale(glm::vec3(3.0f));
    mountainOne.SetScale(glm::vec3(1.1f));
    mountainOne.SetRotation(glm::vec3(0.0f, 90.0f, 0.0f));
    mountainTwo.SetScale(glm::vec3(1.1f));
    mountainThree.SetScale(glm::vec3(1.4f));

    scene.AddDoodle(&hero);
    scene.AddDoodle(&sampleTank);
    scene.AddDoodle(&cloudOne);
    scene.AddDoodle(&cloudTwo);
    scene.AddDoodle(&theSun);
    scene.AddDoodle(&mountainOne);
    scene.AddDoodle(&mountainTwo);
    scene.AddDoodle(&mountainThree);

    scene.Calculate();

    shader.SetView(camera.GetView());
    shader.SetProjection(camera.GetProjection());
    shader.SetLightPosition(glm::vec3(20.0f, 20.0f, 20.0f));

    Input input(scene);
    Controller keyboard;

    input.AddController(&keyboard);

    Player player(hero, 0.125f);

    player.AttachController(&keyboard);

    while (!input.DidRequestStop())
    {
        input.Process();

        player.Update();
        hero.Calculate();

        window.Clear();
        scene.Draw();

        window.Swap();
    }

    SDL_Quit();
}