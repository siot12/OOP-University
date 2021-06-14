#include "NumberList.h"

int main()
{  
	NumberList y;
	y.Init();
	y.Add(5);
	y.Add(6);
	y.Add(4);
	y.Print();
	y.Sort();
	y.Print();
	return 0;

}
