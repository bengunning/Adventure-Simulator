// Ben Gunning
// Adventure-Simulator
// Room.h
#ifndef ROOM
#define ROOM
#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Room {
	public:
		Room(Room* = NULL , Room* = NULL , Room* = NULL , Room* = NULL , SDL_Color = {0x0 , 0x0 , 0x0});
		~Room();
		SDL_Color getColor();
	private:
		SDL_Color background;
		Room* up , down , left , right;
}

#endif