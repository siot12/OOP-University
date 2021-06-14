#pragma once
#include "Car.h"

class Dacia : public Car
{
public:
	Dacia();
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
	char* Name(const char* x);
	virtual void GetName();
};
