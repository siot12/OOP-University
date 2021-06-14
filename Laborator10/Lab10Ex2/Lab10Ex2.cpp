#include <iostream>
#include <list>
#include <iterator> 
using namespace std;

int main()
{
    list<int> l = { 2 ,4 ,5 ,23 ,43 ,22 ,12 };
    auto maxim = [](list<int> a)
    {
        int max = a.front();
        for (auto it : a)
        {
            if (it > max)
            {
                max = it;
            }
        }
        return max;
    };
    cout << maxim(l);
    return 0;
}

