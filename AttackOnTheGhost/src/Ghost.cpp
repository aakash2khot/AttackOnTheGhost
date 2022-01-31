#include <bits/stdc++.h>
#include "../include/Ghost.hpp"
#define resolutionX 1920
#define resolutionY 1080
#define heroX resolutionX / 2
#define heroY resolutionY / 2

Ghost::Ghost(float x, float y, int height, int width, string image, float x_vel, SDL_Renderer *renderer, string s_)
{
    this->x = x;
    this->y = y;
    this->initialisedX = x;
    this->initialisedY = y;
    this->height = height;
    this->width = width;
    this->image = image;
    this->x_vel = x_vel;
    this->renderer = renderer;
    s = s_;
    counter = 0;

}

void Ghost::render()
{
    if (destroyed && Bullet != NULL) {
        Bullet->render();
    }
    SDL_RenderCopy(renderer, playerTex, &srcR, &destR);
    SDL_DestroyTexture(playerTex);
    // SDL_RenderCopy(renderer, this->text_texture, NULL, &dest1);
}

bool Ghost::update(SDL_Rect playerRect,Player *p)
{
    counter++;
    x += x_vel;
    y++;
    int checker = counter / 9;
    if((checker)%4 ==0)
    {
        srcR.x = 3;
        srcR.y = 3;
        srcR.w = 218;
        srcR.h = 252;
    }
    else if((checker)%4 ==1)
    {
         srcR.x = 238;
         srcR.y = 3;
         srcR.w = 243;
        srcR.h = 250;
    }
    else  if((checker)%4 ==2)
    {
         srcR.x = 3;
         srcR.y = 245;
         srcR.w = 233;
         srcR.h = 227;
    }
    else if((checker)%4 ==3)
    {
         srcR.x = 246;
         srcR.y = 240;
         srcR.w = 209;
        srcR.h = 247;
    }
    destR.h = height;
    destR.w = width;
    destR.x = x;
    destR.y = y;

    // cout<<destR.x<<" "<<destR.y<<endl;

    // cout<<text->w<<" "<<text->h<<endl;


    if (abs(heroX - x) < 60)
        return true;
    else
        return false;
}

void Ghost::animate(TTF_Font *font, const char *image1)
{
    tmpSurface;

    if(heroX< x)
        tmpSurface = SDL_LoadBMP("images/ghost3_mirror.bmp");
    else {
       tmpSurface = SDL_LoadBMP("images/ghost3.bmp");
    }
    

    // SDL_Color sc = {0, 0, 0, 0};

    // text = TTF_RenderText_Solid(font,s.c_str() , sc);
    // text_texture = SDL_CreateTextureFromSurface(renderer, text);

    

    playerTex = SDL_CreateTextureFromSurface(renderer, tmpSurface);
    SDL_FreeSurface(tmpSurface);
    //SDL_DestroyTexture(playerTex);

    // SDL_FreeSurface(text);

    //SDL_Delay(1);
}

const char* Ghost::getstring()
{
    return s.c_str();
}

bool Ghost::ghostBullet()
{
    if(Bullet)
    return Bullet->update(destR);
}

void Ghost::destroyBullet() {
    delete(Bullet);
    Bullet = NULL;
}


