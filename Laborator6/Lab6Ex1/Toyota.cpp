#include "Toyota.h"
#include "Car.h"
Toyota::Toyota()
{
	Setfuelconsmp(6);
	Setfuelcap(65);
	Setavgspeedrain(55);
	Setavgspeedsnow(40);
	Setavgspeedsunny(110);
	Name("Toyota");
}

void Toyota::Set()
{

}
void Toyota::Setfuelcap(int value)
{
	fuelcap = value;
}
int Toyota::Getfuelcap()
{
	return fuelcap;
}
void Toyota::Setfuelconsmp(int value)
{
	fuelconsmp = value;
}
int Toyota::Getfuelconsmp()
{
	return fuelconsmp;

}
void Toyota::Setavgspeedrain(int value)
{
	avgspeedrain = value;
}
int Toyota::Getavgspeedrain()
{
	return avgspeedrain;
}
void Toyota::Setavgspeedsnow(int value)
{
	avgspeedsnow = value;
}
int Toyota::Getavgspeedsnow()
{
	return avgspeedsnow;
}
void Toyota::Setavgspeedsunny(int value)
{
	avgspeedsunny = value;
}
int Toyota::Getavgspeedsunny()
{
	return avgspeedsunny;
}
char* Toyota::Name(const char* x)
{
	strcpy(name, x);
	return 0;
}

void Toyota::GetName()
{
	cout << name;
}