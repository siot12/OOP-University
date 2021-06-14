#include <iostream>
#include "Car.h"
#include "Circuit.h"
#include "Dacia.h"
#include "Ford.h"
#include "Mazda.h"
#include "Mercedes.h"
#include "Toyota.h"
#include "Weather.h"
#define CRT_SECURE_NO_WARNINGS
using namespace std;

int main()
{
	Circuit c;

	c.SetLength(1000);
	
	c.SetWeather(Weather::Rain);
	
	c.AddCar(new Dacia());
	c.AddCar(new Toyota());

	c.AddCar(new Mercedes());

	c.AddCar(new Ford());

	c.AddCar(new Mazda());
	/*for (int i = 0;i < 5;i++)
	{
		Car* p = c.Get(i);
		cout << p->Getfuelcap() << endl;
	}*/
	c.Race();

	c.ShowFinalRanks(); // it will print the time each car needed to finish the circuit sorted from the fastest car to the   slowest.

	c.ShowWhoDidNotFinish(); // it is possible that some cars don't have enough fuel to finish the circuit
	
	return 0;
}
