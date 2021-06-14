#include "Math.h"
#include <iostream>
using namespace std;


int main()
{
    Math x;
    cout<<x.Add(10, 20)<<" ";
    cout<<x.Add(20, 30, 40)<<" ";
    cout << x.Add(12.24, 32.64) << " ";
    cout << x.Add(12.24, 32.65, 76.23) << " ";
    cout << x.Mul(12, 24)<<" ";
    cout << x.Mul(54, 75, 12)<<" ";
    cout << x.Mul(4.42, 2.23)<<" ";
    cout << x.Mul(2.1, 3.1, 4.1)<<" ";
    cout << x.Add(5,20,30,40,50,60)<<" ";
    cout<<x.Add("abcd" , "efgh");
    
    
}


