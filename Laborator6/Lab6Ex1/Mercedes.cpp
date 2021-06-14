#include "Mercedes.h"
#include "Car.h"
Mercedes::Mercedes()
{
	Setfuelconsmp(10);
	Setfuelcap(60);
	Setavgspeedrain(100);
	Setavgspeedsnow(60);
	Setavgspeedsunny(160);
	Name("Mercedes");
}

void Mercedes::Set()
{
}
void Mercedes::Setfuelcap(int value)
{
	fuelcap = value;
}
int Mercedes::Getfuelcap()
{
	return fuelcap;
}
void Mercedes::Setfuelconsmp(int value)
{
	fuelconsmp = value;
}
int Mercedes::Getfuelconsmp()
{
	return fuelconsmp;

}
void Mercedes::Setavgspeedrain(int value)
{
	avgspeedrain = value;
}
int Mercedes::Getavgspeedrain()
{
	return avgspeedrain;
}
void Mercedes::Setavgspeedsnow(int value)
{
	avgspeedsnow = value;
}
int Mercedes::Getavgspeedsnow()
{
	return avgspeedsnow;
}
void Mercedes::Setavgspeedsunny(int value)
{
	avgspeedsunny = value;
}
int Mercedes::Getavgspeedsunny()
{
	return avgspeedsunny;
}
char* Mercedes::Name(const char*x)
{
	strcpy(name, x);
	return 0;
}

void Mercedes::GetName()
{
	cout << name;
}