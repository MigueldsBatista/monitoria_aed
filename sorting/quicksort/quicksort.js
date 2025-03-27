function quicksort(arr, startIndex, endIndex){
    if(startIndex < endIndex){
        let pivotIndex = partition(arr, startIndex, endIndex);
        quicksort(arr, startIndex, pivotIndex - 1);
        quicksort(arr, pivotIndex + 1, endIndex);
    }
}
function swap(arr, i, j){
    let aux = arr[i];
    arr[i] = arr[j];
    arr[j] = aux;
}

function partition(arr, startIndex, endIndex){
    let pivot = arr[startIndex];
    let pivotIndex = endIndex;

    for(let i = endIndex; i > startIndex; i--){
        if(arr[i] >= pivot){
            swap(arr, i, pivotIndex);
            pivotIndex--;
        }
    }
    swap(arr, startIndex, pivotIndex);

    return pivotIndex;
}

let arr = [6, 5, 4, 3, 2, 1];
quicksort(arr, 0, arr.length - 1);
console.log(arr); // [1, 2, 3, 4, 5, 6]