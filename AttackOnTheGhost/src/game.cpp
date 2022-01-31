#pragma once 
#include <iostream>
#include <fstream>
#include <SDL_mixer.h>

#include "../include/game.hpp"
#include "../include/Ghost.hpp"
#include "../include/SinGhost.hpp"
#include "../include/Energy.hpp"
#include "../include/Score.hpp"
#include"../include/startScreen.hpp"
#include"../include/SDL2SoundEffects.hpp"
//#include "../include/bullet.hpp"

#define ghostHeight 100
#define ghostWidth 100
#define resolutionX 1920
#define resolutionY 1080
#define heroX resolutionX / 2
#define heroY resolutionY / 2
int ghostSpeed = 1.5;

SDL_Texture *playerTex;
SDL_Rect destR;
vector<Ghost *> ghosts;
vector<Energy *> bolts;
Player *p;
Score *s;
// bullet *b;
startScreen* Name;
startScreen* startButton;
startScreen* highScore;
startScreen* quit;
startScreen* yourScore;
startScreen* theEnd;
SDL_Texture *backgroundTexture;
SDL_Surface *background = IMG_Load("images/bg.bmp");
SDL_Surface *text_surf;
SDL_Texture *text;
SDL_Rect dest;
SDL_Surface *surface;
SDL_Texture *texture;
int stringCounter = 0;


//sounds
SDL2SoundEffects se;
vector<Mix_Chunk*> soundArray;




vector<string> all;
struct position
{
    int X;
    int Y;
};
vector<position> posX;

 
void Game::ghostHandler()
{
    position leftCorner = { 100, 100 };
    posX.push_back(leftCorner);
    position rightCorner = { resolutionX - 100, 100 };
    posX.push_back(rightCorner);
    position topLeftCorner = { 100, resolutionY - 100 };
    posX.push_back(topLeftCorner);

    position topRightCorner = { resolutionX - 100, resolutionY - 100 };
    posX.push_back(topRightCorner);

    position midLeft = { 0,heroY };
    posX.push_back(midLeft);

    position midRight = { resolutionX,heroY };
    posX.push_back(midRight);

    all = scheck->produce_string(1000);
    Ghost *g1 = new SinGhost(0, 0, ghostHeight, ghostWidth, "images/ghost1.bmp", ghostSpeed, renderer, all[stringCounter++]);
    // SDL_Delay(1000);
    Ghost *g2 = new SinGhost(0, heroY, ghostHeight, ghostWidth, "images/ghost1.bmp", ghostSpeed, renderer, all[stringCounter++]);
    // SDL_Delay(1000);
    Ghost *g3 = new SinGhost(resolutionX - ghostWidth, 0, ghostHeight, ghostWidth, "images/ghost1.bmp", ghostSpeed, renderer, all[stringCounter++]);
    Ghost *g4 = new SinGhost(400, 400, ghostHeight, ghostWidth, "images/ghost1.bmp", ghostSpeed, renderer, all[stringCounter++]);
    Ghost *g5 = new SinGhost(800,800, ghostHeight, ghostWidth, "images/ghost1.bmp", ghostSpeed, renderer, all[stringCounter++]);

    Energy *e1 = new Energy(70, 70, 40, 40, renderer);
    Energy *e2 = new Energy(120, 70, 40, 40, renderer);
    Energy *e3 = new Energy(170, 70, 40, 40, renderer);
    Energy *e4 = new Energy(220, 70, 40, 40, renderer);
    Energy *e5 = new Energy(270, 70, 40, 40, renderer);
    bolts.push_back(e1);
    bolts.push_back(e2);
    bolts.push_back(e3);
    bolts.push_back(e4);
    bolts.push_back(e5);
    ghosts.push_back(g1);
    ghosts.push_back(g2);
    ghosts.push_back(g3);
    ghosts.push_back(g4);
    ghosts.push_back(g5);
    // b = new bullet(heroX,heroY,60,60,"images/lightning.bmp", renderer);
    // b->fire(0,0);
    // b->animate();

    p = new Player(heroX, heroY, 120, 120, "images/hero.bmp", renderer);
    p->update(false);
    p->animate();

    for (int i = 0; i < bolts.size(); i++)
        bolts[i]->update();
}

