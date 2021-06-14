#include "Student.h"
#include "GlobalFunctions.h"
#include <iostream>
using namespace std;

int main()
{
    int NotaM, NotaE, NotaH, NotaM2, NotaE2, NotaH2, MedieNota1, MedieNota2;
    cin >> NotaM >> NotaE>>NotaH;
    cin >> NotaM2 >> NotaE2 >> NotaH2;
    Student x, y;
    x.InitName("Raul Petcu");
    y.InitName("Raul Garavani");
    x.InitNotaM(NotaM);
    y.InitNotaM(NotaM2);
    x.InitNotaE(NotaE);
    y.InitNotaE(NotaE2);
    x.InitNotaH(NotaH);
    y.InitNotaH(NotaH2);
    MedieNota1=x.AverageGrade(NotaM,NotaE,NotaH);
    MedieNota2=y.AverageGrade(NotaM2,NotaE2,NotaH2);
    cout<<Medie(MedieNota1, MedieNota2);

    return 0;
}

