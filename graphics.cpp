// Ben Gunning
// Adventure-Simulator
// graphics.cpp
#include "Graphics.h"
using namespace std;

Graphics::Graphics(int width , int height , int bpp , string title) {
	if (SDL_Init(SDL_INIT_EVERYTHING) == -1) {
		throw "Failed to initialize";
	}

	screen = SDL_SetVideoMode(width , height , bpp , SDL_SWSURFACE);
	if (screen == NULL) {
		throw "Failed to setup screen";
	}

	SDL_WM_SetCaption(title , NULL);
	screenWidth = width;
	screenHeight = height;
	screenBPP = bpp;
	screenTitle = title;
}

Graphics::~Graphics() {
	SDL_Quit();
}

SDL_Surface* Graphics::load_image(string filename) {
	SDL_Surface* loadedImage = NULL;
	SDL_Surface* optimizedImage = NULL;

	loadedImage = SDL_LoadBMP(filename.c_str());

	if (loadedImage != NULL) {
		optimizedImage = SDL_DisplayFormat(loadedImage);
		SDL_FreeSurface(loadedImage);
	}

	return optimizedImage;
}

void Graphics::apply_surface(int x , int y , SDL_Surface* source , SDL_Surface* destination) {
	SDL_rect offset;
	offset.x = x;
	offset.y = y;

	SDL_BlitSurface(source , NULL , destination , &offset);
}

void Graphics::update_screen() {
	if(SDL_Flip(screen) == -1) {
		throw "Failed to update screen";
	}
}

void Graphics::wait(int time) {
	if (time < 0 | time > 60000) {
		throw "Invalid wait time";
	}
	SDL_Delay(time);
}