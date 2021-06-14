#include "Number.h"
#include <iostream>
#include <string.h>


using namespace std;

Number::Number(const char* value, int base)
{
	int putere = 1;
	int i;
	rez10 = 0;
	baza = base;
	strcpy(nr, value);
	int nr=0;
	int l = strlen(value);
	for (i = l - 1;i >= 0;i--)
	{
		nr = 0;
		if (value[i] >= '0' && value[i] <= '9')
		{
			nr = (value[i] - '0');
		}
		else
		{
			nr = value[i] - 'A' + 10;
		}
		rez10 = rez10 + nr * putere;
		putere = putere * base;
	}
	

}

Number::~Number()
{
	

}


int operator+(const Number& i, int val)
{
	return i.rez10 + val;
}

int operator+(int val, const Number& i)
{
	return i.rez10 + val;
}

int operator-(const Number& i, int val)
{
	return i.rez10 - val;
}

int operator-(int val, const Number& i)
{
	return i.rez10 - val;
}

int Number::operator +(const Number &i)
{
	int copie = rez10;
	if (baza >= i.baza)
	{
		return rez10 + i.rez10;
	}
	else
	{
		rez10 = rez10 + i.rez10;
		baza = i.baza;
		SwitchBase(baza);
		rez10 = copie;
		return rez10 + i.rez10;
	}
}

int Number::operator -(const Number& i)
{
	int copie = rez10;
	if (baza >= i.baza)
	{
		rez10 = rez10 - i.rez10;
		SwitchBase(baza);
		rez10 = copie;
		return rez10 - i.rez10;
	}
	else
	{ 
		rez10 = rez10 - i.rez10;
		baza = i.baza;
		SwitchBase(baza);
		rez10 = copie;
		return rez10 - i.rez10;
	}
}

int Number::operator !()
{
	return false;
}



Number& Number::operator = (int val)
{
	rez10 = val;
	return (*this);
}


bool Number::operator > (const Number& i)
{
	if (rez10 > i.rez10)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Number::operator < (const Number& i)
{
	if (rez10 < i.rez10)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Number::operator >= (const Number& i)
{
	if (rez10 >= i.rez10)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Number::operator <= (const Number& i)
{
	if (rez10 <= i.rez10)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool operator +=(Number& i, int val)
{
	i.rez10 = i.rez10 + val;
	return true;
}

bool operator -=(Number& i, int val)
{
	i.rez10 = i.rez10 - val;
	return true;
}

bool operator *=(Number& i, int val)
{
	i.rez10 = i.rez10 * val;
	return true;
}

bool operator /=(Number& i, int val)
{
	i.rez10 = i.rez10 / val;
	return true;
}

/*bool Number::operator++ ()
{
	rez10++;
	
	return true;
}*/
bool Number::operator++ (int val)
{
	rez10 = rez10 + 1;
	SwitchBase(baza);
	return false;
}

Number& Number::operator++ ()
{
	rez10 = rez10 + 1;
	SwitchBase(baza);
	return(*this);
}
bool Number::operator--(int val)
{
	nr[strlen(nr)-1] = '\0';
	return false;
}

Number& Number::operator-- ()
{
	strcpy(nr, nr + 1);
	return(*this);
}

Number::Number(const Number& x)
{
	this->rez10 = x.rez10;
	this->baza = x.baza;
	this->nr[100] = x.nr[100];
}

Number::Number(Number&& x)
{
	rez10 = x.rez10;
	rez10 = NULL;
	baza = x.baza;
	baza = NULL;
	nr[100] = x.nr[100];
	nr[100] =NULL;
}

void Number::SwitchBase(int newBase)
{
	nr[strlen(nr)] = '\0';
	baza = newBase;
	int index = 0;
	int rez = rez10;
	char a[100];
	char b[1];
	int z = 0;
	while (rez > 0)
	{
		z = rez % newBase;
		if (z >= 0 && z <= 9)
		{
			b[0] = z + '0';
		}
		else
		{
			b[0] = z - 10 + 'A';
		}
		a[index++] = b[0];
		rez = rez / newBase;
	}
	a[index] = '\0';
	int l = strlen(a);
	int i;
	for (i = 0;i <= (l/2)-1;i++)
	{
		char aux = a[i];
		a[i] = a[l - i - 1];
		a[l - i - 1] = aux;
	}
	strcpy(nr, a);
}

void Number::Print()
{
	cout << endl;
	cout << nr << " ";
}

int Number::GetDigitsCount()
{
	return strlen(nr);
}

int Number::GetBase()
{
	return baza;
}