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
		Key(Object* = NULL , Room* = NULL , int = 320 , int = 240 , string = "" , int = 0 , int = 0 , int = 0);
		~Key();
		int isFinished();
	private:
		Object* match_lock;
		int isCollected;
};

#endif