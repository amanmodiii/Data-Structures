#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int flag = 0;
void printArray(int *arr, int len)
{
    int i;
    for (i = 0; i < len; i++)
    {
        printf("%d\t", *(arr + i));
    }
    printf("\n");
}

void recursiveBinarySearch(int *arr, int val, int start, int end)
{
    int i;
    int mid;
    if(start <= end)
    {
        mid = start + (end - start) / 2;
        if (val < *(arr + mid))
            recursiveBinarySearch(arr,val,start,mid-1);
        else if (val > *(arr + mid))
            recursiveBinarySearch(arr, val, mid+1, end);
        else{
            printf("\n\n %d is present at position %d in the array. \n\n", val, mid + 1);
            flag=1;
        }
    }
}

int main()
{
    int len;
    int *arr;
    printf("Enter size of the array : ");
    scanf("%d", &len);
    arr = (int *)malloc(len * sizeof(int));
    printf("Enter the Elements in increasing order : ");
    int i;
    int val;
    for (i = 0; i < len; i++)
        scanf("%d", (arr + i));
    printf("Enter the Search Value : ");
    scanf("%d", &val);
    printf("\n\n-------------BINARY SEARCH----------------\n\n");
    recursiveBinarySearch(arr, val, 0, len-1);
    if(!flag)
        printf("%d is not present in the array . \n\n",val);
    printf("\nThe Array is :\n");
    printArray(arr, len);

    return 0;
}