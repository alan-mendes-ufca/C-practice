#include <stdlib.h>
#include <stdio.h>

struct node {
    int value;
    struct node *next;
    struct node *prev;
};

struct linkedList {
    struct node *head;
    struct node *tail;
};

struct node* search(const struct linkedList list, const int value) {
    struct node *ptr = list.head;
    while (ptr != NULL) {
        if (ptr->value == value) {
            return ptr;
        }
        ptr = ptr->next;
    }
    return NULL;
}

void insert(struct linkedList list, struct node* new) {
    // IDEIA PRINCIPAL: emendar no início.
    new->next = list.head;

    if (list.head != NULL) {
        list.head->prev = new;
    }

    list.head = new;
    new->prev = NULL;
}

void delete(struct linkedList list, struct node* ptr) {
    // `condições de contorno`: head (prev == NULL), tail (next == NULL)
    if (ptr->prev != NULL) ptr->prev->next = ptr->next;
    else list.head = ptr->next;

    if (ptr->next != NULL) ptr->next->prev = ptr->prev;
    free(ptr);
}


