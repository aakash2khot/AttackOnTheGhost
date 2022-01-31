#include<bits/stdc++.h>
#include"SDL.h"
#include<SDL_image.h>
#include <SDL_ttf.h>
#include"../include/bullet2.hpp"
#include "../include/Player.hpp"
using namespace std;
class Ghost
{
    protected:
        bullet *Bullet=NULL;
        float x,y,initialisedX,initialisedY;
        int height,width;
        string image;
        float x_vel;
        SDL_Surface *tmpSurface;
        SDL_Rect destR,srcR;
        SDL_Texture* playerTex;
        SDL_Renderer *renderer;
        string s;
        SDL_Surface* text;
        SDL_Texture* text_texture;
        SDL_Rect dest1;
        bool destroyed = false;
        int counter;

    public:
        Ghost(float x,float y,int height,int width,string image,float x_vel,SDL_Renderer *renderer,string s_);
        float get_x(){ return x; }
        float get_y(){ return y; }
        int get_height(){ return height; }
        int get_width(){ return width; }
        float get_xvel(){ return x_vel; }

        int getInitialisedX(){ return initialisedX; }
        void render();
        virtual bool update(SDL_Rect playerRect,Player *p);
        void Destroyed(){destroyed =true;}
        bool getDestroyed(){return destroyed;}
        void animate(TTF_Font* font,const char* image1="images/ghosts.bmp");
        const char* getstring();
        bool ghostBullet();
        void destroyBullet();
       
        // virtual void animate(vector<string> hehe);
};