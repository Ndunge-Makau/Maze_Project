#include "main.h"

position *player = NULL;

/**
 * init - starts the game
 * Return: true if sucessful, false otherwise
 */

bool init()
{
    int imgFlags = IMG_INIT_PNG;

    /* Initialize SDL */
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        printf("Could not initialize: SDL_Error: %s\n", SDL_GetError());
        return false;
    }
    else
    {
        /* Create Window */
        window = SDL_CreateWindow("Get Me Bride!", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
        if (window == NULL)
        {
            printf("Couldn't create window: SDL_Error: %s\n", SDL_GetError());
            return false;
        }
        else
        {
            /* Create Renderer */
            renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
            if (renderer == NULL)
            {
                printf("Couldn't create renderer: SDL_Error: %s\n", SDL_GetError());
                return false;
            }
            else
            {
                /* Render Start Page */
                /* Initialize SDL_Image */
                if (!(IMG_Init(imgFlags) & imgFlags))
                {
                    printf("SDL_Image could not be intialized: SDL_Error: %s\n", SDL_GetError());
                    return false;
                }
                 
                player = createPlayer();
                if (player == NULL)
                    return false;
            }
        }
    }
    return true;
}

position* createPlayer()
{
    position *player = NULL;
    
    player = malloc(sizeof(position));
    if (player == NULL)
    {
        printf("Couldn't create a player instance\n");
        return NULL;
    }
    player->x = 6 * cubeSize; /* player's x-coordinate */
    player->y = 2 * cubeSize; /* player's y-coordinate */
    player->viewAngle = PI / 2; /* Viewing angle */
    player->delta_x = 0;
    player->delta_y = 64;
    return player;
}

