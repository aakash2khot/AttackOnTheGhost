#include<bits/stdc++.h>
using namespace std;
#include "../include/Score.hpp"


Score::Score(SDL_Renderer *renderer, std::string text)
{
    TTF_Init();
    this->text = text;
    this->renderer = renderer;
}

void Score::render(int highscore,int score,int x, int y)
{

    SDL_Surface *surface,*surface1;
    SDL_Color textColor = {255, 255, 255, 0};
    SDL_Color bColor = {172, 66, 0, 0};
    TTF_Font *font = TTF_OpenFont("font/OpenSans-Semibold.ttf", 32);
    std::string s = std::to_string(score);
    std::string sr = "";
    sr = text + " " + s;
    const char* pchar = (sr).c_str();

    std::string s1 = std::to_string(highscore);
    std::string high = "HighScore: ";
    high += s1;
    const char* pchar1 = (high).c_str();


    surface = TTF_RenderText_Solid(font, pchar, textColor);
    tx = SDL_CreateTextureFromSurface(renderer, surface);
    surface1 = TTF_RenderText_Solid(font, pchar1, textColor);
    tx1 = SDL_CreateTextureFromSurface(renderer, surface1);

   
    
        text_width = surface->w;
        text_height =surface->h;
        SDL_FreeSurface(surface);
       


        r.x = x;r1.x = x-900;
        r.y = y;r1.y = y;
        r.w = text_width;
        r.h = text_height;
        text_width = surface1->w;
        text_height = surface1->h;
        r1.w = text_width;
        r1.h = text_height;
        SDL_FreeSurface(surface1);
    SDL_RenderCopy(renderer, tx, NULL, &r);
    SDL_RenderCopy(renderer, tx1, NULL, &r1);
    TTF_CloseFont(font);
    SDL_DestroyTexture(tx);
    SDL_DestroyTexture(tx1);
}
