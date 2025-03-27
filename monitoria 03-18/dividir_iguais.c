#include <stdio.h>
#include <stdlib.h>

// Estrutura de um nó da fila
typedef struct Node {
    int valor;          // Armazena o valor do nó
    struct Node *proximo; // Ponteiro para o próximo nó na fila
} Node;


/*
QUESTÃO 05 - Um determinado programa será implementado em C e deve permitir manipular
números em uma Fila. Crie uma nova função que imprima a divisão dos valores de duplas de nós
que estão nesta fila. Se tiver uma quantidade ímpar de nós (sobrando um nó), para o nó restante,
divida o valor dele por 10. E se a fila tiver menos que 2 nós, exiba a seguinte mensagem:
“Tamanho da fila é insuficiente :(” e também não pode ocorrer divisão por ze

*/

// Função que percorre a fila e realiza a divisão dos elementos em pares
void divisao(Node *head, Node *tail) {
    // Verifica se a fila tem elementos suficientes para a operação
    if (!head || !head->proximo) {
        printf("Tamanho da fila é insuficiente :(\n");
        return;
    }

    Node *atual = head;
    // Percorre a fila de dois em dois elementos
    while (atual && atual->proximo) {
        if (atual->proximo->valor != 0) {
            // Exibe o resultado da divisão
            printf("%d / %d = %.2f\n", atual->valor, atual->proximo->valor, (float)atual->valor / atual->proximo->valor);
        } else {
            // Trata o caso de divisão por zero
            printf("%d / %d = Erro (divisão por zero)\n", atual->valor, atual->proximo->valor);
        }
        atual = atual->proximo->proximo; // Avança dois nós na fila
    }
    
    // Caso a fila tenha um número ímpar de elementos, divide o último por 10
    if (atual) {
        printf("%d / 10 = %.2f\n", atual->valor, (float)atual->valor / 10);
    }
}





// Função para adicionar um elemento ao final da fila
void enqueue(Node **head, Node **tail, int valor) {
    Node *novo = (Node *)malloc(sizeof(Node)); // Aloca memória para um novo nó
    if (!novo) return;
    novo->valor = valor;
    novo->proximo = NULL;
    
    if (*tail) {
        (*tail)->proximo = novo; // Atualiza o último nó atual para apontar para o novo
    } else {
        *head = novo; // Se a fila estava vazia, o novo nó é também o primeiro
    }
    *tail = novo; // Atualiza o ponteiro do último nó
}

// Função para liberar a memória alocada para a fila
void liberarFila(Node *head) {
    while (head) {
        Node *temp = head;
        head = head->proximo;
        free(temp); // Libera a memória do nó atual
    }
}

int main() {
    Node *head = NULL, *tail = NULL; // Inicializa a fila vazia
    
    // Insere elementos na fila
    enqueue(&head, &tail, 8);
    enqueue(&head, &tail, 4);
    enqueue(&head, &tail, 15);
    enqueue(&head, &tail, 3);
    enqueue(&head, &tail, 10);
    enqueue(&head, &tail, 10);
    
    // Chama a função para processar as divisões
    divisao(head, tail);
    
    // Libera a memória antes de encerrar o programa
    liberarFila(head);
    
    return 0;
}
