#include <stdio.h>
#include <stdlib.h>

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

// Função para verificar e excluir valores repetidos em Fila2
void excluirIguais(Node **head1, Node **tail1, Node **head2, Node **tail2) {

    if (!head1 || !head2 || !*head1 || !*head2) return;

    Node *walk1 = *head1;
    while (walk1) {
        Node *prev = NULL;
        Node *walk2 = *head2;

        while (walk2) {
            if (walk1->data != walk2->data) { // Se os valores forem diferentes, continua
                prev = walk2; // Sempre mantemos uma referência para o nó anterior
                walk2 = walk2->next;// Aqui avançamos pro proximo simplismente pra andar na lista
                continue; 
            }

            Node *temp = walk2; // Temp é o nó que será removido

            walk2 = walk2->next; // Aqui andamos pra remover o nó repetido

            if (!prev) *head2 = walk2; // Caso o primeiro if seja falso na primeira iteração, quer dizer que o nó removido é o primeiro da lista

            else prev->next = walk2; // Caso o primeiro if seja satisfeito, o nó anterior ao removido aponta para o próximo
            
            if (*tail2 == temp) *tail2 = prev;// Caso o nó removido seja o último, o tail aponta para o anterior
            
            free(temp);
        }
        walk1 = walk1->next; // Aqui andamos na lista 1
    }
}


// Função para imprimir a fila
void printQueue(Node *head) {
    while (head) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    Node *head1 = NULL, *tail1 = NULL;
    Node *head2 = NULL, *tail2 = NULL;
    
    // Inserindo elementos nas filas
    enqueue(&head1, &tail1, 3);
    enqueue(&head1, &tail1, 7);
    enqueue(&head1, &tail1, 10);
    
    enqueue(&head2, &tail2, 5);
    enqueue(&head2, &tail2, 3);
    enqueue(&head2, &tail2, 8);
    enqueue(&head2, &tail2, 10);
    
    printf("Fila1 antes: ");
    printQueue(head1);
    printf("Fila2 antes: ");
    printQueue(head2);
    
    excluirIguais(&head1, &tail1, &head2, &tail2);
    
    printf("Fila1 depois: ");
    printQueue(head1);
    printf("Fila2 depois: ");
    printQueue(head2);
    
    return 0;
}
