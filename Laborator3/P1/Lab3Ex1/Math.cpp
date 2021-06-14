#include "Math.h"
#include <stdarg.h>
#include <string.h>
#include <iostream>
using namespace std;


int Math::Add(int x, int y)
{
	return x + y;
}

int Math::Add(int x, int y, int z)
{
	return x + y + z;
}

int Math::Add(double x, double y)
{
	return x + y;
}

int Math::Add(double x, double y, double z)
{
	return x + y + z;
}

int Math::Mul(int x, int y)
{
	return x * y;
}

int Math::Mul(int x, int y, int z)
{
	return x * y * z;
}

int Math::Mul(double x, double y)
{
	return x * y;
}

int Math::Mul(double x, double y, double z)
{
	return x * y * z;
}

int Math::Add(int count, ...)
{
	int suma = 0;
	va_list args;
	va_start(args, count);
	for (int i = 1;i <= count;i++)
	{
		
		suma = suma + va_arg(args,int);

	}
	va_end(args);
	return suma;
}

char* Math::Add(const char* x, const char* y)
{
	if (x == nullptr or y == nullptr)
	{
		return nullptr;
	}
	else
	{
		int nr = 0;
		int m1 = strlen(x);
		int m2 = strlen(y);
		nr = m1 + m2;
		char *p = new char [nr+1];
		int n = 0;
		n = strlen(x);
		int m = strlen(y);
		strcpy(p,x);
		strcpy(p + n, y);
		p[n + m] = NULL;
		return p;
	}
		
}

