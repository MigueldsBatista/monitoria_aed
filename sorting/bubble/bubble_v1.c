#include <stdio.h>


void bubblesortv1(int v[], int len) {
    
    for (int i = 1; i <= len - 1; i++) {
        for (int j = len - 1; j >= i; j--) {
            if (v[j] < v[j - 1]) {
                int aux = v[j];
                v[j] = v[j - 1];
                v[j - 1] = aux;
            }
        }
    }
}

int main() {
    int arr[] = {6, 5, 4, 3, 2, 1};
    int size = sizeof(arr) / sizeof(arr[0]);

    bubblesortv1(arr, size);

    for (int i = 0; i < size; i++) {
        printf("%d", arr[i]);
    }

    return 0;
}