/*
 * Questão 06:
 * Dada uma lista encadeada simples de números inteiros, implemente uma função
 * que receba uma lista L e a divida em duas novas listas, L_Pares e L_Impares.
 * A lista original L deve ser esvaziada (liberada) ao final do processo.
 */

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct linkedList {
    struct node* head;
    struct node* tail;
    struct node* len;
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

void insert(struct node** ptr, const int value) {

    if (*ptr == NULL) {
        *ptr = malloc(sizeof(struct node));
        (*ptr)->data = value;
        (*ptr)->next = NULL;
        return;
    }

    while (*ptr != NULL) {
        if ((*ptr)->next == NULL) {
            (*ptr)->next = malloc(sizeof(struct node));
            (*ptr)->next->data = value;
            (*ptr)->next->next = NULL;
            break;
        }
        ptr = &(*ptr)->next;
    }
}

void separe(struct linkedList *l, struct linkedList *lOdd, struct linkedList *lEven) {
    struct node *ptr = l->head;
    while (ptr != NULL) {
        if (ptr->data % 2 == 0) {
            insert(&lEven->head, ptr->data);
        }
        else {
            insert(&lOdd->head, ptr->data);
        }
        ptr = ptr->next;
    }
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

int main(void) {
    struct linkedList l;
    l.head = initList();
    l.tail = NULL;

    printLinkedList(l.head);

    // Separar impar x par
    struct linkedList lOdd;
    lOdd.head = NULL;
    lOdd.tail = NULL;
    lOdd.len = 0;

    struct linkedList lEven;
    lEven.head = NULL;
    lEven.tail = NULL;
    lEven.len = 0;

    separe(&l, &lOdd, &lEven);

    printLinkedList(lOdd.head);
    printLinkedList(lEven.head);

    freeLinkedlist(l.head);
    freeLinkedlist(lOdd.head);
    freeLinkedlist(lEven.head);

    return 0;
}