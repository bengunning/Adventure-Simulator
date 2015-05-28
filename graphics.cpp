// Ben Gunning
// Adventure-Simulator
// graphics.cpp
#include "Graphics.h"
using namespace std;

Graphics::Graphics(int width , int height , int bpp , string title) {
	if (SDL_Init(SDL_INIT_EVERYTHING) == -1) {
		throw "Failed to initialize SDL";
	}

	window = SDL_CreateWindow(title.c_str() , SDL_WINDOWPOS_UNDEFINED , SDL_WINDOWPOS_UNDEFINED , width , height , SDL_WINDOW_SHOWN);
	if (window == NULL) {
		throw "Failed to setup window";
	}

	if (!(IMG_Init(IMG_INIT_PNG) & IMG_Init(IMG_INIT_JPG))) {
		throw "Failed to initialize SDL_Image";
	}

	screen = SDL_GetWindowSurface(window);

	screenWidth = width;
	screenHeight = height;
	screenBPP = bpp;
	screenTitle = title;
}

Graphics::~Graphics() {
// Free Surface conundrum (data structure needed to store SDL_Surface pointers for eventual Free_Surface calls)
	SDL_DestroyWindow(window);
	window = NULL;
	SDL_Quit();
}

SDL_Surface* Graphics::loadSurface(string filename) {
	SDL_Surface* final = NULL;
	SDL_Surface* original = IMG_Load(filename.c_str());
	if (original == NULL) {
		throw "Failed to load image";
	}

	final = SDL_ConvertSurface(original , screen->format , NULL);
	if (final == NULL) {
		throw "Failed to optimize image";
	}

	SDL_FreeSurface(original);
	return final;
}

void Graphics::applySurface(SDL_Surface* image , SDL_Rect* iRect , SDL_Rect* screenRect) {
	SDL_BlitScaled(image , iRect , screen , screenRect);
}

void Graphics::update_screen() {
	SDL_UpdateWindowSurface(window);
}

void Graphics::wait(int time) {
	if (time < 0 | time > 60000) {
		throw "Invalid wait time";
	}
	SDL_Delay(time);
}