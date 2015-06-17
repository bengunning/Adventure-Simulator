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

	renderer = SDL_CreateRenderer(window , -1 , SDL_RENDERER_ACCELERATED);
	if (renderer == NULL) {
		throw "Failed to setup renderer";
	}
	SDL_SetRenderDrawColor(renderer , 0x0 , 0x0 , 0x0 , 0x0);

	if (!(IMG_Init(IMG_INIT_PNG) & IMG_Init(IMG_INIT_JPG))) {
		throw "Failed to initialize SDL_Image";
	}

	if (TTF_Init() == -1) {
		throw "Failed to initialize SDL_TTF";
	}

//	screen = SDL_GetWindowSurface(window);

	screenWidth = width;
	screenHeight = height;
	screenBPP = bpp;
	screenTitle = title;
}

Graphics::~Graphics() {
// Free Surface conundrum (data structure needed to store SDL_Surface pointers for eventual Free_Surface calls)
// Same thing for Destroy Texture
// TTF_CloseFont
	SDL_DestroyRenderer(renderer);
	renderer = NULL;
	SDL_DestroyWindow(window);
	window = NULL;

	TTF_Quit();
	IMG_Quit();
	SDL_Quit();
}

/*SDL_Surface* Graphics::loadSurface(string filename) {
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
}*/

SDL_Texture* Graphics::loadTexture(string filename) {
	SDL_Texture* final = NULL;
	SDL_Surface* original = IMG_Load(filename.c_str());
	if (original == NULL) {
		throw "Failed to load image";
	}
	
	final = SDL_CreateTextureFromSurface(renderer , original);
	if (final == NULL) {
		throw "Failed to make texture";
	}
	
	SDL_FreeSurface(original);
	return final;
}

/*void Graphics::applySurface(SDL_Surface* image , SDL_Rect* iRect , SDL_Rect* screenRect) {
	SDL_BlitScaled(image , iRect , screen , screenRect);
}*/

void Graphics::applyTexture(SDL_Texture* texture) {
	SDL_RenderCopy(renderer , texture , NULL , NULL);
}

void Graphics::clear(int bg) {
	if (bg) {
		SDL_SetRenderDrawColor(renderer , 0x0 , 0x0 , 0x0 , 0x0);
	} else {
		SDL_SetRenderDrawColor(renderer , 0xFF , 0xFF , 0xFF , 0xFF);
	}
	SDL_RenderClear(renderer);
}

void Graphics::update_screen() {
//	SDL_UpdateWindowSurface(window);
	SDL_RenderPresent(renderer);
}

void Graphics::wait(int time) {
	if (time < 0 | time > 60000) {
		throw "Invalid wait time";
	}
	SDL_Delay(time);
}

void Graphics::color(int red , int green , int blue , int alpha) {
	SDL_SetRenderDrawColor(renderer , red , green , blue , alpha);
}

void Graphics::drawRect(int x , int y , int wid , int len) {
	SDL_Rect rectangle = { x , y , wid , len };
	SDL_RenderDrawRect(renderer , &rectangle);
}

void Graphics::fillRect(int x , int y , int wid , int len) {
	SDL_Rect rectangle = { x , y , wid , len };
	SDL_RenderFillRect(renderer , &rectangle);
}

void Graphics::line(int x0 , int y0 , int x1 , int y1) {
	SDL_RenderDrawLine(renderer , x0 , y0 , x1 , y1);
}

void Graphics::point(int x , int y) {
	SDL_RenderDrawPoint(renderer , x , y);
}

SDL_Texture* Graphics::loadText(string text , string font_str , int size , SDL_Color color) {
	TTF_Font* font = NULL;
	font = TTF_OpenFont(font_str.c_str() , size);
	if (font == NULL) {
		throw "Failed to open font";
	}

	SDL_Surface* tempText = TTF_RenderText_Solid(font , text.c_str() , color);
	if (tempText == NULL) {
		throw "Failed to make text";
	}

	SDL_Texture* finalText = SDL_CreateTextureFromSurface(renderer , tempText);
	if (finalText == NULL) {
		throw "Failed to make text";
	}
	SDL_FreeSurface(tempText);

	return finalText;
}