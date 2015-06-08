// Ben Gunning
// Adventure-Simulator
// Room.cpp
#include"Room.h"
using namespace std;

Room::Room(Room* above , Room* below , Room* toLeft , Room* toRight , SDL_Color color) {
	up = above;
	down = below;
	left = toLeft;
	right = toRight;
	background = color;
}

Room::~Room() {
}

SDL_Color Room::getColor() {
	return background;
}