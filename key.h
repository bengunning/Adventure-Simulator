// Ben Gunning
// Adventure-Simulator
// Key.h
#ifndef KEY
#define KEY
#include<iostream>
#include<string>
#include"object.h"
using namespace std;

class Key : public Object {
	public:
		Key(Lock* = NULL);
		~Key();
		int isFinished();
	private:
		Lock* match_lock;
		int isCollected;
}

#endif