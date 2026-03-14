/*
 * - First-in, first-out
 * - Enqueue (inserir), Dequeue (remover)
 * - Head (inicio), tail(fim)
 */

#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct list {
    struct node *head;
    struct node *tail;
};

void enqueue(struct list* l, struct node* new) {
    new->next = l->tail;
    struct node* temp = l->tail;
    l->tail = new;
    free(temp);
}

void dequeue(struct list* l) {
    struct node* temp = l->head;
    l->head = temp->next;
    free(temp);
}
