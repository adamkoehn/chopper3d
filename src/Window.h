#ifndef SRC_WINDOW
#define SRC_WINDOW

#include <SDL2/SDL.h>
#include <GL/glew.h>
#include <SDL2/SDL_opengl.h>
#include <iostream>

class Window
{
public:
    Window(int width, int height);
    ~Window();
    void Clear();
    void Swap();

private:
    SDL_Window *window;
    SDL_GLContext context;
};

#endif /* SRC_WINDOW */
