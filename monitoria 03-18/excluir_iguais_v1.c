#include <stdio.h>
#include <stdlib.h>

/*
QUESTÃO 03 - Considere que um programa em C manipula duas Filas (Fila01 e Fila02) e agora
é necessário que seja implementada uma nova função que verifique se existem valores repetidos
entre as filas, caso tenha valor repetido, deve ser removido apenas da Fila2;.
Protótipo da função: void excluirIguais(Node **head1,Node **tail1, Node **head2, Node
**tail2);
*/

typedef struct Node {
    int data;
    struct Node *next;
} Node;

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
