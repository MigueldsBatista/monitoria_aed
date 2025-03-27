#include <stdio.h>
#include <stdlib.h>

/*

QUESTÃO 01 - Revise a implementação das funções a seguir para as pilhas:
a) Inserção
b) Remoção
c) Impressão

*/

typedef struct Node {  
int valor; 
struct Node *prox; 
}Node ;

void inserir(Node **head, int x){
  Node *novo = (Node*)malloc(sizeof(Node));
  if(novo){
    novo->valor = x;
    novo->prox = *head;
    *head = novo;
  }
}

void printa(Node *head){
  if(head){
    Node *temp = head;
    while(temp != NULL){
      printf("%d ", temp->valor);
      temp = temp->prox;
    }
  }
}

void removePilha(Node **head){
  if(*head){
    Node *aux = *head;
    *head = (*head)->prox;
    free(aux);
  }
}

void troca(Node **head1, Node **head2){
  if(head1 && head2){
    Node *topo1 = *head1;
    Node *topo2 = *head2;

    *head1 = topo1->prox;
    *head2 = topo2->prox;

    topo1->prox = *head2;
    topo2->prox = *head1;

    *head1 = topo2;
    *head2 = topo1;

  }
}

int main (void){
  Node  *head = NULL;
  Node  *head2 = NULL;
  inserir(&head, 1);
  inserir(&head, 2);
  inserir(&head, 3);
  printa(head);

  printf("\n");
  
  inserir(&head2, 4);
  inserir(&head2, 5);
  inserir(&head2, 6);
  printa(head2);
  printf("\n"); // 1 2 3

  troca(&head,&head2);
  printa(head); // 1 2 3 4 5 6
  printf("\n");
  printa(head2); // 4 5 6 1 2 3
  
  return 0;
}