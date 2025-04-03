#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
}Node;

void insert_first(Node **head, Node **tail, int value);
void insert_last(Node **head, Node **tail, int value);
void insert_before_x(Node **head, Node **tail, int target, int value);
void insert_after_x(Node **head, Node **tail, int target, int value);
void remove_first(Node **head, Node **tail);
void remove_last(Node **head, Node **tail);
void remove_x(Node **head, Node **tail, int target);
void free_list(Node **head, Node **tail);
void display(Node *head, Node *tail);
void display_reverse(Node *head, Node *tail);

void insert_first(Node **head, Node **tail, int value){
    Node *newNode = malloc(sizeof(Node));

    newNode->data = value;

    if(*head == NULL){
        newNode->prev = newNode;
        newNode->next = newNode;
        *head = *tail = newNode;
    } else {
        newNode->prev = *tail;
        newNode->next = *head;
        (*head)->prev = newNode;
        (*tail)->next = newNode;
        *head = newNode;
    }
}

void insert_last(Node **head, Node **tail, int value){
    if(*head == NULL){
        insert_first(head, tail, value);
        return;
    }
    
    Node *newNode = malloc(sizeof(Node));
    newNode->data = value;
    
    newNode->next = *head;
    newNode->prev = *tail;
    (*tail)->next = newNode;
    (*head)->prev = newNode;
    *tail = newNode;
}

void insert_before_x(Node **head, Node **tail, int target, int value){
    if(*head == NULL){
        insert_first(head, tail, value);
        return;
    }

    // If target is the first node
    if((*head)->data == target) {
        insert_first(head, tail, value);
        return;
    }

    Node *walk = *head;
    do {
        if(walk->next->data == target) {
            Node *newNode = malloc(sizeof(Node));
            newNode->data = value;
            newNode->prev = walk;
            newNode->next = walk->next;
            walk->next->prev = newNode;
            walk->next = newNode;
            return;
        }
        walk = walk->next;
    } while(walk != *head);

    // Target not found, insert at end
    insert_last(head, tail, value);
}

void insert_after_x(Node **head, Node **tail, int target, int value){
    if(*head == NULL){
        insert_first(head, tail, value);
        return;
    }

    Node *walk = *head;
    do {
        if(walk->data == target) {
            // If target is the last node
            if(walk == *tail) {
                insert_last(head, tail, value);
                return;
            }
            
            Node *newNode = malloc(sizeof(Node));
            newNode->data = value;
            newNode->prev = walk;
            newNode->next = walk->next;
            walk->next->prev = newNode;
            walk->next = newNode;
            return;
        }
        walk = walk->next;
    } while(walk != *head);

    // Target not found, insert at end
    insert_last(head, tail, value);
}

void remove_first(Node **head, Node **tail){
    if(*head == NULL) return;

    Node *temp = *head;
    int removed_value = temp->data;
    
    if(*head == *tail) {
        // Only one node in list
        free(temp);
        *head = *tail = NULL;
    } else {
        *head = (*head)->next;
        (*head)->prev = *tail;
        (*tail)->next = *head;
        free(temp);
    }
    
    printf("Removed first value: %d\n", removed_value);
}

void remove_last(Node **head, Node **tail){
    if(*head == NULL) return;
    
    Node *temp = *tail;
    int removed_value = temp->data;
    
    if(*head == *tail) {
        // Only one node in list
        free(temp);
        *head = *tail = NULL;
    } else {
        *tail = (*tail)->prev;
        (*tail)->next = *head;
        (*head)->prev = *tail;
        free(temp);
    }
    
    printf("Removed last value: %d\n", removed_value);
}

void remove_x(Node **head, Node **tail, int target){
    if(*head == NULL) return;
    
    // If target is the first node
    if((*head)->data == target) {
        remove_first(head, tail);
        return;
    }
    
    // If target is the last node
    if((*tail)->data == target) {
        remove_last(head, tail);
        return;
    }
    Node *walk = *head;
    do {
        if(walk->data == target) {
            walk->prev->next = walk->next;
            walk->next->prev = walk->prev;
            free(walk);
            printf("Removed value: %d\n", target);
            return;
        }
        walk = walk->next;
    } while(walk != *head);
}

void display(Node *head, Node *tail){
    if(!head){
        printf("NULL\n");
        return;
    }

    Node *temp = head;
    do {
        printf("%d", temp->data);
        temp = temp->next;
        if(temp != head) {
            printf("->");
        }
    } while(temp != head);

    printf("\n");
}

void display_reverse(Node *head, Node *tail){
    if(!head){
        printf("NULL\n");
        return;
    }

    Node *temp = tail;
    do {
        printf("%d", temp->data);
        temp = temp->prev;
        if(temp != tail) {
            printf("<-");
        }
    } while(temp != tail);

    printf("\n");
}

void free_list(Node **head, Node **tail){
    if(*head == NULL) return;
    
    Node *current = *head;
    Node *next;
    
    do {
        next = current->next;
        free(current);
        current = next;
    } while(current != *head);
    
    *head = *tail = NULL;
    printf("Memory was freed!\n");
}

int main() {
    Node *head = NULL;
    Node *tail = NULL;
    int choice, value, target;
    
    while (1) {
        printf("\n--- Circular Doubly Linked List Operations ---\n");
        printf("1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Insert before a value\n");
        printf("4. Insert after a value\n");
        printf("5. Remove first node\n");
        printf("6. Remove last node\n");
        printf("7. Remove specific value\n");
        printf("8. Display forward\n");
        printf("9. Display backward\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 0:
                free_list(&head, &tail);
                return 0;
            case 1:
                system("clear");
                printf("Enter value: ");
                scanf("%d", &value);
                insert_first(&head, &tail, value);
                break;
            case 2:
                system("clear");
                printf("Enter value: ");
                scanf("%d", &value);
                insert_last(&head, &tail, value);
                break;
            case 3:
                system("clear");
                printf("Enter target value: ");
                scanf("%d", &target);
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insert_before_x(&head, &tail, target, value);
                break;
            case 4:
                system("clear");
                printf("Enter target value: ");
                scanf("%d", &target);
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insert_after_x(&head, &tail, target, value);
                break;
            case 5:
                remove_first(&head, &tail);
                break;
            case 6:
                remove_last(&head, &tail);
                break;
            case 7:
                printf("Enter value to remove: ");
                scanf("%d", &value);
                remove_x(&head, &tail, value);
                break;
            case 8:
                system("clear");
                printf("List forward: ");
                display(head, tail);
                break;
            case 9:
                system("clear");
                printf("List backward: ");
                display_reverse(head, tail);
                break;
            default:
                printf("Invalid choice!\n");
        }
    }
    
    return 0;
}
