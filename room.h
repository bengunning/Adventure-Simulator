// Ben Gunning
// Adventure-Simulator
// Room.h
#ifndef ROOM
#define ROOM
#include<iostream>
#include<string>
#include<vector>
#include<SDL.h>
using namespace std;

class Room {
	public:
		Room(Room* = NULL , Room* = NULL , Room* = NULL , Room* = NULL , SDL_Color = {0x0 , 0x0 , 0x0} , int x = 0 , int y = 0);
		~Room();
		SDL_Color getColor();
		int getX();
		int getY();
	private:
		SDL_Color background;
		Room* up;
		Room* down;
		Room* left;
		Room* right;
		int x , y;
};

#endif