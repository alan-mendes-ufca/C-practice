/*
 * Questão 05:
 * Dada uma lista encadeada simples de números inteiros, implemente uma função
 * Lista* insere_posicao (Lista* li, int dado, int pos) que receba a posição
 * onde o novo nó deve ser colocado (considere a primeira posição como 0).
 * Se a posição for maior que o tamanho da lista, insira o elemento no final.
 * Se a posição for 0 ou a lista estiver vazia, insira no início.
 */

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct linkedList {
    struct node *head;
    struct node *tail;
    int length;
};

void insertInPosition(struct linkedList* l, struct node* new, const int pos) {
    if (l->head == NULL) {
        l->head = new;
        l->tail = new;
        return;
    }

    if (pos == 0) {
        new->next = l->head;
        l->head = new;
        return;
    }

    if (pos > l->length) {
        l->tail->next = new;
        l->tail = new;
        l->length++;
        return;
    }

    struct node *ptr = l->head;
    int count = 0;

    while (ptr != NULL) {
        if (count == pos - 1) {
            // condição de contorno

            struct node *prev = ptr;
            struct node *target = ptr->next;

            prev->next = new;
            new->next = target;
        }
        ptr = ptr->next;
        count++;
    }
}

int main(void) {
    struct linkedList l;
    l.head = NULL;
    l.tail = NULL;
    l.length = 0;

    struct node* new = (struct node*) malloc(sizeof(struct node));
    new->next = NULL;
    new->data = 1;

    insertInPosition(&l, new, 1);

    assert(l.head != NULL);
    assert(l.tail != NULL);
    assert(l.length == 0);
    assert(l.head == new);
    assert(l.tail == new);
    assert(l.head->data == 1);
    assert(l.tail->data == 1);

    free(new);
    return 0;
}