#include <stdio.h>
void bubble_sort(int arr[], int n);

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
    bubble_sort(numarr,n);
    for(i=0;i<n;i++)
    {
        printf("%i\t",numarr[i]);
    }

    return 0;
}

void bubble_sort(int arr[], int n)
{
    int i,j,temp;
    for(i=0;i<(n-1);i++)
    {
        for(j=0;j<(n-1-i);j++)
        {
            if(arr[j] > arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}