// Ben Gunning
// Adventure-Simulator
// Room.cpp
#include"Room.h"
using namespace std;

Room::Room(Room* above , Room* below , Room* toLeft , Room* toRight , SDL_Color color , int hor , int ver) {
	up = above;
	down = below;
	left = toLeft;
	right = toRight;
	background = color;
	x = hor;
	y = ver;
}

Room::~Room() {
}

SDL_Color Room::getColor() {
	return background;
}

int Room::getX() {
	return x;
}

int Room::getY() {
	return y;
}