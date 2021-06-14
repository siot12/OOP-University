#include <iostream>
#include <stdio.h>
using namespace std;

template <typename K,typename V>
class Map
{
public:
    struct Data
    {
        K key;
        V value;
        int index;
    };
    Data z[100];
    Data* copy[100];
    int size=0;
    int cpy = -1;
    Map()
    {
        z[size].index = 0;
        z[size].key = 0;
        z[size].value = 0;
    }
    Map& operator[](int val)
    {
        for (int i = 0;i < size;i++)
        {
            if (z[i].key == val)
            {
                cpy = i;
            }
        }
        if (cpy == -1)
        {
            if (z[size].index != 0)
            {
                z[size].index = z[size - 1].index + 1;
            }

            z[z[size].index].key = val;
            return *this;
        }
        else
        {
            z[z[cpy].index].key = val;
            return *this;
        }
    }
    Map& operator=(const char* a)
    {
        if (cpy != -1)
        {
            z[z[cpy].index].value = a;
            cpy = -1;
            return *this;
        }
        z[z[size].index].value = a;
        size++;
        return *this;
    }   
    Data* begin()
    {
        z[0].index = 0;
        copy[0] = &z[0];
        return copy[0];
    }
    Data* end()
    {
        z[size].index = size;
        copy[size] = &z[size];
        copy[size+1] = NULL;
        return copy[size];
    }
    void Set(K key, V value)
    {
        for (int i = 0;i < size;i++)
        {
            if (z[i].key == key)
            {
                z[i].value = value;
            }
        }
    }
    bool Get(const K& key, V value)
    {
        for (int i = 0;i < size;i++)
        {
            if (z[i].key == key)
            {
                for (int j = 0;j < size;j++)
                {
                    if (z[j].value == value)
                    {
                        z[j].value = z[i].value;
                        return true;
                    }
                }
            }
        }
        return false;
    }
    int Count()
    {
        return size;
    }
    void Clear()
    {
        for (int i = 0;i < size;i++)
        {
            z[i].key = 0;
            z[i].value = 0;
            z[i].index = 0;
        }
    }
    bool Delete(const K& key)
    {
        for (int i = 0;i < size;i++)
        {
            if (z[i].key == key)
            {
                for (int j = i;j < size-1;j++)
                {
                    z[j].key =z[j+1].key;
                    z[j].value = z[j+1].value;
                    z[j].index = z[j + 1].index-1;
                    
                }
                size--;
                return true;
            }
        }
        return false;
    }
    bool Includes(const Map<K, V>& map)
    {
        
        for (int j = 0;j < map.size;j++)
        {
            int ok = 0;
            for (int i = 0;i < size;i++)
            {
                if (z[i].key == map.z[j].key)
                {
                    ok = 1;
                }
            }
            if (ok == 0)
            {
                return false;
            }
        }
        return true;
    }
};

int main()
{
    Map<int, const char*> m;
 
    m[10] = "C++";
   
    m[20] = "test";
   
    m[30] = "Poo";


    for (auto [key, value, index] : m)
    {

        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);

    }
    
    m[20] = "result";

    for (auto [key, value, index] : m)
    {

        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);

    }
    
    return 0;
}