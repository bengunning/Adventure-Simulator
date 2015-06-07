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
using namespace std;

class Graphics {
	public:
		Graphics(int=640 , int=480 , int=32 , string=""); // Constructor (width , height , bpp , title)
		~Graphics(); // Destructor

//		SDL_Surface* loadSurface(string);
		SDL_Texture* loadTexture(string); // Load texture for later use
//		void applySurface(SDL_Surface* , SDL_Rect* , SDL_Rect*);
		void applyTexture(SDL_Texture*); // Apply texture to graphics window

		void clear(int); // Clear screen; 0 for white, 1 for black
		void update_screen(); // Update all previous changes to animate the screen
		void wait(int=0);

		void color(int , int , int , int);
		void drawRect(int , int , int , int);
		void fillRect(int , int , int , int);
		void line(int , int , int , int);
		void point(int , int);

		SDL_Texture* loadText(string , TTF_Font , SDL_Color); // "text" , TTF_OpenFont(filename , size) , SDL_Color = {r,g,b}

	private:
		SDL_Window* window;
//		SDL_Surface* screen;
		SDL_Renderer* renderer;
		int screenWidth , screenHeight , screenBPP;
		string screenTitle;
};

#endif