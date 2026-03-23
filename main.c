#include <stdio.h>
#include <SDL3/SDL.h>

int main(void)
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
        return 1;

    SDL_Window *window = SDL_CreateWindow("SDL Test", 800, 600, 0);

    SDL_Delay(2000);

    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}