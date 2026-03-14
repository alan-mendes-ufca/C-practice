#include <stdlib.h>
/*
 * - Last-in, first-Out
 * - Push (inserir), Pop (remover)
 * - Tail as Head (indexa o elemento mais recente inserido)
 */

struct node {
    int data;
    struct node *next;
    struct node *prev;
};

struct stack {
    struct node *head;
};

void push(const struct stack *s, struct node *n) {
    s->head->next = n;
}
void pop(struct stack *s) {
    struct node *temp = s->head;
    s->head = s->head->prev;
    s->head->next = NULL;
    free(temp);
}