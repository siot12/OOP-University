#include "Dacia.h"
#include "Car.h"

Dacia::Dacia()
{
	Setfuelconsmp(4);
	Setfuelcap(60);
	Setavgspeedrain(60);
	Setavgspeedsnow(30);
	Setavgspeedsunny(90);
	Name("Dacia");
}

void Dacia::Set()
{
}
void Dacia::Setfuelcap(int value)
{
	fuelcap = value;
}
int Dacia::Getfuelcap()
{
	return fuelcap;
}
void Dacia::Setfuelconsmp(int value)
{
	fuelconsmp = value;
}
int Dacia::Getfuelconsmp()
{
	return fuelconsmp;

}
void Dacia::Setavgspeedrain(int value)
{
	avgspeedrain = value;
}
int Dacia::Getavgspeedrain()
{
	return avgspeedrain;
}
void Dacia::Setavgspeedsnow(int value)
{
	avgspeedsnow = value;
}
int Dacia::Getavgspeedsnow()
{
	return avgspeedsnow;
}
void Dacia::Setavgspeedsunny(int value)
{
	avgspeedsunny = value;
}
int Dacia::Getavgspeedsunny()
{
	return avgspeedsunny;
}
char* Dacia::Name(const char* x)
{
	strcpy(name, x);
	return 0;
}

void Dacia::GetName()
{
	cout << name;
}