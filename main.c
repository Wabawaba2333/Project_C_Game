#include <stdio.h>
#include <SDL3/SDL.h>
#include <stdbool.h>

int main(void)
{
    if (!SDL_Init(SDL_INIT_VIDEO)) {
        printf("SDL Init Error: %s\n", SDL_GetError());
        return 1;
    }

    SDL_Window *window = SDL_CreateWindow("SDL Renderer Test", 800, 600, 0);
    if (!window) {
        printf("Window Error: %s\n", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    // Create the renderer
    SDL_Renderer *renderer = SDL_CreateRenderer(window, NULL);
    if (!renderer) {
        printf("Renderer Error: %s\n", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    bool running = true;
    SDL_Event event;

    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_EVENT_QUIT) {
                running = false;
            }
        }

        // 1. Set drawing color (Cornflower Blue)
        SDL_SetRenderDrawColor(renderer, 100, 149, 237, 255);
        
        // 2. Clear the screen with the selected color
        SDL_RenderClear(renderer);
        
        // 3. Update the window
        SDL_RenderPresent(renderer);
    }

    // Clean up
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}