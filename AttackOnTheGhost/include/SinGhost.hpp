#include<bits/stdc++.h>
#include"SDL.h"
#include<SDL_image.h>
#include "../include/Player.hpp"
class SinGhost:public Ghost
{
public:
        SDL_Surface* tmpSurface;
        SinGhost(float x,float y,int height,int width,string image,float x_vel,SDL_Renderer *renderer,string s);
        bool update(SDL_Rect playerRect,Player *p);
        //void animate(TTF_Font* font,const char* image1="ghosts.png");
//Manan Changes:
        // void animate(vector<string>);
        int counter;
};
