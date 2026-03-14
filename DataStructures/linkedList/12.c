/*
 * Questão 12:
 * Implemente uma função int eh_palindromo (Lista2* li) que verifique se a lista duplamente
 * encadeada forma um palíndromo. A função deve retornar 1 se for palíndromo e 0 se não for.
 */

#include <assert.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

struct node {
    char data;
    struct node *next;
    struct node *prev;
};

struct linkedList {
    struct node *head;
    struct node *tail;
    int len;
};

int isPalindromo(const struct linkedList *l) {
    const struct node *head = l->head;
    const struct node *tail = l->tail;
    int count = 0;

    while (head != tail && count != (l->len / 2)) {
        if (tolower(head->data) != tolower(tail->data)) {
            return 0;
        }
        head = head->next;
        tail = tail->prev;
        count++;
    }
    return 1;
}

void initList(struct linkedList **l, const char* word) {
    if (*l == NULL) {
        *l = malloc(sizeof(struct linkedList));
        (*l)->head = NULL;
        (*l)->tail = NULL;
    }

    struct node *head = malloc(sizeof(struct node));
    if (head == NULL) {
        return;
    }

    const int size = strlen(word);
    (*l)->len = size;

    head ->prev = NULL;
    head->data = word[0];

    struct node *ptr = head;
    for (int idx = 1; idx <= size - 1; idx++, ptr=ptr->next) {
        struct node *temp = malloc(sizeof(struct node));
        if (temp == NULL) {
            return;
        }

        temp->data = word[idx];
        ptr->next = temp;
        temp->prev = ptr;
    }

    ptr->next = NULL;
    (*l)->tail = ptr;
    (*l)->head = head;
}

int main(void) {
    struct linkedList *l = NULL;
    initList(&l, "ana");

    assert(isPalindromo(l) == 1);

    initList(&l, "alan");
    assert(isPalindromo(l) == 0);

    initList(&l, "osso");
    assert(isPalindromo(l) == 1);

    initList(&l, "Atorredaderrota");
    assert(isPalindromo(l) == 1);
}