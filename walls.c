#include "main.h"

float fov = PI / 3;

/**
 * castHorizontalRay - Casts Horizontal ray
 * @angle: the current angle of the ray
 * Return: position of horizontal ray
 */
intersection* castHorizontalRay(float angle)
{
    intersection *h_intersect = NULL; /* First horizontal intersection */
    float delta_y = 0, delta_x = 0;
    
    h_intersect = malloc(sizeof(intersection));
    
    if (h_intersect == NULL)
    {
        printf("Couldn't allocate memory for first horizontal intersection.\n");
        return NULL;
    }
    
    /* Check for horizontal ray */
    if (angle > 0 && angle < PI)
    {
        /* Ray is facing up */
        h_intersect->y = ((player->y / cubeSize) * cubeSize) - 0.01; /* Align to previous grid */
        delta_y = -cubeSize;
    }
    else if (angle > PI && angle < 2 * PI)
    {
        /* Ray is facing down */
        h_intersect->y = ((player->y / cubeSize) * cubeSize) + cubeSize;
        delta_y = cubeSize;
    }
    else
    {
        /* Handle edge case when ray is exactly horizontal */
        h_intersect->x = player->x;
        h_intersect->y = player->y;
        return h_intersect;
    }

    h_intersect->x = player->x + (player->y - h_intersect->y) / tan(angle);
    delta_x = cubeSize / tan(angle);

    while (!(checkWall(h_intersect)))
    {
        h_intersect->x += delta_x;
        h_intersect->y += delta_y;
    }
    h_intersect->y %= 64;
    return h_intersect;
}

/**
 * castVerticalRay - Casts Vertical ray
 * @angle: the current angle of the ray
 * Return: position of vertical ray
 */
intersection * castVerticalRay(float angle)
{
    intersection *v_intersect = NULL; /* First vertical intersection */
    float delta_x = 0, delta_y = 0;
    
    v_intersect = malloc(sizeof(intersection));
    
    if (v_intersect == NULL)
    {
        printf("Couldn't allocate memory for first vertical intersection.\n");
        return NULL;
    }

    /* Ray is facing left */
    if (angle > PI / 2 && angle < 3 * PI / 2)
    {
        v_intersect->x = ((player->x / cubeSize) * cubeSize) - 1; /* Align to previous grid */
        delta_x = -cubeSize;
    }
    /* Ray is facing right */
    else if (angle < PI / 2 || angle > 3 * PI / 2)
    {
        v_intersect->x = ((player->x / cubeSize) * cubeSize) + cubeSize;
        delta_x = cubeSize;
    }
    else
    {
        /* Handle edge case when ray is exactly vertical */
        v_intersect->x = player->x;
        v_intersect->y = player->y;
        return v_intersect;
    }

    v_intersect->y = player->y + (player->x - v_intersect->x) * tan(angle);
    delta_y = cubeSize / tan(angle);

    while (!(checkWall(v_intersect)))
    {
        v_intersect->x += delta_x;
        v_intersect->y += delta_y;
    }
    v_intersect->x %= 64;
    return v_intersect;
}

/**
 * checkWall - check if there's a wall at the given point
 * @point: point to check from.
 * Return: true if there's a wall, false if there's none.
 */
bool checkWall(intersection *point)
{
    int floorX = (int)(point->x / cubeSize);
    int floorY = (int)(point->y / cubeSize);

    /* Make sure we're within the boundaries of the map */
    if (floorX < 0 || floorX >= 14 || floorY < 0 || floorY >= 14)
    {
        return true;  /* Treat out-of-bound areas as walls */
    }

    /* Return true if there's a wall at the current map position */
    return map[floorY][floorX] != 0;
}

/**
 * findDistance - Finds distance to the wall
 * Return: float
 */

float findDistance(intersection *point, float angle)
{
    float distance;
    
    /* Uses the Pythagoras Theorem */
    distance = sqrt(pow(player->x - point->x, 2) + pow(player->y - point->y, 2));

    return distance;
}

/**
 * castRay - Finds distance of actual ray
 * Return: float
 */

intersection* castRay(position *point, float angle)
{
    intersection *vertical = NULL, *horizontal = NULL;
    
    if (angle < 0)
        angle += 2 * PI;
    if (angle > 2 * PI)
        angle -= 2 * PI;
    vertical = castVerticalRay(angle);
    horizontal = castHorizontalRay(angle);
    
    vertical->distance = findDistance(vertical, angle);
    horizontal->distance = findDistance(horizontal, angle);
    
    if (vertical->distance < horizontal->distance)
    {
        return vertical;
    }
        
    else
    {
        return horizontal;
    }
        
}

/**
 * drawWall - Draws all walls for the player.
 * Return: true if successful, false otherwise
 */

bool drawWall(position *player)
{
    int numRays = SCREEN_WIDTH / cubeSize;
    float wallHeight;
    int ray;
    float distance;
    intersection *wallSlice;
    float angle;
    float dist2Plane = (SCREEN_WIDTH / 2) / tan(fov);
    
    for (ray = 0; ray < numRays; ray++)
    {
        angle = player->viewAngle + (fov / 2) - (ray * (fov / numRays));
        if (angle < 0)
            angle += 2 * PI;
        if (angle > 2 * PI)
            angle -= 2 * PI;
        wallSlice = castRay(player, angle);
        distance = wallSlice->distance * cos(player->viewAngle - angle);
        if (distance > SCREEN_HEIGHT)
            distance = SCREEN_HEIGHT;
        wallHeight = (cubeSize / distance) * dist2Plane;
        //float shade = 1 / (1 + distance * 0.05);  /* Modify shadingFactor as needed */
        //SDL_SetTextureColorMod(wallTexture, 255 * shade, 255 * shade, 255 * shade);
        
        SDL_Rect wall = {(ray * (SCREEN_WIDTH / numRays)), ((SCREEN_HEIGHT / 2) - (wallHeight / 2)), (SCREEN_WIDTH / numRays), wallHeight};
        
        SDL_RenderCopy(renderer, wallTexture, NULL, &wall);
    }
    return true;
}

