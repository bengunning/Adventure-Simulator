// Ben Gunning
// Adventure-Simulator
// main.cpp
#include"Graphics.h"
using namespace std;

int main(int argc , char* argv[]) {
	Graphics window(640 , 480 , 32 , "Adventure-Simulator");
	SDL_Event user;
	int quit = 0;

	while (!quit) {
		while(SDL_PollEvent(&user) != 0) {
			if (user.type == SDL_QUIT) {
				quit = true;
			}
		}
		
		window.clear(1);



		window.update_screen();
	}

	return 0;
}