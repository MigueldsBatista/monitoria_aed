#include <stdio.h>
#include <stdlib.h>

/*
QUESTÃO 04 - Considere que um programa em C manipula duas Pilhas (Pilha01 e Pilha02)
e agora é necessário que seja implementada uma nova função que realiza a troca do primeiro
elemento entre as pilhas (o primeiro nó que está na Pilha01 vai para a Pilha02 E o primeiro nó
que estava na Pilha02 vai para a Pilha01).
Protótipo da função: void troca(Node *head1, Node *head2);

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
  printf("\n");

  troca(&head,&head2);
  printf("Resultado: ");
  printa(head);
  printf("\n");
  printa(head2);
  
  return 0;
}