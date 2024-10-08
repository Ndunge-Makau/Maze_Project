#include "main.h"

SDL_Renderer *renderer;
SDL_Window *window;

/**
 * main - Entry Point
 * Return: 0 when successful, -1 if failed
 */

int main(void)
{
    SDL_Event event;
    bool quit = false;
    
    if (!init())
    {
        printf("Could not start!\n");
        return (-1);
    }
    if (!loadMedia())
    {
        printf("Couldn't load media: %s\n", SDL_GetError());
        return (-1);
    }
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, startTexture, NULL, NULL);
    SDL_RenderPresent(renderer);
    
    while (quit == false)
    {
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                quit = true;
            }
            else if (event.type == SDL_KEYDOWN)
            {
                handleEvent(player, event);
                if (!render())
                {
                    printf("Couldn't render\n");
                    return (-1);
                }
            }
        }
        /*
       
        SDL_RenderPresent(renderer); */
    }
    return (0);
}
