#ifndef MAIN_H
#define MAIN_H

#include <stdbool.h>
#include <stdio.h>
#include <math.h>
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <stdlib.h>

#define SCREEN_WIDTH 960
#define SCREEN_HEIGHT 768
#define PI 3.1415926535 /* Value of PI */
#define DE



typedef struct position {
    int x;
    int y;
    float viewAngle;
    float delta_x;
    float delta_y;
} position;

typedef struct intersection {
    int x;
    int y;
    float distance;
} intersection;

extern SDL_Window *window;
extern SDL_Renderer *renderer;
extern SDL_Texture *startTexture;
extern SDL_Texture *wallTexture;
extern position *player;
extern int map[14][14];
extern int mapX, mapY;
extern int cubeSize;
extern float fov;

bool init(void);
bool render(void);
position* createPlayer(void);
bool drawMap(void);
intersection* castHorizontalRay(float angle);
intersection * castVerticalRay(float angle);
bool checkWall(intersection *point);
intersection* castRay(position *point, float angle);
float findDistance(intersection *point, float angle);
bool drawWall(position *player);
void handleEvent(position *player, SDL_Event event);
void drawPlayer(position *player);
bool loadMedia(void);

#endif /* MAIN_H */
