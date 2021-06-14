#include "Sort.h"
#include <iostream>
using namespace std;
int main()
{
    int a[] = { 6,5,4,3,2 };
    Sort* x = new Sort();
    x->Print();
    x->QuickSort();
    x->Print();
    cout << endl;


}


