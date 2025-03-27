#include <stdio.h>
#include <stdlib.h>

/*
QUESTÃO 02 - Revise a implementação das funções a seguir para as filas:
a) Inserção
b) Remoção
c) Impressão

OBS: ESSA VERSÃO DA FILA UTILIZA STRUCT QUEUE PARA MANIPULAÇÃO DA FILA
POR ISSO TEMOS PONTEIROS COM APENAS * E NÃO **
CASO NÃO TIVESSE A STRUCT QUEUE, SERIA NECESSÁRIO UTILIZAR **

*/
// Node structure for the queue
typedef struct Node {
    int data;
    struct Node *next;
} Node;

// Queue structure
typedef struct {
    Node *head;
    Node *tail;
} Queue;

// Function to initialize a queue
void initializeQueue(Queue *q) {
    q->head = NULL;
    q->tail = NULL;
}

// Function to enqueue (insert) an element into the queue
void enqueue(Queue *q, int value) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;

    if (q->tail == NULL) { // If the queue is empty
        q->head = newNode;
        q->tail = newNode;
    } else {
        q->tail->next = newNode;
        q->tail = newNode;
    }
}

// Function to print a queue
void printQueue(Queue *q, const char *queueName) {
    printf("%s: ", queueName);
    Node *temp = q->head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}


// Main function to test the implementation
int main() {
    Queue Fila01;
    initializeQueue(&Fila01);

    // Insert elements into Fila01
    enqueue(&Fila01, 10);
    enqueue(&Fila01, 20);
    enqueue(&Fila01, 30);
    enqueue(&Fila01, 40);

    printQueue(&Fila01, "Fila01");

    return 0;
}
