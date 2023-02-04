#include <SDL.h>
#include <OpenGL/gl.h>

#include "shader.h"
#define W 1600
#define H 900
#define GL_SILENCE_DEPRECATION

void glUniformlf(int location, float v0);
void glUniform2f(int location, float vO, float v1);

int main(int argc, char *argv[])
{
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window *screen =
        SDL_CreateWindow("Oops.",
                         SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                         0, 1, SDL_WINDOW_OPENGL);
    SDL_Renderer *rend = SDL_CreateRenderer(screen, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    SDL_SetRenderDrawColor(rend, 0, 0, 0, 255);
    glViewport(0, 0, W, H);

    int p = glCreateProgram();
    shader(shader_fragment, GL_FRAGMENT_SHADER, p);
    glLinkProgram(p);
    glUseProgram(p);
    int timeLocation = glGetUniformLocation(p, "time");
    int resolution = glGetUniformLocation(p, "resolution");
    glUniform2f(resolution, W, H);
    SDL_Event e;
    for (;;)
    {
        SDL_PollEvent(&e);
        if (e.type == SDL_QUIT)
            break;
        float t = SDL_GetTicks() / 500.0;
        glUniformlf(timeLocation, t);
        glRecti(-1, -1, 1, 1);
        SDL_GL_SwapWindow(screen);
    }
    SDL_DestroyRenderer(rend);
    SDL_DestroyWindow(screen);
    SDL_Quit();
    return 0;
}