// Ben Gunning
// Adventure-Simulator
// graphics.h
#ifndef GRAPHICS
#define GRAPHICS
#include<iostream>
#include<string>
#include<SDL.h>
#include<SDL_image.h>
#include<SDL_ttf.h>
#include<SDL_mixer.h>
using namespace std;

class Graphics {
	public:
		Graphics(int=640 , int=480 , int=32 , string="");
		~Graphics();
		SDL_Surface* loadSurface(string);
		void applySurface(SDL_Surface* , SDL_Rect* , SDL_Rect*)
		void update_screen();
		void wait(int=0);
	private:
		SDL_Window* window;
		SDL_Surface* screen;
		int screenWidth , screenHeight , screenBPP;
		string screenTitle;
};

#endif