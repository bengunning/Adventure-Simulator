// Ben Gunning
// Adventure-Simulator
// main.cpp
#include"Graphics.h"
using namespace std;

int main(int argc , char* argv[]) {
	Graphics window(640 , 480 , 32 , "Adventure-Simulator");
	SDL_Rect* screenRect;
	SDL_Surface* background;
	SDL_Event user;
	int quit = 0;
	screenRect.x = 0;
	screenRect.y = 0;
	screenRect.w = 640;
	screenRect.h = 480;

	while (!quit) {
		while(SDL_PollEvent(&user) != 0) {
			if (user.type == SDL_QUIT) {
				quit = true;
			}
		}
		
		window.applySurface(background , NULL , &screenRect);
		window.update_screen();
	}

	SDL_FreeSurface(background);
	return 0;
}