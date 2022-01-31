
#include<iostream>
#include<SDL.h>
#include<SDL_image.h>
#define resolutionX 1920
#define resolutionY 1080
#define heroX resolutionX / 2
#define heroY resolutionY / 2
using namespace std;

class bullet {
protected:
	int bulletX, bulletY;
	int ghostX, ghostY;
	int height, width;
	const char * image;
	SDL_Rect destR,scrR;
	SDL_Texture* BulletTex;
	SDL_Surface* tmpSurface;
	SDL_Renderer* renderer;
	float velocity;
	int counter;

public:
	bullet( int gX, int gY, int height, int width,const char * image,float velocity, SDL_Renderer* renderer);
	bool update(SDL_Rect ghost);
	void render() {
		SDL_RenderCopy(renderer, BulletTex, NULL, &destR);

	}
	void animate(const char *);
};