Game::Game(const char *title, int positionX, int positionY, int width, int height, bool fullscreen,int sco)
{   
    highscore=sco;
    score = 0;
    power = 5;

    windowWidth = width;
    windowHeight = height;
     
    int flag = 0;
    // input = "";
    if (fullscreen)
    {
        flag = SDL_WINDOW_FULLSCREEN;
    }

    if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
    {
        cout << "SDL is initialised\n";
        window = SDL_CreateWindow(title, positionX, positionY, width, height, SDL_WINDOW_FULLSCREEN);
        renderer = SDL_CreateRenderer(window, -1, 0);
        SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255);

        // SDL_Texture *texture;
        backgroundTexture = SDL_CreateTextureFromSurface(renderer, background);
        isRunning = true;
    }

    else
    {
        isRunning = false;
    }

    if (TTF_Init() == 0)
    {
        cout << "TTF inialized" << endl;
        font = TTF_OpenFont("font/OpenSans-Semibold.ttf", 24);

        // FILE* f = fopen("font/OpenSans-Italic.ttf","r");

        if (!font)
        {
            cout << "Error in font" << endl;
        }
        isRunning = true;
    }
    else
    {
        isRunning = false;
    }

    input = "";
    scheck = new String_check(3);
    length = 3;
    s = new Score(renderer, "Score: ");
    Name = new startScreen(renderer, "Attack On The Ghost");
    theEnd = new startScreen(renderer, "THE END");
    
    startButton = new startScreen(renderer, "Start");
    quit = new startScreen(renderer, "Quit");
    
   
    highScore = new startScreen(renderer, "HighScore: " + to_string(Game::highscore));

    soundArray.push_back(Mix_LoadWAV("Sound/Background_sound.mp3"));
    soundArray.push_back(Mix_LoadWAV("Sound/bullet_hit.mp3"));
    soundArray.push_back(Mix_LoadWAV("Sound/bullet_fire.wav"));

    Mix_PlayChannel(-1, soundArray[0], 500);

    ghostHandler();
}

Game::~Game(){
    // MyFile.close();
};

void Game::render()

{
    SDL_RenderClear(renderer);
    if (power == 0)
    {
        SDL_FreeSurface(background);
        background = IMG_Load("images/bg1.bmp");
        SDL_DestroyTexture(backgroundTexture);
        backgroundTexture = SDL_CreateTextureFromSurface(renderer, background);
        SDL_RenderCopy(renderer, backgroundTexture, NULL, NULL);
        yourScore = new startScreen(renderer, "Your Score: " + to_string(Game::score));
        highScore = new startScreen(renderer, "HighScore: " + to_string(Game::highscore));
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
        highScore->render(heroX, 500);
        yourScore->render(heroX, 300);
        theEnd->render(heroX, 100);
        SDL_RenderPresent(renderer);

    }
    else if (maingame==0 &&power!=0) {
        SDL_FreeSurface(background);
        background = IMG_Load("images/bg1.bmp");
        SDL_DestroyTexture(backgroundTexture);
        backgroundTexture = SDL_CreateTextureFromSurface(renderer, background);
        SDL_RenderCopy(renderer, backgroundTexture, NULL, NULL);

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
        Name->render(heroX , 100);
        startButton->render(heroX, 300);
        highScore->render(heroX, 500);
        quit->render(heroX, 750);
        SDL_RenderPresent(renderer);
    }

    else if (maingame==1 && power != 0)
    {
        SDL_FreeSurface(background);
        background = IMG_Load("images/bg.bmp");
        SDL_DestroyTexture(backgroundTexture);
        backgroundTexture = SDL_CreateTextureFromSurface(renderer, background);
        SDL_RenderCopy(renderer, backgroundTexture, NULL, NULL);
        // b->render();
        p->render();
        s->render(Game::highscore, score, 1700, 80);
        SDL_Color sc = {255, 255, 255, 0};
        for (int i = 0; i < ghosts.size(); i++)
        {
            if (ghosts[i] != NULL)
            {
                ghosts[i]->render();
                surface = TTF_RenderText_Solid(font, ghosts[i]->getstring(), sc);
                SDL_Rect dest;
                dest.x = ghosts[i]->get_x();
                dest.y = ghosts[i]->get_y() - ghosts[i]->get_height() / 6 - 10;
                dest.h = surface->h;
                dest.w = surface->w;
                texture = SDL_CreateTextureFromSurface(renderer, surface);
                SDL_RenderCopy(renderer, texture, NULL, &dest);
                SDL_DestroyTexture(texture);
                SDL_FreeSurface(surface);
            }
        }
        for (int i = 0; i < bolts.size(); i++)
        {
            if (bolts[i] != NULL)
            {
                bolts[i]->render();
            }
        }

        if (input.size())
        {
            text_surf = TTF_RenderText_Solid(font, input.c_str(), sc);
            text = SDL_CreateTextureFromSurface(renderer, text_surf);

            dest.x = 0;
            dest.y = windowHeight - 30;
            dest.w = text_surf->w;
            dest.h = text_surf->h;
            SDL_RenderCopy(renderer, text, NULL, &dest);

            SDL_DestroyTexture(text);
            SDL_FreeSurface(text_surf);
        }
        SDL_RenderPresent(renderer);
    }
   
    
}

