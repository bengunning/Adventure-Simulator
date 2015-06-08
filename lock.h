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
		Lock(Key* = NULL);
		~Lock();
		int isFinished();
	private:
		Key* match_key;
		int isOpen;
}

#endif