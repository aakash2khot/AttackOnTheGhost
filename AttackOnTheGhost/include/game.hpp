#include <bits/stdc++.h>
#include "SDL.h"
#include <SDL_image.h>
#include <SDL_ttf.h>
#include "String_check.hpp"
#include"SDL_mixer.h"
#undef main
using namespace std;

class Game
{
private:
    bool isRunning;
    SDL_Window *window;
    SDL_Renderer *renderer;
    int countX, countY, countZ;
    int windowWidth, windowHeight;
    String_check *scheck;
    int maingame = 0;
    bool death = false;
    TTF_Font* font;
    string input;
    int length;
   
    // vector<SinGhost*> ghost_alive;

public:
    int score;
    int highscore;
    int power;
    void ghostHandler();
    Game(const char *title, int positionX, int positionY, int width, int height, bool fullscreen,int sc);

    void init(const char *title, int positionX, int positionY, int width, int height, bool fullscreen);

    void update();
    void render();
    void clean();
    void eventHandler();
    bool running();
    void hehe();

    ~Game();
};