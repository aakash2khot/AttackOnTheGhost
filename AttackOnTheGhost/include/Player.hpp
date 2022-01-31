#pragma once
#include<bits/stdc++.h>
#include"SDL.h"
#include<SDL_image.h>

using namespace std;
class Player
{
protected:
    float x, y;
    int height, width;
    string image;
    SDL_Rect destR;
    SDL_Rect srcR;
    SDL_Texture* playerTex;
    SDL_Surface* tmpSurface;
    SDL_Renderer* renderer;
    int counter;
public:
    Player(float x, float y, int height, int width, string image, SDL_Renderer* renderer);
    float get_x() { return x; }
    float get_y() { return y; }
    int get_height() { return height; }
    int get_width() { return width; }
    void render();
    void update(bool);
    void animate(const char* image1 = "images/hero.bmp",const char* image2 = "images/mario2.bmp");
    SDL_Rect get_rect() { return destR; }
};