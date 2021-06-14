#pragma once
class Student
{
	char Nume[20];
	float NotaM;
	float NotaE;
	float NotaH;
	float MedieNota;
public:
	void InitName(const char* Nume);
	void InitNotaM(float NotaM);
	void InitNotaE(float NotaE);
	void InitNotaH(float NotaH);
	int  AverageGrade(float NotaM,float NotaE,float NotaH);
};
