#include "Ford.h"
#include "Car.h"
Ford::Ford()
{
	Setfuelconsmp(6);
	Setfuelcap(60);
	Setavgspeedrain(55);
	Setavgspeedsnow(35);
	Setavgspeedsunny(95);
	Name("Ford");
}

void Ford::Set()
{
}
void Ford::Setfuelcap(int value)
{
	fuelcap = value;
}
int Ford::Getfuelcap()
{
	return fuelcap;
}
void Ford::Setfuelconsmp(int value)
{
	fuelconsmp = value;
}
int Ford::Getfuelconsmp()
{
	return fuelconsmp;

}
void Ford::Setavgspeedrain(int value)
{
	avgspeedrain = value;
}
int Ford::Getavgspeedrain()
{
	return avgspeedrain;
}
void Ford::Setavgspeedsnow(int value)
{
	avgspeedsnow = value;
}
int Ford::Getavgspeedsnow()
{
	return avgspeedsnow;
}
void Ford::Setavgspeedsunny(int value)
{
	avgspeedsunny = value;
}
int Ford::Getavgspeedsunny()
{
	return avgspeedsunny;
}
char* Ford::Name(const char*x)
{
	strcpy(name, x);
	return 0;
}

void Ford::GetName()
{
	cout << name;
}