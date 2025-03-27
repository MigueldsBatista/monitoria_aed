#Implementaçã do pivot como primeiro elemento

def quicksort(arr: list, startIndex, endIndex) -> list:
    if(startIndex < endIndex):
        pivotIndex = partition(arr, startIndex, endIndex)

        quicksort(arr, startIndex, pivotIndex-1)

        quicksort(arr, pivotIndex+1, endIndex)

def partition(arr: list, startIndex, endIndex) -> int:

    pivot = arr[startIndex]

    pivotIndex = endIndex

    i = endIndex
    while(i > startIndex):
        if(arr[i]>=pivot):
            arr[i], arr[pivotIndex] = arr[pivotIndex], arr[i]
            pivotIndex-=1
        i-=1
    arr[startIndex], arr[pivotIndex] = arr[pivotIndex], arr[startIndex]
    return pivotIndex

arr=[6, 5, 4, 3, 2, 1]

quicksort(arr, 0, 5)

print(arr)