void Game::eventHandler()
{
    SDL_Event event;
    SDL_PollEvent(&event);
    int x, y, k1, k2, m1, m2;

    switch (event.type)
    {
    case SDL_MOUSEBUTTONDOWN:
        //int x, y;
        SDL_GetMouseState(&x, &y);
        k1 = (resolutionX - quit->getWidth()) / 2;
        k2 = (resolutionX + quit->getWidth()) / 2;
        if ((x >= k1) && (x <= k2) && (y >= 750) && (y <= 750 + quit->getHeight()))
            isRunning = false;

        m1 = (resolutionX - startButton->getWidth()) / 2;
        m2 = (resolutionX + startButton->getWidth()) / 2;
        if ((x >= m1) && (x <= m2) && (y >= 300) && (y <= 300 + startButton->getHeight())) {
            if(!maingame)
                maingame = 1;
      
        }
        break;

    case SDL_QUIT:
        
        isRunning = false;

        break;

    case SDL_TEXTINPUT:
        input += event.text.text;
        break;

        // g1 g2 g3 -> string type all three boolean
    case SDL_KEYDOWN:
        if (event.key.keysym.sym == SDLK_ESCAPE)
        {
         
            isRunning = false;
            break;
        }
        if (event.key.keysym.sym == SDLK_BACKSPACE)
        {
            if (input.size() > 0)
            {
                input.pop_back();
            }
        }
        if (event.key.keysym.sym == SDLK_RETURN)
        {
            // Make a array of current ghosts present
            for (int i = 0; i < ghosts.size(); i++)
            {
                if (ghosts[i] != NULL)
                {
                    if (ghosts[i]->getstring() == input)
                    {

                        ghosts[i]->Destroyed();
                        p->animate();
                       
                        score += 10;
                        
                    }
                }
            }

            input = "";
        }
        break;

    default:
        break;
    }
}

bool Game::running()
{
    return isRunning;
}

void Game::update()
{
    if (maingame) {
        bool bulletPresent = false;
        for (int i = 0; i < ghosts.size(); i++)
        {
            int x = heroX, y = heroY;
            if (ghosts[i] != NULL)
            {
                int flag = 0;
                bool bulletHit = false;
                bool ghostHit = ghosts[i]->update(p->get_rect(),p);
                bool ghostDest = ghosts[i]->getDestroyed();
               
                if (ghostDest)
                {
                    bulletHit = ghosts[i]->ghostBullet();
                    ghosts[i]->animate(font, "images/ghosts.bmp");
              
                }
                if (bulletHit == false && ghostDest) {
                    bulletPresent=true;
                }
                if (!(ghosts[i]->getDestroyed() || ghostHit))
                {
                    ghosts[i]->animate(font, "images/ghosts.bmp");
                }
                else if (bulletHit)
                {
                    Mix_PlayChannel(-1, soundArray[1], 0);
                    ghosts[i]->destroyBullet();
                    delete(ghosts[i]);
                    ghosts[i] = NULL;
                    ghosts.erase(ghosts.begin() + i);
                    int k = rand() % posX.size();
                    if (heroX < posX[k].X) {
                        ghosts.push_back(new SinGhost(posX[k].X, posX[k].Y, ghostHeight, ghostWidth, "images/ghost1.bmp", ghostSpeed, renderer, all[stringCounter++]));

                    }
                    ghosts.push_back(new SinGhost(posX[k].X, posX[k].Y, ghostHeight, ghostWidth, "images/ghost1.bmp", ghostSpeed, renderer, all[stringCounter++]));
                    if (score > 50)
                        ghostSpeed = 3;
                    if (score > 100)
                        ghostSpeed = 3.5;
                    if (score > 200)
                        ghostSpeed = 4.5;
                }
                else if (ghostHit)
                {
                    power--;
                   
                    for (int i = bolts.size() - 1; i >= 0; i--)
                    {
                        if (bolts[i]->getEnergy())
                        {
                            bolts[i]->changeEnergy();
                            break;
                        }
                    }
                    delete (ghosts[i]);
                    ghosts[i] = NULL;
                    ghosts.erase(ghosts.begin() + i);
                    int k = rand() % posX.size();
                    ghosts.push_back(new SinGhost(posX[k].X, posX[k].Y, ghostHeight, ghostWidth, "images/ghost1.bmp", ghostSpeed, renderer, all[stringCounter++]));

                }
                if (bulletPresent) {
                    //p->update(true);
                    bulletPresent = false;
                }
                else {
                    //p->update(false);

                }
                p->update(false);
            }
        }
        if (ghosts.size() == 0)
        {
            isRunning = false;
        }
        for (int i = 0; i < bolts.size(); i++)
        {
            bolts[i]->animate();
        }
    }
}