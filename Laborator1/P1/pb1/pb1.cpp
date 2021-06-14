#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

int main()
{
    FILE* fpin;
    char x[100];
    int suma = 0;
    int y = 0;
    fpin = fopen("F:\\pb1.txt", "r");
    if (fpin == NULL)
    {
        printf("Error: cannot open file");
        exit(1);
    }
    while (!feof(fpin))
    {
        fgets(x, 100, fpin);
        int i = 0;
        y = 0;//nr convertit din char in int
        while (x[i] != NULL)
        {
            if (x[i] >= '0' && x[i] <= '9')
            {
                y = y * 10 + (x[i] - '0'); //conversia string in int cu ajutorul ASCII
            }
            i++;
        }
        suma = suma + y;
    }
    cout << suma;
    return 0;
}
