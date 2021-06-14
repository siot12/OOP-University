#include "Mazda.h"
#include "Car.h"
Mazda::Mazda()
{
	Setfuelconsmp(7);
	Setfuelcap(60);
	Setavgspeedrain(80);
	Setavgspeedsnow(45);
	Setavgspeedsunny(120);
	Name("Mazda");
}

void Mazda::Set()
{
}
void Mazda::Setfuelcap(int value)
{
	fuelcap = value;
}
int Mazda::Getfuelcap()
{
	return fuelcap;
}
void Mazda::Setfuelconsmp(int value)
{
	fuelconsmp = value;
}
int Mazda::Getfuelconsmp()
{
	return fuelconsmp;

}
void Mazda::Setavgspeedrain(int value)
{
	avgspeedrain = value;
}
int Mazda::Getavgspeedrain()
{
	return avgspeedrain;
}
void Mazda::Setavgspeedsnow(int value)
{
	avgspeedsnow = value;
}
int Mazda::Getavgspeedsnow()
{
	return avgspeedsnow;
}
void Mazda::Setavgspeedsunny(int value)
{
	avgspeedsunny = value;
}
int Mazda::Getavgspeedsunny()
{
	return avgspeedsunny;
}
char* Mazda::Name(const char* x)
{
	strcpy(name, x);
	return 0;
}

void Mazda::GetName()
{
	cout << name;
}