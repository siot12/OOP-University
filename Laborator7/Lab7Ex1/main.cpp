#include <iostream>
using namespace std;


int operator"" _Kelvin(unsigned long long int x)
{
    return x - 273.15;
}

int operator"" _Farenheit(unsigned long long int x)
{
    return (x - 32) / 1.8;
}

int main()
{
    float a = 300_Kelvin;
    float b = 120_Farenheit;
    cout << a << " " << b;
    return 0;
}

