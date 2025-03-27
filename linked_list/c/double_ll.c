#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
}Node;

void insert_first(Node **head, int value);
void insert_last(Node **head, int value);
void insert_before_x(Node **head, int target, int value);
void insert_after_x(Node **head, int target, int value);
void remve_first(Node **head);
void remove_last(Node **head);
void free_list(Node **head);
void display(Node *head);


void insert_first(Node **head, int value){
    Node *newNode = malloc(sizeof(Node));

    newNode->data= value;
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
    
    Node *newNode = malloc(sizeof(Node));
    newNode->data=value;
    newNode->next=NULL;

    Node *walk=*head;
    while (walk->next!=NULL){
        walk=walk->next;
    }
    newNode->prev=walk;
    walk->next=newNode; // 3-> 4 -> 5 -> null
}

void insert_before_x(Node **head, int target, int value){
    if(*head==NULL){
        insert_first(head, value);
        return;
    }

    Node *newNode = malloc(sizeof(Node));

    newNode->data=value;
    Node *walk = *head;
    while(walk->next!=NULL && walk->next->data!=target){ // ex target = 3, value = 12 | [4 -> 3 -> 5]
        walk=walk->next;
    }

    if(walk->next==NULL) {
        insert_last(head, value); 
        return;
    }
    newNode->prev=walk;
    newNode->next=walk->next;
    walk->next->prev=newNode;
    walk->next=newNode;

}

void insert_after_x(Node **head, int target, int value){
    if(*head==NULL){
        insert_first(head, value);
        return;
    }
    Node *newNode = malloc(sizeof(Node));

    newNode->data=value;
    Node *walk = *head;

    while(walk->next!=NULL && walk->data!=target){ // ex target = 3, value = 12 | [4 -> 3 -> 5]
        walk=walk->next;
    }
    if(walk->next==NULL) {
        insert_last(head, value); 
        return;
    }
    newNode->prev=walk;
    newNode->next=walk->next;
    walk->next->prev=newNode;
    walk->next=newNode;
}

void remove_first(Node **head){
    if(*head == NULL) return;

    Node *current=*head;
    int removed_value = current->data;
    *head=(*head)->next;
    if (*head != NULL) {
        (*head)->prev = NULL;
    }
    free(current);
    printf("Removed first value: %d\n", removed_value);
}

void remove_last(Node **head){
    if(*head == NULL) return;
    Node *walk=*head;
    if(walk->next==NULL){
        int removed_value = walk->data;
        free(walk);
        *head = NULL;
        printf("Removed last value: %d\n", removed_value);
        return;
    }
    while(walk->next->next){
        walk=walk->next;
    }
    int removed_value = walk->next->data;
    free(walk->next);
    walk->next=NULL;
    printf("Removed last value: %d\n", removed_value);
}

void remove_x(Node **head, int target){
    if(*head == NULL) return;
    
    // If target is the first node
    if((*head)->data == target) {
        Node *temp = *head;
        *head = (*head)->next;
        if(*head != NULL) {
            (*head)->prev = NULL;
        }
        free(temp);
        printf("Removed value: %d\n", target);
        return;
    }
    
    Node *walk=*head;
    while(walk->next && walk->next->data!=target){
        walk=walk->next;
    }

    if(walk->next==NULL){
        return;
    }

    Node *trashed = walk->next;
    walk->next=trashed->next;
    if(trashed->next != NULL) {
        trashed->next->prev = walk;
    }
    free(trashed);
    printf("Removed value: %d\n", target);
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
    printf("\n");

}

void display_reverse(Node *head){
    if(!head){
        printf("NULL");
        return;
    }

    while(head->next){
        head=head->next;
    }
    while (head){
        printf("%d", head->data);
        if(head->prev){
            printf("<-");
        }

        head=head->prev;
    }
    printf("\n");
    

}

void free_list(Node **head){
    Node *current;
    while((*head)){
        current = *head;
        *head = (*head)->next;
        free(current);
    }
    printf("Memory was freed!\n");
    
}


int main() {
    Node *head = NULL;
    int choice, value, target;
    
    while (1) {
        printf("\n--- Doubly Linked List Operations ---\n");
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
                free_list(&head);
                return 0;
            case 1:
                system("clear");

                printf("Enter value: ");
                scanf("%d", &value);
                insert_first(&head, value);
                break;
            case 2:
                system("clear");
            
                printf("Enter value: ");
                scanf("%d", &value);
                insert_last(&head, value);
                break;
            case 3:
                system("clear");

                printf("Enter target value: ");
                scanf("%d", &target);
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insert_before_x(&head, target, value);
                break;
            case 4:
                system("clear");

                printf("Enter target value: ");
                scanf("%d", &target);
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insert_after_x(&head, target, value);
                break;
            case 5:
                remove_first(&head);
                break;
            case 6:
                remove_last(&head);
                break;
            case 7:
                printf("Enter value to remove: ");
                scanf("%d", &value);
                remove_x(&head, value);
                break;
            case 8:
                system("clear");

                printf("List forward: ");
                display(head);
                break;
            case 9:
                system("clear");

                printf("List backward: ");
                display_reverse(head);
                break;
            default:
                printf("Invalid choice!\n");
        }
    }
    
    return 0;
}