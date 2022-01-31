#include "../include/bullet2.hpp"
#define resolutionX 1920
#define resolutionY 1080
#define heroX resolutionX / 2
#define heroY resolutionY / 2

bullet::bullet(int gX, int gY, int height, int width, const char * image,float velocity ,SDL_Renderer* renderer) {
	this->bulletX = heroX;
	this->bulletY = heroY;
	this->ghostX = gX;
	this->ghostY = gY;
	this->image = image;
	this->height = height;
	this->width = width;
	this->renderer = renderer;
	this->velocity = velocity;
	counter = 0;
	tmpSurface = SDL_LoadBMP(image);
	BulletTex = SDL_CreateTextureFromSurface(renderer, tmpSurface);
	
}

bool bullet::update(SDL_Rect gRect) {
	
	if (ghostX > heroX) {
		bulletX += velocity;
		bulletY =ghostY+ (float(ghostY - heroY) / (ghostX - heroX)) * (bulletX-ghostX);
	}
	else if (ghostX < heroX) {
		bulletX -= velocity;
		bulletY =ghostY + (float(ghostY - heroY) / (ghostX - heroX)) * (bulletX-ghostX);
	}
	else {
		bulletY += velocity;
	}
	destR.h = height; destR.w = width;
	destR.x = bulletX; destR.y = bulletY;
	if (SDL_HasIntersection(&destR, &gRect))	return true;
	else return false;

}

void bullet::animate(const char *image1) {
	tmpSurface = SDL_LoadBMP(image1);
	BulletTex = SDL_CreateTextureFromSurface(renderer, tmpSurface);
	SDL_FreeSurface(tmpSurface);

}