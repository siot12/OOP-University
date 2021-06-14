#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    vector<string> v = { "aaaa", "aaab", "dnsna", "efefs",};
    auto compare = [](const string sir1, const string sir2)
    {
        if (sir1.length() > sir2.length())
        {
            return 1;
        }
        if (sir1.length() < sir2.length())
        {
            return -1;
        }
        if (sir1 > sir2)
        {
            return 1;
        }
        if (sir1 < sir2)
        {
            return -1;
        }
        return 0;
    };
    for (int i = 0; i < v.size() - 1; i++) 
    {
        for (int j = i + 1; j < v.size(); j++)
        {
            if (compare(v[i], v[j]) == 1)
            {
                swap(v[i], v[j]);
            }
        }
    }
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << "\n";
    }
    return 0;
}


