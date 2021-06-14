#include <iostream>
#include <exception>

using namespace std;

class exceptieCapacity : public exception {
	virtual const char* what() const throw()
	{
		return "Eroare de capacitate!";
	}
};

class exceptieIndex : public exception {
	virtual const char* what() const throw()
	{
		return "Index-ul este in afara vectorului!";
	}
};

class exceptieBinary : public exception {
	virtual const char* what() const throw()
	{
		return "Vectorul nu e sortat!";
	}
};

class exceptieFind : public exception
{
	virtual const char* what() const throw()
	{
		return "Elementul nu a fost gasit!";
	}
};

class Compare
{
public:
	virtual int CompareElements(void* e1, void* e2) = 0;
};

class CompareInt : public Compare {
public:
	int CompareElements(void* el1, void* el2)
	{
		if (el1 > el2)
			return 1;
		if (el2 > el1)
			return -1;
		return 0;
	}
};

template<class T>
class ArrayIterator
{
private:
	int* Current; // mai adaugati si alte date si functii necesare pentru iterator
public:
	ArrayIterator() {
		Current = 0;
	}
	ArrayIterator& operator ++ () {
		Current++;
		return *this;
	}
	ArrayIterator& operator -- () {
		Current--;
		return *this;
	}
	bool operator =(ArrayIterator<T>& a) {
		return Current == a.Current;
	}
	bool operator!=(ArrayIterator<T>& a) {
		return Current != a.Current;
	}
	T* GetElement() {
		return *Current;
	}
	int operator * () { return *Current; }
};

template<class T>
int comparare(const T& x, const T& y) {
	if (x > y) return 1;
	if (y > x) return -1;
	return 0;
}

template<class T>
class Array
{
private:
	T** List; // lista cu pointeri la obiecte de tipul T*
	int Capacity; // dimensiunea listei de pointeri
	int Size; // cate elemente sunt in lista
public:
	Array() noexcept(false)// Lista nu e alocata, Capacity si Size = 0
	{
		Capacity = 0;
		Size = 0;
	}
	~Array() noexcept(false) {	// destructor
		Capacity = 0; Size = 0;
		delete[] List;
	}
	Array(int capacity) noexcept(false) // Lista e alocata cu 'capacity' elemente
	{
		exceptieCapacity OutOfRange;
			if (capacity <= 0)
			{
				throw OutOfRange;
			}
			else
			{
				Capacity = capacity;
				Size = 0;
				List = new T * [Capacity];
			}
	}
	Array(const Array<T>& otherArray) noexcept(false) // constructor de copiere
	{
		Size = otherArray.Size;
		Capacity = otherArray.Capacity;
		for (int i = 0; i < otherArray.Size; i++) {
			List[i] = otherArray.List[i];
		}
	}

	T& operator[] (int index) { // arunca exceptie daca index este out of range
		exceptieCapacity OutOfRange;
		if (index < 0 || index >= Size)
		{
			throw OutOfRange;
		}
		else return *List[index];
	}

	const Array<T>& operator+=(const T& newElem) // adauga un element de tipul T la sfarsitul listei si returneaza this
	{
		exceptieCapacity OutOfRange;
			if (Size + 1 > Capacity)
				throw OutOfRange;
			else {
				List[Size] = new T;
				*List[Size] = newElem;
				Size++;
				return *this;
			}
		
		

	}

	const Array<T>& Insert(int index, const T& newElem) // adauga un element pe pozitia index, retureaza this. Daca index e invalid arunca o exceptie
	{
		exceptieIndex exceptie1;
		exceptieCapacity exceptie2;
			if (index < 0 || index > Size)
				throw exceptie1;
			else if (Size + 1 > Capacity)
				throw exceptie2;
			else {
				Size++;
				for (int i = Size; i >= index; i--) {
					List[i] = List[i - 1];
				}
				List[index] = new T;
				*List[index] = newElem;
				return *this;
			}
	}
	/*const Array<T>& Insert(int index, const Array<T> otherArray) // adauga o lista pe pozitia index, retureaza this. Daca index e invalid arunca o exceptie
	{
		exceptieIndex exceptie1;
		exceptieCapacity exceptie2;
		try {
			if (index < 0 || index > Size)
				throw exceptie1;
			else if (Size + 1 > Capacity)
				throw exceptie2;
			else {
				Size += otherArray.Size;
				for (int i = Size; i >= index + otherArray.Size; i--) {
					List[i] = List[i - otherArray.Size];
				}
				for (int i = index; i < index + otherArray.Size; i++) {
					List[i] = new T;
					List[i] = otherArray.List[i - index];
				}
				return *this;
			}
		}
		catch (exception& e) {
			cout << "Exceptie: " << e.what() << endl;
		}
	}*/

	const Array<T>& Delete(int index) // sterge un element de pe pozitia index, returneaza this. Daca index e invalid arunca o exceptie
	{
		exceptieIndex exceptie1;
		exceptieCapacity exceptie2;
			if (index < 0 || index > Size)
				throw exceptie1;
			else if (Size == 0)
				throw exceptie2;
			else {
				for (int i = index; i < Size; i++) {
					List[i] = List[i + 1];
				}
				// delete List[Size];
				Size--;
				return *this;
			}
	}

