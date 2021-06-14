#pragma once
#include <string.h>
#include <iostream>
using namespace std;
class Car
{
protected:
	int fuelcap;
	int fuelconsmp;
	int avgspeedrain;
	int avgspeedsnow;
	int avgspeedsunny;
	char name[10];
public:
	virtual void Set() = 0;
	virtual void Setfuelcap(int value)
	{
		fuelcap = value;
	}
	virtual int Getfuelcap()
	{
		return fuelcap;
	}
	virtual void Setfuelconsmp(int value)
	{
		fuelconsmp = value;
	}
	virtual int Getfuelconsmp()
	{
		return fuelconsmp;

	}
	virtual void Setavgspeedrain(int value)
	{
		avgspeedrain = value;
	}
	virtual int Getavgspeedrain()
		{
		return avgspeedrain;
		}
	virtual void Setavgspeedsnow(int value)
	{
		avgspeedsnow = value;
	}
	virtual int Getavgspeedsnow()
	{
		return avgspeedsnow;
	}
	virtual void Setavgspeedsunny(int value)
	{
		avgspeedsunny = value;
	}
	virtual int Getavgspeedsunny()
	{
		return avgspeedsunny;
	}
	virtual char* Name(const char* x)
	{
		strcpy(name, x);
		return 0;
	}
	virtual void GetName()
	{
		cout << name;
	}
};