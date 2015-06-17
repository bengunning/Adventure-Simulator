// Ben Gunning
// Adventure-Simulator
// Game.h
#ifndef GAME
#define GAME
#include<iostream>
#include<string>
#include<vector>
#include<SDL.h>
#include"room.h"
#include"key.h"
#include"lock.h"
using namespace std;

class Game {
	public:
		Game();
		~Game();
		void createRoom(Room* = NULL , char = 'w' , SDL_Color = {0x0 , 0x0 , 0x0});
		void createPuzzle();
	private:
		vector<Room> nodes;
		vector<Key> keys;
		vector<Lock> locks;
};

#endif