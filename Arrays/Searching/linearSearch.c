#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void printArray(int *arr, int len)
{
    int i;
    for (i = 0; i < len; i++)
    {
        printf("%d\t", *(arr + i));
    }
    printf("\n");
}

void linearSearch(int *arr, int len, int val)
{
    int i,flag=0;
    for (i = 0; i < len; i++)
    {
        if(*(arr+i)==val){
            flag=1;
            break;
        }
    }
    if(flag==1)
        printf("\n\n %d is present at position %d in the array. \n\n",val,i+1);
    else
        printf("\n\n %d is not present in the array. \n\n", val);
}

int main()
{
    int len;
    int *arr;
    printf("Enter size of the array : ");
    scanf("%d", &len);
    arr = (int *)malloc(len * sizeof(int));
    printf("Enter the Elements : ");
    int i;
    int val;
    for (i = 0; i < len; i++)
        scanf("%d", (arr + i));
    printf("Enter the Search Value : ");
    scanf("%d",&val);
    printf("\n\n-------------LINEAR SEARCH----------------\n\n");
    linearSearch(arr, len, val);
    printf("\nThe Array is :\n");
    printArray(arr, len);

    return 0;
}