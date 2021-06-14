#include <iostream>
using namespace std;

class MyVector
{
    int v[100];
    int size = 0;
public:
    bool Add(int x)
    {
        if (size > 99) 
        {
            return 0;
        }
        v[size] = x;
        size++;
        return 1;
    }
    bool Delete(int index) 
    {
        if (index < 0 || index >= size)
        { 
            return 0; 
        }
        size--;
        for (int i = index; i < size; i++)
        {
            v[i] = v[i + 1];
        }
        return 1;
    }
    void Print()
    {
        for (int i = 0; i < size; i++)
        {
            cout << v[i] << " ";
        }
        cout << endl;
    }
    void Iterate(int(*f)(int x))
    {
        for (int i = 0; i < size; i++)
        {
            v[i] = f(v[i]);
        }
    }
    void Filter(bool(*f)(int x))
    {
        for (int i = 0; i < size; i++)
        {
            if (f(v[i]) == 1)
            {
                Delete(i);
                i--;
            }
        }
    }
}; 

int main()
{
    MyVector v;
    v.Add(5);
    v.Add(24);
    v.Add(7);
    v.Add(3);
    v.Add(18);
    v.Add(20);
    auto f = [](int x)
    {
        return x * 3;
    };
    auto h = [](int x) 
    {
        if (x % 2 == 0)
        {
            return true;
        }
        return false;
    };
    v.Filter(h);
    v.Print();
    v.Iterate(f);
    v.Print();

    return 0;
}


