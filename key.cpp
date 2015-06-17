// Ben Gunning
// Adventure-Simulator
// Key.cpp
#include"Key.h"
using namespace std;

Key::Key(Object* lock , Room* room , int x , int y , string keyName , int r , int g , int b) {
	isCollected = 0;
	match_lock = lock;
	Found_Room = room;
	Found_X = x;
	Found_Y = y;
	name = keyName;
	red = r;
	green = g;
	blue = b;
}

Key::~Key() {
}

int Key::isFinished() {
	return isCollected;
}