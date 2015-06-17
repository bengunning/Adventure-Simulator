// Ben Gunning
// Adventure-Simulator
// Lock.cpp
#include"Lock.h"
using namespace std;

Lock::Lock(Object* key , Room* room , int x , int y , string lockName , int r, int g, int b) {
	isOpen = 0;
	match_key = key;
	Found_Room = room;
	Found_X = x;
	Found_Y = y;
	name = lockName;
	red = r;
	green = g;
	blue = b;
}

Lock::~Lock() {
}

int Key::isFinished() {
	return isOpen;
}