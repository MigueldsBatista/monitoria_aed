#include <stdio.h>
#define LEN 6
/*

QUESTÃO 06 - Explique os seguintes algoritmos de ordenação e suas respectivas complexidades
de tempo, também escreva o código para cada um deles.
a) Bubble Sort V0
b) Bubble Sort V1
c) Bubble Sort V2

d) Insertion Sort -> insertion.c

*/


void print_array(int v[], int len) {
    for(int i = 0; i < len; i++) {
        printf(" %d ", v[i]);
    }
}

void bubblesortv0(int v[], int len) {
    
    for (int i = 1; i <= len - 1; i++) {
        for (int j = 0; j < len - 1; j++) {
            if (v[j] > v[j + 1]) {
                int aux = v[j]; 
                v[j] = v[j + 1];
                v[j + 1] = aux;
            }
        }
    }
} 

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

void bubblesortv2(int v[], int len) {
    int i = 1; int troca = 1;

    while(i <= len - 1 && troca == 1)  {
        troca = 0;
        for (int j = 0; j < len - 1; j++) {
            if (v[j] > v[j + 1]) {
                int aux = v[j]; 
                v[j] = v[j + 1];
                v[j + 1] = aux;
                troca = 1;
            }
        }
        i++;
    }  
}

int main() {

    int v[LEN] = {6, 5, 4, 3, 2, 1};
    
    bubblesortv0(v, LEN);
    
    print_array(v, LEN);

    return 0;
}