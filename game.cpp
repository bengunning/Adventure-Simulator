// Ben Gunning
// Adventure-Simulator
// Game.cpp
#include"Game.h"
using namespace std;

Game::Game() {
}

Game::~Game() {
	for (vector<Room>::iterator it = nodes.begin() , it != nodes.end() , it++) {
// What to do about vectors of rooms and puzzles
	}
}

void Game::createRoom(Room* initial , char direction , SDL_Color backdrop) {
	if (initial == NULL) {
		Room next(NULL , NULL , NULL , NULL , backdrop , 0 , 0);
	} else {
		switch (direction) {
			case 'w':
				Room next(NULL , initial , NULL , NULL , backdrop , initial.getX() , initial.getY() + 1);
				break;
			case 'a':
				Room next(NULL , NULL , NULL , initial , backdrop , initial.getX() - 1 , initial.getY());
				break;
			case 's':
				Room next(initial , NULL , NULL , NULL , backdrop , initial.getX() , initial.getY() - 1)
				break;
			case 'd':
				Room next(NULL , NULL , initial , NULL , backdrop , initial.getX() + 1 , initial.getY());
				break;
			default:
				break;
		}
	}
	nodes.push_back(next);
}

void Game::createPuzzle() {
}