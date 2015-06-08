// Ben Gunning
// Adventure-Simulator
// Key.cpp
#include"Key.h"
using namespace std;

Key::Key(Lock* lock) {
	isCollected = 0;
	match_lock = lock;
}

Key::~Key() {
}

int Key::isFinished() {
	return isCollected;
}