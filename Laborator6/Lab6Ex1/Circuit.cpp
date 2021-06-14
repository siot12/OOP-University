#include "Car.h"
#include "Dacia.h"
#include "Toyota.h"
#include "Mercedes.h"
#include "Ford.h"
#include "Mazda.h"
#include "Circuit.h"
#include <iostream>



using namespace std;

int Circuit::SetLength(int value)
{
	length = value;
	return 0;
}

int Circuit::SetWeather(Weather x)
{
	vremea = x;
	return 0;
}

void Circuit::AddCar(Car *obj)
{
	arr[numberofcars] = obj;
	numberofcars++;
}

Car* Circuit:: Get(int i)
{
	return arr[i];
}

void Circuit::Race() 
{
	int fuelcap = 0;
	int consum = 0;
	int viteza = 0;
	if (vremea == Weather::Rain)
	{
		for (int i = 0;i < 5;i++)
		{
			Car* p = Get(i);
			fuelcap = p->Getfuelcap();
			consum = p->Getfuelconsmp();
			viteza = p->Getavgspeedrain();
			if (length <= (fuelcap * (length / 10)) / consum)
			{
				f[i] = 1;
			}
			else
			{
				f[i] = 0;
			}
			if (f[i] == 1)
			{
				poz[i] = length / static_cast<float>(viteza);
			}
			else
			{
				poz[i] = 1000;
			}
		}

		
	}
	else
		if (vremea == Weather::Snow)
		{
			for (int i = 0;i < 5;i++)
			{
				Car* p = Get(i);
				fuelcap = p->Getfuelcap();
				consum = p->Getfuelconsmp();
				viteza = p->Getavgspeedsnow();
				if (length == (fuelcap * (length / 10)) / consum)
				{
					f[i] = 1;
				}
				else
				{
					f[i] = 0;
				}
				if (f[i] == 1)
				{
					poz[i] = length / static_cast<float>(viteza);
				}
				else
				{
					poz[i] = 1000;
				}
			}
		}
		else
		{
			//sunny
			for (int i = 0;i < 5;i++)
			{
				Car* p = Get(i);
				fuelcap = p->Getfuelcap();
				consum = p->Getfuelconsmp();
				viteza = p->Getavgspeedsunny();
				if (length == (fuelcap * (length / 10)) / consum)
				{
					f[i] = 1;
				}
				else
				{
					f[i] = 0;
				}
				if (f[i] == 1)
				{
					poz[i] = length / static_cast<float>(viteza);
				}
				else
				{
					poz[i] = 1000;
				}
			}



		}
	/*for (int i = 0;i < 5;i++)
	{
		Car* p = c.Get(i);
		cout << p->Getfuelcap() << endl;
	}*/

}


void Circuit::ShowFinalRanks()
{
	for (int i = 0;i < numberofcars-1;i++)
	{
		for (int j = i+1;j <numberofcars ;j++)
		{
			if (poz[i] > poz[j])
			{
				int aux = poz[i];
				poz[i] = poz[j];
				poz[j] = aux;
				Car* aux2 = arr[i];
				arr[i] = arr[j];
				arr[j] = aux2;
				int aux3 = f[i];
				f[i] = f[j];
				f[j] = aux3;
			}
		}
		
	}
	for (int i = 0;i < numberofcars;i++)
	{
		Car* p = Get(i);
		if (poz[i] == 1000)
		{
			cout << "Run Out OF Fuel" << " ";
			p->GetName();
			cout << endl;
		}
		else
		{
			cout << poz[i] << " ";
			p->GetName();
			cout << endl;

		}
	}
}

void Circuit::ShowWhoDidNotFinish()
{
	for (int i = 0;i < numberofcars;i++)
	{
		Car* p = Get(i);
		if (f[i] == 0)
		{
			p->GetName();
			cout << endl;
		}
	}
}