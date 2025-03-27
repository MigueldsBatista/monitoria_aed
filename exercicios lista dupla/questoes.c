#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
} Node;

// Function prototype
Node* create_node(int data);

void insert_first(Node **head, int value){
    Node *newNode = create_node(value);

    newNode->prev=NULL;
    if(*head!=NULL){
        (*head)->prev=newNode;
    }

    newNode->next=*head;
    *head=newNode;


}

void insert_last(Node **head, int value){
    if(*head==NULL){
        insert_first(head, value);
        return;
    }
    
    Node *newNode = create_node(value);

    newNode->next=NULL;

    Node *walk=*head;
    while (walk->next!=NULL){
        walk=walk->next;
    }
    newNode->prev=walk;
    walk->next=newNode; // 3-> 4 -> 5 -> null
}

// Função para criar um novo nó
Node* create_node(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) return NULL;
    newNode->data = data;
    newNode->prev = newNode->next = NULL;
    return newNode;
}
              
// 01 - Inserção ordenada na lista duplamente encadeada
void insert_sorted(Node** head, int data) {
    Node* newNode = create_node(data);
    if (!newNode) return;

    if (!*head) { 
        *head = newNode; 
        return; 
    }

    Node* walk = *head;
    while (walk->next && walk->next->data < data) {
        walk = walk->next;
    }
    
    if (walk->data >= data) { // Inserção no início
        newNode->next = walk;
        walk->prev = newNode;
        *head = newNode;
        return;
    }

    newNode->next = walk->next;
    newNode->prev = walk;
    if (walk->next) walk->next->prev = newNode;
    walk->next = newNode;
}

// 02 - Intercalar elementos de duas listas ordenadas
Node* intercalar_listas(Node *head1, Node *head2) {
    Node *new_head=NULL;
    Node *walk1 = head1;
    Node *walk2 = head2;
    
    while (walk1 != NULL || walk2 != NULL) {
        if (walk1 != NULL) {
            insert_last(&new_head, walk1->data);
            walk1 = walk1->next;
        }
        
        if (walk2 != NULL) {
            insert_last(&new_head, walk2->data);
            walk2 = walk2->next;
        }
    }
    
    return new_head;
}

// 03 - Buscar nó e contar elementos antes e depois dele
void cont_distance_to_edges(Node* head, int value) {
    Node* walk = head;
    while (walk && walk->data != value) {
        walk = walk->next;
    }
    if (!walk) {
        printf("Nó não encontrado.\n");
        return;
    }

    int before = 0, after = 0;

    Node* temp = walk->prev;//elemento anterior ao nó
    while (temp) {
        before++;
        temp = temp->prev;
    }
    
    temp = walk->next;// elemento posterior ao nó
    while (temp) {
        after++;
        temp = temp->next;
    }

    printf("Antes: %d\nDepois: %d", before, after);
}

int main()
{
    Node* head = NULL;
    insert_sorted(&head, 5);
    insert_sorted(&head, 3);
    insert_sorted(&head, 8);
    insert_sorted(&head, 1);
    
    printf("Lista ordenada: ");
    Node* walk = head;
    while (walk) {
        printf("%d ", walk->data);
        walk = walk->next;
    }
    printf("\n");

    cont_distance_to_edges(head, 3);

    return 0;
}
