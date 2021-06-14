#include "Sort.h"
#include <iostream>
using namespace std;
void Sort::InsertSort(bool ascendent)
{
	for (int i = 1;i < n ;i++)
	{
		int j = i - 1;
		int tmp = v[i];
		while (j >= 0 && v[j] > tmp)
		{
			v[j + 1] = v[j];
			j = j - 1;
		}
		if (v[j + 1] != tmp)
		{
			v[j + 1] = tmp;
		}
	}
	ascendent= true;
}

void Sort::BubbleSort(bool ascendent)
{
	int i, j;
	for (i = 0;i < n;i++)
	{
		for (j = 0;j < n - i - 1;j++)
		{
			if (v[j] > v[j + 1])
			{
				swap(v[j], v[j + 1]);
			}
		}
	}
	ascendent = true; 
}

void Sort::QuickSort(bool ascendent)
{
	int x, i, j, t;
	i = inf;
	j = sup;
	x = v[(i + j) / 2];
	do {
		while ((i < sup) && (v[i] < x)) i++;
		while ((j > inf) && (v[j] > x)) j--;
		if (i <= j)
		{
			t = v[i];
			v[i] = v[j];
			v[j] = t;
			i++;
			j--;
		}
	} while (i <= j);
	if (inf < j)
	{
		sup = j;
		QuickSort();
	}
	if (i < sup)
	{
		inf = i;
		QuickSort();
	}
	ascendent = true;

}

void Sort::Print()
{
	for (int i = 0;i < n;i++) 
	{
		cout << v[i] <<" ";
	}
	cout << endl;
}

int Sort::GetElementsCount()
{
	return n;
}

int Sort::GetElementFromIndex(int index)
{
	if (index > n || index <0)
	{
		return false;
	}
	else
	{
		return v[index];
	}
}