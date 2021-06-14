#pragma once
#include "Car.h"
class Mazda:public Car
{
public:
	Mazda();
	void Set();
	void Setfuelcap(int value);
	int Getfuelcap();
	void Setfuelconsmp(int value);
	int Getfuelconsmp();
	void Setavgspeedrain(int value);
	int Getavgspeedrain();
	void Setavgspeedsnow(int value);
	int Getavgspeedsnow();
	void Setavgspeedsunny(int value);
	int Getavgspeedsunny();
	char* Name(const char*);
	virtual void GetName();
};