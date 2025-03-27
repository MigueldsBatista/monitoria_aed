/*
INSERTION SORT

- Analisa cada elemento com o elemento a esquerda, primeiramente se seleciona o segundo elemento do vetor
para iniciar as comparações;
- Comparações em pares;
- Elementos à esquerda estarão sempre ordenados em ordem crescente ou descrescente;
- Ordenação in-place, executada dentro do mesmo vetor;
- Estrutura de repetição será executada n-1 vezes;
- Pior caso: vetor com elementos na ordem inversa O(n^2)
- Melhor caso: vetor com elementos ordenados O(n), segundo laço não é executado;

*/

#include <stdio.h>
#define MAX 6

int main(){

    int vetor[MAX] = {4, 3, 6, 1, 9, 11};

    for(int i=1; i<MAX; i++){
        int k=i;
        while(vetor[k] < vetor[k-1] && k>0){
            int temp = vetor[k-1];
            vetor[k-1] = vetor[k];
            vetor[k] = temp;
            k--;
        }
    }

    for(int i=0; i<MAX; i++){
        printf("%d ", vetor[i]);
    }

    return 0;
}