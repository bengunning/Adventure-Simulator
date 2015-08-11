// Ben Gunning
// Adventure-Simulator
// Game.h
#ifndef GAME
#define GAME
#include<iostream>
#include<string>
#include<vector>
#include"room.h"
#include"key.h"
#include"lock.h"
using namespace std;

class Game {
	public:
		Game();
		~Game();
		void createRoom();
		void createPuzzle();
	private:
		vector<Room> nodes;
		vector<Key> keys;
		vector<Lock> locks;
};

#endif