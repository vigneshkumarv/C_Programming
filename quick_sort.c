/* Quick Sort in decending order */

#include <stdio.h>
#include <stdlib.h>

#define MYSIZEOF(a) ((char*)(&a+1) - (char*)(&a))

void swap(int *a, int *b);
int partition(int *arr, int low, int high);
void quicksort(int *arr, int low, int high);

int main(void)
{
    int arr[] = {10, 50, 30, 40, 15, 70, 35};
    int size = (MYSIZEOF(arr)/MYSIZEOF(arr[0]));
    quicksort(arr, 0, size-1);
    for(int i = 0; i<size; i++){
        printf("%d\t",arr[i]);
    }
    return 0;
}

void swap(int *a, int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int *arr, int low, int high){
    int i, j, pivot = arr[high];
    i = low-1;
    for(j=low;j<high;j++){
        if(arr[j] > pivot){
            i++;
            swap(&arr[i],&arr[j]);
        }
    }
    swap(&arr[i+1],&arr[high]);
    return (i+1);
}

void quicksort(int *arr, int low, int high){
    if(low < high){
        int pi = partition(arr, low, high);
        
        quicksort(arr, low, pi-1);
        quicksort(arr, pi+1, high);
    }
}