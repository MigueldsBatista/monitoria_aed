#include <stdio.h>
#include <malloc.h>
typedef struct Node{
    int data;
    struct Node* next;
    struct Node* prev;
}Node;

// Function declarations
void insertFirst(Node **head, Node **tail, int num);
void insertLast(Node **head, Node **tail, int num);
void insertOrdered(Node **head, Node **tail, int value);
void insertBeforeX(Node **head, Node **tail, int element_after, int value);
void insertAfterX(Node **head, Node **tail, int element_before, int value);
void removeFirst(Node **head, Node **tail);
void removeLast(Node **head, Node **tail);
void removeX(Node **head, Node **tail, int target);
void display(Node *head, Node *tail);
void freeList(Node **head, Node **tail);

int main(){
    Node *head=NULL;
    Node *tail=NULL;
    int op, num, before, target;
    do{
        display(head, tail);
        printf("1- Inserir no início\n");
        printf("2- Inserir no final\n");
        printf("3- Inserir Ordenado\n");
        printf("4- Inserir antes de um elemento\n");
        printf("5- Inserir depois de um elemento\n");
        printf("6- Remover do início\n");
        printf("7- Remover do final\n");
        printf("8- Remover elemento específico\n");
        printf("0- Sair\n");
        printf("Escolha sua opção: ");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            printf("Numero: ");
            scanf("%d", &num);
            insertFirst(&head, &tail, num);
            break;
        case 2:
            printf("Numero: ");
            scanf("%d", &num);
            insertLast(&head, &tail, num);
            break;
        case 3:
            printf("Numero: ");
            scanf("%d", &num);
            insertOrdered(&head, &tail, num);
            break;
        case 4:
            printf("Numero a inserir: ");
            scanf("%d", &num);
            printf("Inserir antes de qual elemento: ");
            scanf("%d", &before);
            insertBeforeX(&head, &tail, before, num);
            break;
        case 5:
            printf("Numero a inserir: ");
            scanf("%d", &num);
            printf("Inserir depois de qual elemento: ");
            scanf("%d", &before);
            insertAfterX(&head, &tail, before, num);
            break;
        case 6:
            removeFirst(&head, &tail);
            printf("Elemento do início removido\n");
            break;
        case 7:
            removeLast(&head, &tail);
            printf("Elemento do final removido\n");
            break;
        case 8:
            printf("Elemento a remover: ");
            scanf("%d", &target);
            removeX(&head, &tail, target);
            break;
        default:
            if(op != 0)
                printf("Opção inválida!\n");
            break;
        }
    }while (op!=0);

    freeList(&head, &tail);
    return 0;
}

void insertLast(Node **head, Node **tail, int num){
    Node *newNode=(Node*)malloc(sizeof(Node));
    newNode->data=num;
    newNode->next=*head;
    newNode->prev=*tail;
    
// [3] <-> [4] <-> [6] <-> [3] <--> *(2)

    if(*head==NULL){
        newNode->next=newNode;
        newNode->prev=newNode;
        *head=newNode;
        *tail=newNode;
        return;
    }
        (*tail)->next = newNode;  // O antigo último nó aponta para o novo nó
        (*head)->prev=newNode;
        *tail=newNode;
    
}

void insertFirst(Node **head, Node **tail, int num){
    Node *newNode=(Node*)malloc(sizeof(Node));

    newNode->data=num;
    newNode->next=*head;
    newNode->prev=*tail;

    if(*head==NULL){
        newNode->next=newNode;
        newNode->prev=newNode;
        *head=newNode;
        *tail=*head;
        return;
    }
    (*head)->prev=newNode;
    (*tail)->next=newNode;
    *head=newNode;
}
void insertBeforeX(Node **head, Node **tail, int element_after, int value){
    if(*head == NULL) {
        insertFirst(head, tail, value);
        return;
    }
    
    // If target is at head, insert at beginning
    if((*head)->data == element_after) {
        insertFirst(head, tail, value);
        return;
    }
    
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    
    Node *walk = *head;
    do {
        if(walk->next->data == element_after) {
            newNode->prev = walk;
            newNode->next = walk->next;
            walk->next->prev = newNode;
            walk->next = newNode;
            return;
        }
        walk = walk->next;
    } while(walk != *head);
    
    // Element not found, insert at the end
    free(newNode);
    printf("Elemento %d não encontrado, inserindo no final\n", element_after);
    insertLast(head, tail, value);
}

