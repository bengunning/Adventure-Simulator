// Ben Gunning
// Adventure-Simulator
// graphics.h
#ifndef GRAPHICS
#define GRAPHICS
#include<iostream>
#include<string>
#include"SDL/SDL.h"
using namespace std;

class Graphics {
	public:
		Graphics(int=640 , int=480 , int=32 , string='');
		~Graphics();
		SDL_Surface* load_image(string);
		void apply_surface(int , int , SDL_Surface* , SDL_Surface*);
		void update_screen();
		void wait(int=0);
	private:
		SDL_Surface* screen;
		int screenWidth , screenHeight , screenBPP;
		string screenTitle;
};

#endif