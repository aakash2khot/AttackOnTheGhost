#include"../include/startScreen.hpp"

startScreen::startScreen(SDL_Renderer* renderer,std::string text) {
	this->renderer = renderer;
	this->text = text;
}


void startScreen::render(int x,int y) {
	SDL_Surface* surface;
	TTF_Font* gFont1 = TTF_OpenFont("font/Amatic-Bold.ttf", 90);
	SDL_Color textColor1 = { 0, 0, 0, 0 };
	const char* st = text.c_str();
	surface = TTF_RenderText_Solid(gFont1, st, textColor1);
	tx = SDL_CreateTextureFromSurface(renderer, surface);
	text_Width = surface->w;
	text_Height = surface->h;
	SDL_FreeSurface(surface);
	r->x = x-text_Width/2;
	r->y = y;
	r->w = text_Width;
	r->h = text_Height;
	SDL_RenderCopy(renderer, tx, NULL, r);
	TTF_CloseFont(gFont1);
	SDL_DestroyTexture(tx);
}