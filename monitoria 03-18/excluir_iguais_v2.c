#include <stdio.h>
#include <stdlib.h>

/*
QUESTÃO 03 - Considere que um programa em C manipula duas Filas (Fila01 e Fila02) e agora
é necessário que seja implementada uma nova função que verifique se existem valores repetidos
entre as filas, caso tenha valor repetido, deve ser removido apenas da Fila2;.
Protótipo da função: void excluirIguais(Node **head1,Node **tail1, Node **head2, Node
**tail2);
*/

// Estrutura do nó da fila
typedef struct Node {
    int data;
    struct Node *next;
} Node;


// Function to remove duplicate values from Fila02 that exist in Fila01
void excluirIguais(Node **head1, Node **tail1, Node **head2, Node **tail2) {
    if (*head2 == NULL) return; // If Fila02 is empty, nothing to remove

    Node *prev = NULL, *curr = *head2;

    while (curr != NULL) {
        Node *search = *head1;
        int found = 0;

        // Check if the value in Fila02 exists in Fila01
        while (search != NULL) {
            if (search->data == curr->data) {
                found = 1;
                break;
            }
            search = search->next;
        }

        if (found) { // If value is found in Fila01, remove it from Fila02
            if (prev == NULL) { // Removing the first element in Fila02
                *head2 = curr->next;
                free(curr);
                curr = *head2;
                if (*head2 == NULL) { // If Fila02 becomes empty, update tail2
                    *tail2 = NULL;
                }
            } else { // Removing a middle or last element
                prev->next = curr->next;
                free(curr);
                curr = prev->next;
                if (curr == NULL) { // If we removed the last element, update tail2
                    *tail2 = prev;
                }
            }
        } else {
            prev = curr;
            curr = curr->next;
        }
    }
}


