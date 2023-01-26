#include <SDL.h>
#include <stdio.h>

#define SCREEN_WIDTH 1200
#define SCREEN_HEIGHT 1000

void draw(SDL_Surface *s, SDL_Rect *r)
{
    SDL_FillRect(s, NULL, 0x000000);
    SDL_FillRect(s, r, SDL_MapRGB(s->format, 0xFF, 0x00, 0xFF));
}

int main()
{
    SDL_Window *window = NULL;

    // //The surface contained by the window
    SDL_Surface *screenSurface = NULL;

    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return 0;
    }
    window = SDL_CreateWindow("project-omikron", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_RESIZABLE);
    screenSurface = SDL_GetWindowSurface(window);

    SDL_Rect dims;
    dims.x = (SCREEN_WIDTH / 2) - 100;
    dims.y = (SCREEN_WIDTH / 2) - 200;
    dims.w = 200;
    dims.h = 200;

    SDL_FillRect(screenSurface, &dims, SDL_MapRGB(screenSurface->format, 0xFF, 0x00, 0xFF));
    SDL_UpdateWindowSurface(window);

    SDL_Event e;
    int quit = 0;

    while (quit == 0)
    {
        while (SDL_PollEvent(&e))
        {
            switch (e.type)
            {
            case SDL_QUIT:
                printf("quitting\n");
                quit = 1;
                break;
            case SDL_WINDOWEVENT:
                printf("window event\n");
                break;
            case SDL_MOUSEMOTION:
                printf("mouse event\n");
            case SDL_KEYUP:
            case SDL_KEYDOWN:
                switch (e.key.keysym.scancode)
                {
                case SDL_SCANCODE_W:
                    dims.y -= 10;
                    break;
                case SDL_SCANCODE_S:
                    dims.y += 10;
                    break;
                case SDL_SCANCODE_A:
                    dims.x -= 10;
                    break;
                case SDL_SCANCODE_D:
                    dims.x += 10;
                    break;
                default:
                    break;
                }
                draw(screenSurface, &dims);
                SDL_UpdateWindowSurface(window);
                break;
            default:
                if (e.type != 771)
                    printf("not sure what event: %d\n", e.type);
                break;
            }
        }
    }

    // Cleanup
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
