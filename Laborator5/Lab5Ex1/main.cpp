#include <iostream>
#include "Number.h"
#include <stdio.h>

using namespace std;
int main()
{
    Number n1("10110010", 2);

    Number n2("734", 10);

    Number n3("FF", 16);
    printf("n1 has %d digits and it is written in base %d\n", n1.GetDigitsCount(), n1.GetBase());
    printf("n2 has %d digits and it is written in base %d\n", n2.GetDigitsCount(), n2.GetBase());
    printf("n3 has %d digits and it is written in base %d\n", n3.GetDigitsCount(), n3.GetBase());
    n1.Print();
    n2.Print();
    n3.Print();
    //n1.SwitchBase(10);
   // n2.SwitchBase(10);
    //n3.SwitchBase(2);
    n1 = n1 + n3;
    n1.Print();
    cout << endl;
    if (n1 > n2) printf("n1 is bigger than n2\n"); else printf("n2 is bigger than n1\n");
    n1--;
    n1.Print();
    --n1;
    n1.Print();

}

