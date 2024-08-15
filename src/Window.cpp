#include "Window.h"

Window::Window(int width, int height)
{
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS);

    window = SDL_CreateWindow(
        "Chopper 3D",
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        width,
        height,
        SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);

    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_ES);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 0);

    context = SDL_GL_CreateContext(window);
    SDL_GL_SetSwapInterval(1);

    GLenum init = glewInit();
    if (init != GLEW_OK)
    {
        std::cerr << "glewInit() failed: " << glewGetErrorString(init) << std::endl;
    }

    glViewport(0, 0, width, height);
    glClearColor(0.2f, 0.3f, 0.3f, 0.0f);
    glEnable(GL_DEPTH_TEST);
}

Window::~Window()
{
    SDL_GL_DeleteContext(context);
    SDL_DestroyWindow(window);
}

void Window::Clear()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Window::Swap()
{
    SDL_GL_SwapWindow(window);
}
