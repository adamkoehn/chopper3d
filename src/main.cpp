#include "Camera.h"
#include "Window.h"
#include "Shader.h"
#include "Mesh.h"

#include <glm/glm.hpp>

int main()
{
    int width = 1024;
    int height = 768;

    Window window(width, height);
    Shader shader("shaders/std.vert.glsl", "shaders/std.frag.glsl");
    Camera camera(glm::radians(45.0f), (float)width / (float)height);

    shader.Use();
    shader.SetView(camera.GetView());
    shader.SetProjection(camera.GetProjection());

    std::vector<Vertex> vertices = {
        Vertex{.Position = glm::vec3(-0.5f, -0.5f, 0.0f), .Normal = glm::vec3(0.0f, 0.0f, 1.0f), .TexCoords = glm::vec2(0.0f, 0.0f)},
        Vertex{.Position = glm::vec3(0.5f, -0.5f, 0.0f), .Normal = glm::vec3(0.0f, 0.0f, 1.0f), .TexCoords = glm::vec2(0.0f, 0.0f)},
        Vertex{.Position = glm::vec3(0.0f, 0.5f, 0.0f), .Normal = glm::vec3(0.0f, 0.0f, 1.0f), .TexCoords = glm::vec2(0.0f, 0.0f)}};
    std::vector<unsigned> indices = {0, 1, 2};
    std::vector<Texture> textures = {};
    Mesh triangle(vertices, indices, textures);

    glm::mat4 model = glm::mat4(1.0f);
    model = glm::scale(model, glm::vec3(10.0f));
    shader.SetModel(model);

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
        triangle.Draw();
        window.Swap();
    }

    SDL_Quit();
}