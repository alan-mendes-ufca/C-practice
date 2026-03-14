/*
 * Questão 07: Dada uma lista encadeada simples de números inteiros, implemente uma função que
 * inverta a ordem dos elementos da lista original sem criar novos nós. Você deve apenas alterar
 * os ponteiros prox para que o último elemento passe a ser o primeiro, o penúltimo passe a ser
 * o segundo, e assim por diante.
 */

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct linkedList {
    struct node *head;
    struct node *tail;
    int len;
};

struct node* initList() {
    struct node* head = malloc(sizeof(struct node));

    struct node *ptr = head;
    int i;
    for (i = 0; i < 10; i++, ptr = ptr->next) {
        ptr->data = i;
        ptr->next = malloc(sizeof(struct node));
    }
    ptr->data = i;
    ptr->next = NULL;
    return head;
}

void printLinkedList(struct node *ptr) {
    while (ptr != NULL) {
        printf("%i ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}


void freeLinkedlist(struct node* ptr) {
    while (ptr != NULL) {
        struct node *next = ptr->next;
        free(ptr);
        ptr = next;
    }
}

void invert(struct linkedList *l) {
    // último para primeiro e penúltimo para segundo
    // pegar o último e remontar lista de trás para frente

    struct node* pointersList[l->len - 1];
    struct node *ptr = l->head;
    struct node *last = NULL;

    // Get last pointer and init pointersList
    int idx = 0;
    while (ptr != NULL) {
        if (ptr->next == NULL) {
            last = ptr;
            break;
        }
        else {
            pointersList[idx] = ptr;
        }
        idx++;
        ptr = ptr->next;
    }

    // Remodel list
    struct node* temp = last;


    for (int i = idx - 1; i >= 0; i--, temp = temp->next) {
        ptr = pointersList[i];
        temp->next = ptr;
    }
    ptr ->next = NULL;
    l->head = last;
}

int main(void) {
    struct linkedList list;
    struct node* head = initList();
    list.head = head;
    list.tail = NULL;
    list.len = 11;
    printLinkedList(list.head);

    invert(&list);
    printLinkedList(list.head);
    freeLinkedlist(list.head);
}