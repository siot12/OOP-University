#include <iostream>
#include "Student.h"
using namespace std;


void Student::InitName(const char* Nume)
{
	cout << Nume <<endl;
}

void Student::InitNotaM(float NotaM)
{
	this->NotaM = NotaM;
	cout << NotaM<<" ";
}

void Student::InitNotaE(float NotaE)
{
	this->NotaE = NotaE;
	cout << NotaE <<" ";
}

void Student::InitNotaH(float NotaH)
{
	this->NotaH = NotaH;
	cout << NotaH<<" ";
}

int Student::AverageGrade(float NotaM,float NotaE,float NotaH)
{
	int media;
	media = (NotaM + NotaE + NotaH) / 3;
	cout << media<<" ";
	return media;
	
}


