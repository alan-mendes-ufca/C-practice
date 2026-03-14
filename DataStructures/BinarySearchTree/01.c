/*
 * Questão 4: Apresenta apenas a assinatura da função calcular_somatorio(Arvore);
 * para ser implementada (cujo objetivo, demonstrado no teste de mesa, é calcular
 * a soma de todos os valores dos nós da árvore).
 */

#include <stdio.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
    struct node *parent;
};

struct tree {
    struct node* root;
};


void inOrderTreeWalk(const struct node *root, int* sum) {
    if (root != NULL) {
        inOrderTreeWalk(root->left, sum);
        *sum += root->data;
        inOrderTreeWalk(root->right, sum);
    }
}

int calculateSum(const struct tree *t) {
    if (t == NULL) return 0;

    int sum = 0;
    inOrderTreeWalk(t->root, &sum);
    return sum;
}