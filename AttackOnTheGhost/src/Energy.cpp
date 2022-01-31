#include <bits/stdc++.h>
#include "../include/Energy.hpp"

Energy::Energy(float x, float y, int height, int width, SDL_Renderer* renderer)
{
    this->x = x; this->y = y;
    this->height = height; this->width = width;
    this->energy = true;
    this->renderer = renderer;
}

void Energy::render()
{
    SDL_RenderCopy(renderer, EnergyTex, NULL, &destR);
    SDL_DestroyTexture(EnergyTex);
        // SDL_Delay(4);
}
void Energy::update()
{
    destR.h = height; destR.w = width;
    destR.x = x; destR.y = y;
}

void Energy::animate()
{
    SDL_Surface* tmpSurface;
    if(energy==true)
        tmpSurface = SDL_LoadBMP(full);
    else
        tmpSurface = SDL_LoadBMP(low);    

    EnergyTex = SDL_CreateTextureFromSurface(renderer, tmpSurface);
    SDL_FreeSurface(tmpSurface);

}

void Energy::changeEnergy()
{
   energy=false;
}

bool Energy::getEnergy()
{
    return energy;
}