	bool operator=(const Array<T>& otherArray);

	void Sort() // sorteaza folosind comparatia intre elementele din T
	{
		int i, j;
		for (i = 0; i < Size - 1; i++) {
			for (j = i + 1; j < Size; j++) {
				if (*List[i] > *List[j]) {
					swap(List[i], List[j]);
				}
			}
		}
	}
	void Sort(int(*compare)(const T&, const T&)) // sorteaza folosind o functie de comparatie
	{
		int i, j;
		for (i = 0; i < Size - 1; i++) {
			for (j = i + 1; j < Size; j++) {
				if (compare(*List[i], *List[j]) == 1) {
					swap(List[i], List[j]);
				}
			}
		}
	}
	void Sort(Compare* comparator) // sorteaza folosind un obiect de comparatie
	{
		int i, j;
		for (i = 0; i < Size - 1; i++) {
			for (j = i + 1; j < Size; j++) {
				if (comparator->CompareElements((void*)*List[i], (void*)*List[j]) == 1) {
					swap(List[i], List[j]);
				}
			}
		}
	}

	// functii de cautare - returneaza pozitia elementului sau -1 daca nu exista
	int BinarySearch(const T& elem) // cauta un element folosind binary search in Array
	{
		exceptieBinary eroare;
			for (int i = 0; i < Size - 1; i++)
				if (*List[i] > *List[i + 1]) {
					throw eroare;
				}

			int l = 0;
			int r = Size - 1;
			int m = 0;
			int index = -1;
			while (l < r && index == -1) {
				m = (l + r) / 2;
				if (*List[m] == elem) {
					index = m;
				}
				else if (*List[m] < elem) {
					l = m + 1;
				}
				else {
					r = m - 1;
				}
			}
			if (*List[r] == elem) index = r;
			return index;
	}
	int BinarySearch(const T& elem, int(*compare)(const T&, const T&)) //  cauta un element folosind binary search si o functie de comparatie
	{
		exceptieBinary eroare;
			for (int i = 0; i < Size - 1; i++)
				if (compare(*List[i], *List[i + 1]) == 1) {
					throw eroare;
				}

			int l = 0;
			int r = Size - 1;
			int m = 0;
			int index = -1;
			while (l < r && index == -1) {
				m = (l + r) / 2;
				if (compare(*List[m], elem) == 0) {
					index = m;
				}
				else if (compare(*List[m], elem) == -1) {
					l = m + 1;
				}
				else {
					r = m - 1;
				}
			}
			if (*List[r] == elem) index = r;
			return index;
		

	}
	int BinarySearch(const T& elem, Compare* comparator) //  cauta un element folosind binary search si un comparato
	{
		exceptieBinary eroare;
			for (int i = 0; i < Size - 1; i++)
				if (comparator->CompareElements((void*)*List[i], (void*)*List[i + 1]) == 1) {
					throw eroare;
				}

			int l = 0;
			int r = Size - 1;
			int m = 0;
			int index = -1;
			while (l < r && index == -1) {
				m = (l + r) / 2;
				if (comparator->CompareElements((void*)*List[m], (void*)elem) == 0) {
					index = m;
				}
				else if (comparator->CompareElements((void*)*List[m], (void*)elem) == -1) {
					l = m + 1;
				}
				else {
					r = m - 1;
				}
			}
			if (*List[r] == elem) index = r;
			return index;
		
	}

	int Find(const T& elem) // cauta un element in Array
	{
		exceptieFind exceptie;
			for (int i = 0; i < Size; i++)
			{
				if (*List[i] == elem)
				{
					return i;
				}
		    }
			throw exceptie;
		
	}
	int Find(const T& elem, int(*compare)(const T&, const T&)) //  cauta un element folosind o functie de comparatie
	{
		exceptieFind exceptie;
		for (int i = 0; i < Size; i++) {
			if (compare(*List[i], elem) == 0)
				return i;
		}
		throw exceptie;
	}
	int Find(const T& elem, Compare* comparator)//  cauta un element folosind un comparator
	{
		exceptieFind exceptie;
		for (int i = 0; i < Size; i++) {
			if (comparator->CompareElements((void*)*List[i], (void*)elem) == 0)
				return i;
		}
		throw exceptie;
	}

	int GetSize() { return Size; }
	int GetCapacity() { return Capacity; }

	ArrayIterator<T> begin();
	ArrayIterator<T> end();

	void Print() {
		for (int i = 0; i < Size; i++) {
			cout << *List[i] << " ";
		}
		cout << endl;
	}
};

int main()
{
	try
	{
		CompareInt x;
		Array<int> t(20);
		t += 2;
		t += 3;
		t += 4;
		t.Insert(1, 12);
		t += 1;
		cout << t[2];
		cout << endl;
		t.Sort(&x);
		cout << t.Find(1) << endl;
		t.Print();
		t.BinarySearch(3);
	}
	catch (exception& e)
	{
		cout << "Exceptie: " << e.what() << endl;
	}
	return 0;
}
