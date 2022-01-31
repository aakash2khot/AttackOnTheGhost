#include<bits/stdc++.h>
#include"SDL.h"
#include<SDL_image.h>
#include <SDL_ttf.h>

class Score
{
    private:
        int text_width;
        int text_height;
        SDL_Rect r;
        SDL_Texture *tx;
        SDL_Rect r1;
        SDL_Texture *tx1;
        SDL_Renderer *renderer;
        std::string text;

    public:
        Score(SDL_Renderer *renderer, std::string text);
        void render(int highscore,int score,int x,int y);
};