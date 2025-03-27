#include <stdio.h>
#include <stdlib.h>


/*
QUESTÃO 02 - Revise a implementação das funções a seguir para as filas:
a) Inserção
b) Remoção
c) Impressão


ESSA VERSÃO É UMA IMPLEMENTACAO DA FILA SEM USAR STRUCT QUEUE
POR ISSO TEMOS PONTEIROS COM **

*/

// Estrutura do nó da fila
typedef struct Node {
    int data;
    struct Node *next;
} Node;

// Função para enfileirar um elemento
void enqueue(Node **head, Node **tail, int value) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    if (!*tail) {
        *head = newNode;
    } else {
        (*tail)->next = newNode;
    }
    *tail = newNode;
}


// Função para desenfileirar um elemento
int dequeue(Node **head, Node **tail) {
    if (!*head) return -1;
    Node *temp = *head;
    int value = temp->data;
    *head = (*head)->next;
    if (!*head) *tail = NULL;
    free(temp);
    return value;
}

void display(Node *head){
    if(!head){
        printf("NULL");
        return;
    }

    while(head){
        printf("%d", head->data);
        if(head->next){
        printf("->");
        }
        head=head->next;
    }
}


int main(){
    Node *head1 = NULL, *tail1 = NULL;

    enqueue(&head1, &tail1, 10);
    enqueue(&head1, &tail1, 20);
    enqueue(&head1, &tail1, 30);
    enqueue(&head1, &tail1, 40);
    display(head1);
    dequeue(&head1, &tail1);
    printf("\n");
    display(head1);
    return 0;
}