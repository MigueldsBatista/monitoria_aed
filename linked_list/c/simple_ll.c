#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
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

    newNode->next=walk->next;
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
    newNode->next=walk->next;
    walk->next=newNode;
}

void remove_first(Node **head){
    if(*head == NULL) return;

    Node *current=*head;
    *head=(*head)->next;
    free(current);

}

void remove_last(Node **head){
    if(*head == NULL) return;
    Node *walk=*head;
    if(walk->next==NULL){
        free(walk);
        walk=NULL;
    }
    while(walk->next->next){
        walk=walk->next;
    }
    free(walk->next);
    walk->next=NULL;    
}

void remove_x(Node **head, int target){
    if(*head == NULL) return;
    Node *walk=*head;
    if(walk->next==NULL){
        free(walk);
        walk=NULL;
    }
    while(walk->next && walk->next->data!=target){
        walk=walk->next;
    }

    if(walk->next==NULL && walk->data!=target){
        return;
    }

    Node *trashed = walk->next;
    walk->next=trashed->next;
    free(trashed);
    
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

void free_list(Node **head){
    Node *current;
    while((*head)){
        current = *head;
        *head = (*head)->next;
        free(current);
    }
    printf("\nMemory was freed!\n");
    
}

int main() {
    Node *head = NULL;
    int choice, value, target;

    while (1) {
        printf("\n\nLinked List Operations:\n");
        printf("1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Insert before value\n");
        printf("4. Insert after value\n");
        printf("5. Remove first\n");
        printf("6. Remove last\n");
        printf("7. Remove specific value\n");
        printf("8. Display list\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insert_first(&head, value);
                break;
            case 2:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insert_last(&head, value);
                break;
            case 3:
                printf("Enter target value: ");
                scanf("%d", &target);
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insert_before_x(&head, target, value);
                break;
            case 4:
                printf("Enter target value: ");
                scanf("%d", &target);
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insert_after_x(&head, target, value);
                break;
            case 5:
                remove_first(&head);
                printf("First node removed\n");
                break;
            case 6:
                remove_last(&head);
                printf("Last node removed\n");
                break;
            case 7:
                printf("Enter value to remove: ");
                scanf("%d", &value);
                remove_x(&head, value);
                break;
            case 8:
                printf("Current list: ");
                display(head);
                break;
            case 9:
                free_list(&head);
                return 0;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}