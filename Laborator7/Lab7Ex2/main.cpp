#include <iostream>
using namespace std;
template <class T>
class Vector
{
	int size=0;
	T* v = new T[100];
public:
	
	void push(T value)
	{
		v[++size] = value;
	}
	T pop()
	{
		return v[--size];
	}
	void remove(T index)
	{
		for (int i = index;i < size;i++)
		{
			v[i] = v[i + 1];
		}
		size--;
	}
	
	/*void compare(T value1, T value2,int i,int j)
	{
		if (value1 > value2)
		{
			v[i] = value2;
			v[j] = value1;
		}
		else
		{
			v[i] = value1;
			v[j] = value2;
		}
	}*/

	static bool compare(T a, T b)
	{
		return(a < b);
	}
	
	static bool eq(T a, T b)
	{
		return (a == b);
	}

	int firstIndexOf(T element,bool (*eq)(T, T))
	{
		if (eq == nullptr)
		{
			int i = 1;
			while(i<=size)
			{
				if (element==v[i])
				{
					return i;
				}
				else
				{
					i++;
				}
			}
		}
		else
		{
			int i = 1;
			while (i <= size)
			{
				if ((*eq)(element, v[i]))
				{
					return i;
				}
				else
				{
					i++;
				}
			}
		}
	}
	void sort(bool (*compare)(T,T))
	{
		if (compare == nullptr)
		{
			bool sorted;
			do
			{
				sorted = true;
				for (int i = 1;i <= size;i++)
				{
					if (v[i] < v[i + 1])
					{
						swap(v[i], v[i + 1]);
						sorted = false;
					}
				}
			} while (!sorted);
		}
		else
		{
			bool sorted;
			do {
				sorted = true;
				for (int i = 1;i <= size;i++)
				{
					if ((*compare)(v[i], v[i + 1]))
					{
						swap(v[i], v[i + 1]);
						sorted = false;
					}
				}

			} while (!sorted);
		}
	}

	void insert(T index,T value)
	{
		
		v[size + 1] = v[size];
		for (int i = size;i > index;i--)
		{
			v[i] = v[i - 1];
		}
		v[index] = value;
		size++;
	}
	const T* get(int index)
	{
		return &v[index];
	}
	void set(T tmp, int index)
	{
		v[index] = tmp;
	}
	int count()
	{
		return size;
	}
	void getElements() 
	{
		for (int i = 1; i <= size; i++)
		{
			cout << v[i] << " ";
		}
		cout << endl;
	}
};

int main()
{
	Vector<int> v;

	v.push(1);
	v.push(2);
	v.push(3);
	v.push(4);
	v.push(5);
	v.push(6);
	v.push(7);
	v.push(8);
	v.push(9);

	v.sort(&v.compare);
	v.getElements();
	cout << endl;
	cout<<v.firstIndexOf(3, &v.eq);
	cout << endl;


	cout << v.count() << endl;
	v.remove(9);
	v.getElements();

	v.insert(7, 112);
	v.getElements();

	cout << v.get(2) << endl;

	v.set(245, 5);
	v.getElements();

	return 0;
}

