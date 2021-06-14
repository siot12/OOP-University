#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

int main()
{
    char a[100], aux[100], c[] = " ";
    char* s;
    char cuv[20][100];
    int i, k = 0, j, n, m;
    scanf("%[^\t\n]", a);
    s = strtok(a, c);
    while (s != 0)
    {
        k++;
        strcpy(cuv[k], s);
        s = strtok(NULL, c);
    }
    for (i = 1;i <= k - 1;i++)
    {
        for (j = i + 1;j <= k;j++)
        {
            n = strlen(cuv[i]);
            m = strlen(cuv[j]);
            if (n < m)
            {
                swap(cuv[i], cuv[j]);
            }
            else
            {
                if (n == m)
                {
                    //cazul in care ordonam alfabetic
                }
            }

        }
    }

    for (i = 1;i <= k;i++)
    {
        cout << cuv[i] << endl;
    }

    return 0;

}
