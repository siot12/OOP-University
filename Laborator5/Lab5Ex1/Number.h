#pragma once
class Number
{
	int rez10;
	int baza;
	char nr[100];

public:
	Number(const char* value, int base);
	~Number();

	friend int operator+(const Number& i, int val);
	friend int operator+(int val, const Number& i);
	friend int operator-(const Number& i, int val);
	friend int operator-(int val, const Number& i);
	Number(Number&& x);
	Number(const Number& x);
	int operator +(const Number &i);
	int operator -(const Number &i);
	Number& operator = (int val);
	int operator !();

	bool operator > (const Number& i);
	bool operator < (const Number& i);
	bool operator >= (const Number& i);
	bool operator <= (const Number& i);

	friend bool operator += (Number& i, int val);
	friend bool operator -= (Number& i, int val);
	friend bool operator *= (Number& i, int val);
	friend bool operator /= (Number& i, int val);

    bool operator ++ (int value);
	Number& operator ++ ();

	bool operator --(int value);
	Number& operator --();


	//add operators and copy/move constructor
	void SwitchBase(int newBase);
	void Print();
	int GetDigitsCount();
	int GetBase();
};