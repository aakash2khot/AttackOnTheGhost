#pragma once
#include "SDL.h"
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <stdio.h>
#include <string>
#include <cmath>

class startScreen {
private:
	int text_Width;
	int text_Height;
	SDL_Rect* r = new SDL_Rect();
	SDL_Texture* tx;
	SDL_Renderer* renderer;
	std::string text;

public:
public:
	startScreen(SDL_Renderer* renderer, std::string text);
	void render(int x, int y);

	int getWidth() { return text_Width; }
	int getHeight() { return text_Height; }
};