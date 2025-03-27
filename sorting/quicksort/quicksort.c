#include <stdio.h>

int partition(int arr[], int startIndex, int endIndex);
void quicksort(int arr[], int startIndex, int endIndex);
void swap(int arr[], int i, int j);

void swap(int arr[], int i, int j){
    int aux = arr[i];
    arr[i]= arr[j];
    arr[j]=aux;
}

int partition(int arr[], int startIndex, int endIndex){
    int pivot = arr[startIndex];

    int pivotIndex = endIndex;

    for(int i = endIndex ; i > startIndex ; i--){
        if(arr[i]>= pivot){
            swap(arr, i, pivotIndex);
            pivotIndex--;
        }
    }
    swap(arr, startIndex, pivotIndex);
    return pivotIndex;
}

void quicksort(int arr[], int startIndex, int endIndex){
    if(startIndex < endIndex){
        int pivotIndex = partition(arr, startIndex, endIndex);

        quicksort(arr, startIndex, pivotIndex-1);

        quicksort(arr, pivotIndex+1, endIndex);
    
    }
}

int main(){
    int arr[] = {6, 5, 4, 3, 2, 1};
    quicksort(arr, 0, 5);
    for(int i = 0; i < 6; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}