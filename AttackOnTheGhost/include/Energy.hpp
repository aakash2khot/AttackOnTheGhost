#include<bits/stdc++.h>
#include"SDL.h"
#include<SDL_image.h>

using namespace std;
class Energy
{
protected:
    float x, y;
    int height, width;
    const char* full = "images/lightning.bmp";
    const char* low="images/lightning.bm";
    bool energy;
    SDL_Rect destR;
    SDL_Texture* EnergyTex;
    SDL_Renderer* renderer;
public:
    Energy(float x, float y, int height, int width, SDL_Renderer* renderer);
    float get_x() { return x; }
    float get_y() { return y; }
    int get_height() { return height; }
    int get_width() { return width; }
    void render();
    void update();
    void animate();
    void changeEnergy();
    bool getEnergy();
};