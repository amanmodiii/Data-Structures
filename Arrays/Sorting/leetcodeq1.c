#include<stdio.h>
#include<stdlib.h>

int main()
{
    int num=1234;
    int arr[4];
    int i, j;
    for (i = 0; i < 4; i++)
    {
        arr[i] = num % 10;
        num /= 10;
    }
    int a[12] = {0};
    int n1, n2, sum, min,c=0;
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            if (i == j)
                continue;
            else
            {
                a[c++] = arr[i] * 10 + arr[j];
            }
        }
    }
    for (i = 0; i < 12; i++)
        printf("%d\t", a[i]);
    return 0;
}