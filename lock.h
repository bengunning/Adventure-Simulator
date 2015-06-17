// Ben Gunning
// Adventure-Simulator
// Lock.h
#ifndef LOCK
#define LOCK
#include<iostream>
#include<string>
#include"object.h"
using namespace std;

class Lock : public Object {
	public:
		Lock(Object* = NULL , Room* = NULL , int = 320 , int = 240 , string = "" , int = 0 , int = 0 , int = 0);
		~Lock();
		int isFinished();
	private:
		Object* match_key;
		int isOpen;
};

#endif