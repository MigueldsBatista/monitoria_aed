#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
} Node;

// Função para criar um novo nó
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) return NULL;
    newNode->data = data;
    newNode->prev = newNode->next = NULL;
    return newNode;
}

// 01 - Inserção ordenada na lista duplamente encadeada
void insertSorted(Node** head, int data) {
    Node* newNode = createNode(data);
    if (!newNode) return;

    if (!*head) { 
        *head = newNode; 
        return; 
    }

    Node* current = *head;
    while (current->next && current->next->data < data) {
        current = current->next;
    }
    
    if (current->data >= data) { // Inserção no início
        newNode->next = current;
        current->prev = newNode;
        *head = newNode;
        return;
    }

    newNode->next = current->next;
    newNode->prev = current;
    if (current->next) current->next->prev = newNode;
    current->next = newNode;
}

// 02 - Intercalar elementos de duas listas ordenadas
Node* mergeLists(Node* head1, Node* head2) {
    if (!head1) return head2;
    if (!head2) return head1;

    Node* head = NULL, **tail = &head;
    while (head1 && head2) {
        if (head1->data <= head2->data) {
            *tail = head1;
            head1 = head1->next;
        } else {
            *tail = head2;
            head2 = head2->next;
        }
        (*tail)->prev = (Node*)tail;
        tail = &((*tail)->next);
    }
    *tail = head1 ? head1 : head2;
    return head;
}

// 03 - Buscar nó e contar elementos antes e depois dele
void countBeforeAfter(Node* head, int value) {
    Node* current = head;
    while (current && current->data != value) {
        current = current->next;
    }
    if (!current) {
        printf("Nó não encontrado.\n");
        return;
    }

    int before = 0, after = 0;
    Node* temp = current->prev;
    while (temp) {
        before++;
        temp = temp->prev;
    }
    
    temp = current->next;
    while (temp) {
        after++;
        temp = temp->next;
    }

    printf("Antes: %d, Depois: %d\n", before, after);
}
