#include <SDL.h>
#include <OpenGL/GL.h>

#include "shader.h"

#define W 1600
#define H 900
#define GL_SILENCE_DEPRECATION

void glUniformLocation(int program, const char *name);
void glUniform1f(int location, float vO);
void glUniform2f(int location, float vO, float v1);

int test()
{
    printf("starting");
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return 0;
    }

    SDL_Window *window = NULL;
    SDL_Renderer *rend = NULL;
    window =
        SDL_CreateWindow("Shaders",
                         SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                         W, H, SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);

    rend = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    SDL_SetRenderDrawColor(rend, 0, 0, 0, 255);

    // throws an error
    int p = glCreateProgram();
    // shader(shader_fragment, GL_FRAGMENT_SHADER, p);
    // glLinkProgram(p);
    // glUseProgram(p);
    // int timeLocation = glGetUniformLocation(p, "time");
    // int resolution = glGetUniformLocation(p, "resolution");
    // glUniform2f(resolution, W, H);

    // printf("starting event loop!");
    // SDL_Event e;
    // for (;;)
    // {
    //     SDL_PollEvent(&e);
    //     if (e.type == SDL_QUIT)
    //         break;
    //     float t = SDL_GetTicks() / 500.0;
    //     glUniform1f(timeLocation, t);
    //     glRecti(-1, -1, 1, 1);
    //     SDL_GL_SwapWindow(screen);
    // }

    // SDL_DestroyRenderer(rend);
    // SDL_DestroyWindow(screen);
    // SDL_Quit();

    // return 0;
}

int main()
{
    printf("oioi");
    test();
    return 0;
}