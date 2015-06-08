// Ben Gunning
// Adventure-Simulator
// Lock.cpp
#include"Lock.h"
using namespace std;

Lock::Lock(Key* key) {
	isOpen = 0;
	match_key = key;
}

Lock::~Lock() {
}

int Key::isFinished() {
	return isOpen;
}