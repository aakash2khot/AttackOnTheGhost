#include <bits/stdc++.h>
#include "../include/Ghost.hpp"
#include "../include/SinGhost.hpp"
#include"SDL_mixer.h"
#include <cmath>
#define resolutionX 1920
#define resolutionY 1080
#define heroX resolutionX/2
#define heroY resolutionY/2

SinGhost::SinGhost(float x, float y,int height,int width,string image,float x_vel,SDL_Renderer *renderer,string s):Ghost(x,y,height,width,image,x_vel,renderer,s)
{
    //counter=0;
    // SDL_RenderClear(renderer);
    //Ghost::render();
    //SDL_RenderPresent(renderer);
    // SDL_Delay(1000);
}

bool SinGhost::update(SDL_Rect playerRect, Player* p)
{
    if (destroyed == false) {
        counter += 5;
        if (initialisedX < resolutionX / 2)
        {
            x += x_vel;
            y = initialisedY + ((initialisedY - resolutionY / 2) / (initialisedX - resolutionX / 2)) * (x - initialisedX) + 100 * sin(2 * (2 * acos(0.0)) * (x) / 100);
        }
        else
        {
            x -= x_vel;
            y = initialisedY + ((initialisedY - resolutionY / 2) / (initialisedX - resolutionX / 2)) * (x - initialisedX) + 100 * sin(2 * (2 * acos(0.0)) * (x) / 100);
        }

        destR.h = height; destR.w = width;
        destR.x = x; destR.y = y;
    }

    int checker = counter / 10;
    int sprites = 9;

    if ((checker) % sprites == 0)
    {

        if (heroX > x) {
            srcR.x = 4;
            srcR.y = 90;
            srcR.w = 52;
            srcR.h = 70;
        }
        else {
            srcR.x = 0;
            srcR.y = 109;
            srcR.w = 68;
            srcR.h = 56;
        }
    }
    else if ((checker) % sprites == 1)
    {
        if (heroX > x)
        {
            srcR.x = 108;
            srcR.y = 90;
            srcR.w = 52;
            srcR.h = 71;
        }
    else {
        srcR.x = 100;
        srcR.y = 138;
        srcR.w = 68;
        srcR.h = 49;
    }
  
       
    }
    else  if ((checker) % sprites == 2)
    {
        if (heroX > x) {
            srcR.x = 211;
            srcR.y = 85;
            srcR.w = 44;
            srcR.h = 72;
        }
        else {
            srcR.x = 212;
            srcR.y = 132;
            srcR.w = 64;
            srcR.h = 46;
        }
        

    }

    else if (checker%sprites ==3) {
        if (heroX > x) {
            srcR.x = 316;
            srcR.y = 91;
            srcR.w = 52;
            srcR.h = 72;
        }
        else {
            srcR.x = 312;
            srcR.y = 113;
            srcR.w = 66;
            srcR.h = 47;
        }
    }
    else if (checker%sprites==4) {
        if (heroX > x) {
            srcR.x = 418;
            srcR.y = 100;
            srcR.w = 67;
            srcR.h = 79;
        }
        else {
            srcR.x = 405;
            srcR.y = 102;
            srcR.w = 67;
            srcR.h = 61;
        }
    }
    else if(checker %sprites==5){
        if (heroX > x) {

            srcR.x = 516;
            srcR.y = 111;
            srcR.w = 68;
            srcR.h = 49;
        }
        else {
            srcR.x = 525;
            srcR.y = 93;
            srcR.w = 55;
            srcR.h = 72;
        }
        

    }
    else if (checker % sprites == 6) {
   
        if (heroX > x) {
            srcR.x = 617;
            srcR.y = 127;
            srcR.w = 72;
            srcR.h = 56;
        }
        else {
            srcR.x = 140;
            srcR.y = 96;
            srcR.w = 42;
            srcR.h = 70;
        }
        

    }
    else if (checker % sprites == 7) {

        if (heroX > x) {
            srcR.x = 722;
            srcR.y = 132;
            srcR.w = 72;
            srcR.h = 55;
        }
        else {
            srcR.x = 735;
            srcR.y = 88;
            srcR.w = 47;
            srcR.h = 73;
        }


    }
    else if (checker % sprites == 8) {
        if (heroX > x) {
            srcR.x = 825;
            srcR.y = 104;
            srcR.w = 67;
            srcR.h = 62;
        }
        else {
            srcR.x = 840;
            srcR.y = 94;
            srcR.w = 52;
            srcR.h = 65;
        }
    }
    

    if (destroyed && (Bullet == NULL)) {
        Mix_Chunk* chunk = Mix_LoadWAV("Sound/bullet_fire.wav");
        Mix_PlayChannel(-1, chunk, 0);
        Bullet = new bullet(destR.x, destR.y, 80, 80, "images/fire.bmp", 40, renderer);
        p->update(destroyed);
    }
   
    if(SDL_HasIntersection(&destR,&playerRect)) return true;
    return false;
}
