#include <stdio.h>
void selection_sort(int arr[], int n);

int main()
{
    int numarr[50],n,i;
    printf("Enter number of elements in the array: ");
    scanf("%i",&n);
    for(i=0;i<n;i++)
    {
        printf("Enter element %i: ",i+1);
        scanf("%i",&numarr[i]);
    }
    selection_sort(numarr,n);
    for(i=0;i<n;i++)
    {
        printf("%i\t",numarr[i]);
    }

    return 0;
}

void selection_sort(int arr[], int n)
{
    int i,j,min,temp;
    for(i=0;i<n;i++)
    {
        min = i;
        for(j=i+1;j<n;j++)
        {
            if(arr[min]>arr[j])
            {
                temp = arr[min];
                arr[min] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

/* Version 2 */

/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define SWAP(x,y,t) ((t) = (x), (x) = (y), (y) = (t))

void selection_sort(int *num, int n);

int main(void)
{
    int num, i, *arr;
    printf("Enter no. of elements: ");
    scanf("%d",&num);
    if(num<1)
    {
        fprintf(stderr,"Invalid input!");
        exit(EXIT_FAILURE);
    }
    arr = (int *)malloc(num*sizeof(int));
    if(!arr)
    {
        fprintf(stderr,"Insufficient memory!");
        exit(EXIT_FAILURE);
    }
    memset(arr,'\0',num *sizeof(int));
    
    srand((unsigned) time(NULL));
    for(i=0;i<num;i++)
    {
        arr[i] = rand() % 100 + 1;
    }
    selection_sort(arr,num);
    printf("Sorted List:\n");
    for(i=0;i<num;i++)
    {
        printf("%d\t",arr[i]);
    }
    free(arr);
    arr = NULL;

    return (0);
}

void selection_sort(int *num, int n)
{
    int i, j, temp, min;
    for(i=0;i<n-1;i++)
    {
        min = i;
        for(j=i+1;j<n;j++)
        {
            if(num[j]<num[min])
            min = j;
            SWAP(num[i],num[min],temp);
        }
    }
}
*/