void insertAfterX(Node **head, Node **tail, int element_before, int value){
    if(*head == NULL) {
        insertFirst(head, tail, value);
        return;
    }
    
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    
    Node *walk = *head;
    do {
        if(walk->data == element_before) {
            newNode->prev = walk;
            newNode->next = walk->next;
            walk->next->prev = newNode;
            walk->next = newNode;
            
            // Update tail if needed
            if(walk == *tail) {
                *tail = newNode;// if the new node is inserted after the tail
            }
            return;
        }
        walk = walk->next;
    } while(walk != *head);
    
    // Element not found, insert at the end
    free(newNode);
    printf("Elemento %d não encontrado, inserindo no final\n", element_before);
    insertLast(head, tail, value);
}

void insertOrdered(Node **head, Node **tail, int value){
    if(*head == NULL || (*head)->data >= value) {
        insertFirst(head, tail, value);
        return;
    }
    
    if((*tail)->data <= value) {
        insertLast(head, tail, value);
        return;
    }
    
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    
    Node *walk = *head;
    do {
        if(walk->data <= value && walk->next->data >= value) {
            newNode->prev = walk;
            newNode->next = walk->next;
            walk->next->prev = newNode;
            walk->next = newNode;
            return;
        }
        walk = walk->next;
    } while(walk != *head);
}

void removeFirst(struct Node **head, struct Node **tail){
    if(!(*head)) return;

    struct Node *delete=*head;

    if (*head == *tail) {
        *head = *tail = NULL;
        free(delete);
        return;
    }
    
    (*head) = (*head)->next;
    (*tail)->next = (*head);
    (*head)->prev = *tail;
    free(delete);
}

void removeLast(struct Node **head, struct Node **tail){
    if(!(*head)) return;

    if (*head == *tail) {
        free(*head); // Fix: free the only node properly
        *head = *tail = NULL;
        return;
    } 
    
    struct Node *delete = *tail; // Fix: track the node to delete
    struct Node *walk = *head;
    
    while (walk->next != *tail)
    {
        walk = walk->next;
    }

    walk->next = *head;
    (*head)->prev = walk; // Fix: update prev pointer for head
    *tail = walk;
    
    free(delete); // Fix: properly free the deleted node
}

void removeX(Node **head, Node **tail, int target){
    if(*head == NULL) return;

    // If only one node in list
    if(*head == *tail) {
        if((*head)->data == target) {
            free(*head);
            *head = *tail = NULL;
            printf("Elemento %d removido\n", target);
            return;
        }
        printf("Elemento %d não encontrado\n", target);
        return;
    }
    
    // If target is at head
    if((*head)->data == target) {
        removeFirst(head, tail);
        printf("Elemento %d removido do início\n", target);
        return;
    }
    
    // If target is at tail
    if((*tail)->data == target) {
        removeLast(head, tail);
        printf("Elemento %d removido do final\n", target);
        return;
    }
    
    // Target is somewhere in the middle
    Node *walk = *head;
    do {
        if(walk->next->data == target) {
            Node *delete = walk->next;
            walk->next = delete->next;
            delete->next->prev = walk;
            printf("Elemento %d removido\n", target);
            free(delete);
            return;
        }
        walk = walk->next;
    } while(walk != *head);
    
    printf("Elemento %d não encontrado\n", target);
}

void display(Node *head, Node *tail){
    if(head==NULL) return;
    
    Node *walk=head;
    printf("NORMAL: \n");
    do{
        printf("%d  <-> ", walk->data);
        walk=walk->next;
    }while(walk!=head);
    printf("\n");

    walk=tail;

    printf("INVERTIDA: \n");
    do{
        printf("%d  <-> ", walk->data);
        walk=walk->prev;
    }while(walk!=tail);
    printf("\n");


}

void freeList(Node **head, Node **tail) {
    if(*head == NULL) return;
    
    Node *current = *head;
    Node *next;
    
    do {
        next = current->next;
        free(current);
        current = next;
    } while(current != *head);
    
    *head = NULL;
    *tail = NULL;
}
