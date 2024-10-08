#include "main.h"

/**
 * handleEvent - Handle key events
 * Return: nothing
 */

void handleEvent(position *player, SDL_Event event)
{
    if (map[player->y][player->x] == 0) /* Handle Wall Collisions */
    {
        if (event.key.keysym.sym == SDLK_UP)
        {
            printf("Moving Forward!\n");
            player->x -= player->delta_x * cos(player->viewAngle) * 0.005;
            player->y -= player->delta_y * sin(player->viewAngle) * 0.005;
        }
        if (event.key.keysym.sym == SDLK_DOWN)
        {
            printf("Moving Back!\n");
            player->x += player->delta_x * cos(player->viewAngle)* 0.005;
            player->y += player->delta_y * sin(player->viewAngle)* 0.005;
        }
        if (event.key.keysym.sym == SDLK_RIGHT)
        {
            printf("Turning Right!\n");
            player->viewAngle += PI / 6;
            player->viewAngle = fmod(player->viewAngle, 2 * PI);
        }
        if (event.key.keysym.sym == SDLK_LEFT)
        {
            printf("Turning Left!\n");
            player->viewAngle -= PI / 6;
            player->viewAngle = fmod(player->viewAngle, 2 * PI);
        }
    }
}
