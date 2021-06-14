#include <iostream>
#include "GlobalFunctions.h"
#include "Student.h"

using namespace std;

int Medie(int Media1, int Media2)
{
	if (Media1 > Media2)
	{
		return 1;
	}
	else
	{
		if (Media1 == Media2)
		{
			return 0;
		}
		else
		{
			return -1;
		}
	}
}
