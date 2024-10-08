#include "main.h"

SDL_Texture *wallTexture = NULL;
SDL_Texture *startTexture = NULL;
/**
 * loadMedia - Loads media used in the maze
 * Return: true if successful, false otherwise
 */

bool loadMedia()
{
    SDL_Surface *wallSurface = NULL;
    SDL_Surface *startSurface = NULL;
    
    
    /* Load images */
    startSurface = IMG_Load("images/runaway_bride.png");
    wallSurface = IMG_Load("images/purplestone.png");
    
    if (startSurface == NULL || wallSurface == NULL)
    {
        printf("Couldn't load images\n");
        return false;
    }
    startTexture = SDL_CreateTextureFromSurface(renderer, startSurface);
    wallTexture = SDL_CreateTextureFromSurface(renderer, wallSurface);
    
    if (startTexture == NULL || wallTexture == NULL)
    {
        printf("Couldn't create textures\n");
        return false;
    }
    SDL_FreeSurface(startSurface);
    SDL_FreeSurface(wallSurface);
    return true;
}
