#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <map>
#include <queue>
using namespace std;
ifstream in("Prop.txt");

class Compare
{
public:
    bool operator() (pair<string, int> const& x, pair<string, int> const& y) const
    {
        if (x.second != y.second)
        {
            return x.second < y.second;

        }
        else
        {
            if (x.first.compare(y.first) > 0)
            {
                return true;
            }
            else
            {
                return false;
            }

        }
    }
};


int main()
{
    map<string, int>mep;
    string sir;
    string cuv;
    vector<string> v;
    string sep = " .,;!?";
    getline(ifstream("Prop.txt"), sir, '\0');
    size_t start, poz = 0;
    start = sir.find_first_not_of(sep, poz);
    for (int i = 0; i < sir.length(); i++)
    {
        if (sir[i] >= 'A' && sir[i] <= 'Z')
            sir[i] = sir[i] + 32;
    }
    while (start != string::npos)
    {
        poz = sir.find_first_of(sep, start + 1);
        string item(sir.substr(start, poz - start));
        mep[item]++;
        start = sir.find_first_not_of(sep, poz);
    }
    for (int i = 0; i < v.size(); i++) { // bagam cuvintele in map
        mep[v[i]]++;
    }

    map<string, int>::iterator i;
    for (i = mep.begin(); i != mep.end(); i++) {
        cout << i->first << "->" << i->second << endl; // afisam cuvintele din map
    }

    cout << endl;

    priority_queue<pair<string, int>, vector<pair<string, int>>, Compare> s;
    for (i= mep.begin(); i != mep.end(); i++)
    {
        pair<string, int> item(i->first, i->second);
        s.push(item);
    }

    while (s.empty() != true)
    {
        cout << s.top().first << "->" << s.top().second << endl;
        s.pop();
    }


    in.close();
    return 0;

}


