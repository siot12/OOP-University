#include "Canvas.h"




int main()
{
    Canvas x{30,30};
    x.DrawCircle(8, 8, 5, '.');
    x.Print();
    x.FillCircle(8, 8, 3, '.');
    x.Print();
    x.Clear();
    x.DrawRect(4, 2, 8, 6, '.');
    x.Print();
    x.FillRect(4, 2, 8, 6, '.');
    x.Print();
    x.Clear();
    x.DrawLine(7,7, 20,20, '.');
    x.SetPoint(0, 0, '.');
    x.Print();


}

