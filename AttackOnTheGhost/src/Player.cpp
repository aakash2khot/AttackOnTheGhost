#include <bits/stdc++.h>
#include "../include/Player.hpp"


Player::Player(float x, float y, int height, int width, string image, SDL_Renderer* renderer)
{
    this->x = x; this->y = y;
    this->height = height; this->width = width;
    this->image = image;
    this->renderer = renderer;
    counter = 0;
}

void Player::render()
{
    SDL_RenderCopy(renderer, playerTex, &srcR, &destR);
    //SDL_DestroyTexture(playerTex);
        // SDL_Delay(4);
}
void Player::update(bool destroyed)
{
    //counter++;
    if ((counter/10)%4 == 0)
    {
        srcR.x = 62;
        srcR.y = 45;
        srcR.w = 47;
        srcR.h = 70;
        destR.h = height; destR.w = width;
        destR.x = x; destR.y = y;
        
        if (destroyed)
            counter += 10;;
        
    }
    else if ((counter/10)%4 == 1)
    {
        srcR.x = 127;
        srcR.y = 29;
        srcR.w =64;
        srcR.h = 83;
        destR.h = height; destR.w = width;
        destR.x = x; destR.y = y;
        counter++;
    }
    else if ((counter/10)%4 == 2)
    {
        srcR.x = 210;
        srcR.y = 30;
        srcR.w = 89;
        srcR.h = 81;
        destR.h = height; destR.w = width;
        destR.x = x; destR.y = y;
        counter++;
    }
    else if ((counter/10)%4 == 3)
    {
        srcR.x = 328;
        srcR.y = 57;
        srcR.w = 76;
        srcR.h = 57;
        destR.h = height; destR.w = width;
        destR.x = x; destR.y = y;
        counter =0;
    }
    destR.h = height; destR.w = width;
    destR.x = x; destR.y = y;

 }


void Player::animate(const char* image1,const char* image2)
{
    tmpSurface = IMG_Load(image1);


    
    playerTex = SDL_CreateTextureFromSurface(renderer, tmpSurface);


}