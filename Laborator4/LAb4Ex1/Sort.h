#pragma once
#include <iostream>
#include <stdarg.h>
#include <string.h>

class Sort
{
	int* v;
	bool ascendent = false;
	int n;
	int inf = 0;
	int sup;


public:
	
	Sort(int nr, int min, int max) :n(nr)
	{
		int i = 0;
		sup = n - 1; 
		v = new int[n];
		while (nr > 0)
		{
			int random = (rand() % (max - min + 1)) + min;
			v[i] = random;
			i++;
			nr--;
		}
	}
	Sort()
	{
		
		int a[7] = { 6,5,4,3,2,1,0 };
		n = 7;
		v = new int[n];
		Sort(a, n); 
		
	}
	Sort(int a[], int nr) 
	{
		v = new int[nr];
		n = nr;
		for (int i = 0;i < nr;i++)
		{
			v[i] = a[i];
		}
		sup = n - 1;
		
	} 
	Sort(int count, ...):n(count)
	{
		v = new int[n];
		sup = n - 1;
		va_list args;
		va_start(args, count);
		for (int i = 1;i <= count;i++)
		{
			v[i - 1] = va_arg(args, int);
		}
		va_end(args); 
		
	} 
	Sort(const char* x)
	{
		
		int i=0;
		n = 0;
		while (x[i] != NULL)
		{
			if (x[i] == ',')
			{
				n++;
			}
			i++;
		}
		n++;
		i = 0;
		v = new int[n];
		int y = 0;
		int z = 0;
		int ok = 1;
		while (x[i] !=NULL)
		{
			if (x[i] == ',')
			{
				y = 0;
				i++;
				ok = 0;
			}
			else
			{
				while (x[i]!= ',' && x[i]!=NULL)
				{
					y = y * 10 + (x[i] - '0');
					i++;
				}
				ok = 1;
				i++;
			}
			if (ok == 1)
			{
				v[z] = y;
				z++;
			}
			y = 0;
		}
		sup = n - 1;
		
	}
	void InsertSort(bool ascendent = false);
	void QuickSort(bool ascendent = false);
	void BubbleSort(bool ascendent = false);
	void Print();
	int GetElementsCount();
	int GetElementFromIndex(int index);
};

/*Sort::Sort(int nr, int min, int max)
{
	n = nr;
	while (nr != 0)
	{
		int i = 0;
		int random = min + (std::rand() % (max - min + 1));
		v[i] = random;
		i++;
		nr--;
	}
}

Sort::Sort()
{
	int v[] = { 4,2,8,5,3,1,9 };
	n = sizeof(v);
}

Sort::Sort(int a[], int nr)
{
	int z = 0;
	int n = 1;
	for (int i = 0;i < nr;i++)
	{
		v[z] = a[i];
		z++;
		n++;
	}
}*/