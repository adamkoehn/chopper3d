#include "Window.h"

Window::Window()
{
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS);

    window = SDL_CreateWindow(
        "Chopper 3D",
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        1024,
        768,
        SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);

    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_ES);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 0);

    context = SDL_GL_CreateContext(window);
    SDL_GL_MakeCurrent(window, context);
    SDL_GL_SetSwapInterval(1);

    GLenum init = glewInit();
    if (init != GLEW_OK) {
        std::cerr << "glewInit() failed: " << glewGetErrorString(init) << std::endl;
    }

    glViewport(0, 0, 1024, 768);
    glClearColor(0.2f, 0.3f, 0.3f, 0.0f);
}

Window::~Window()
{
    SDL_GL_DeleteContext(context);
    SDL_DestroyWindow(window);
}

void Window::Swap()
{
    SDL_GL_SwapWindow(window);
}
