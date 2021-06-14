#pragma once
#include "Weather.h"

class Circuit
{
    float poz[5];
    int f[5];
	int length;
	int numberofcars = 0;
	Weather vremea;
	Car* arr[100];
public:
	int SetLength(int value);
	int SetWeather(Weather x);
	void AddCar(Car *obj);
	void Race();
	void ShowFinalRanks();
	void ShowWhoDidNotFinish();
	Car* Get(int i);
};