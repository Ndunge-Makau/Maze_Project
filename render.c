#include "main.h"

/**
 * render - display content on screen
 * Return: true if successful, false otherwise
 */

bool render(void)
{
    SDL_RenderClear(renderer);
    
    /* if (!drawMap())
    {
        printf("Couldn't draw map\n");
        return false;
        
    } */
    
    
    if (!(drawWall(player)))
    {
        printf("Couldn't draw walls\n");
        return false;
    } 
    // drawPlayer(player);
    SDL_RenderPresent(renderer);
    return true;
}


/* void drawPlayer(position *player)
{
    SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255);
    SDL_RenderDrawPoint(renderer, player->x, player->y);
} */
