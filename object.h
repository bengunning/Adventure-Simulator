// Ben Gunning
// Adventure-Simulator
// Object.h
#ifndef OBJECT
#define OBJECT
#include<iostream>
#include<string>
using namespace std;

class Object {
	public:
		Object();
		~Object();
		virtual int isFinished() = 0;
	private:
		Room* Found_Room;
		int Found_X , Found_Y;
}

#endif