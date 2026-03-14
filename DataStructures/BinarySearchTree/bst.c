
/*
 * - Operações: search, minimum, maximum, predecessor, successor, insert e delete
 * - É possível utilizá-la como um 'dicionário' ou uma 'fila de prioridade'
 * - BST é eficiente quando está balanceada O(log height), mas degenera para O(height) no pior caso.
 * - Propriedade básica:
 *       - keys in subtree(node.left) < root.key < keys in subtree(node.right)
 * - Print, search = condição de parada + condição de recursão
*/

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* leftSubtree;
    struct node* rightSubtree;
    struct node* parentTree;
};

struct tree {
    struct node* root;
};

// O(n), sendo n = número de nós
void inOrderTreeWalk(const struct node *root) {
    if (root != NULL) {
        inOrderTreeWalk(root->leftSubtree);
        printf("%d", root->data);
        inOrderTreeWalk(root->rightSubtree);
    }
}

// O(h), onde h é a altura da árvore. Entretanto, com a recursão se gasta mais memória.
struct node* recursiveTreeSearch(struct node *root, const int data) {
    if (root == NULL || root->data == data) return root;
    if (data < root->data) return recursiveTreeSearch(root->leftSubtree, data);
    else return recursiveTreeSearch(root->rightSubtree, data);
}

// O(h), onde h é a altura da árvore. Mais eficiênte.
struct node* iterativeTreeSearch(struct node *root, const int data) {
    while (root != NULL && root->data != data) {
        if (root->data < data) root = root->leftSubtree;
        else root = root->rightSubtree;
    }
    return root;
}

struct node* iterativeTreeMinimumSearch(struct node *root) {
    while (root->leftSubtree != NULL) {
        root = root->leftSubtree;
    }
    return root;
}

struct node* recursiveTreeMinimumSearch(struct node *root) {
    if (root == NULL) return NULL;
    struct node *target =  recursiveTreeMinimumSearch(root->leftSubtree);
    if (target == NULL) return root;
    return target;
}

struct node* iterativeTreeMaximumSearch(struct node *root) {
    while (root->rightSubtree != NULL) {
        root = root->rightSubtree;
    }
    return root;
}

struct node* recursiveTreeMaximumSearch(struct node *root) {
    if (root == NULL) return NULL;
    struct node *target = recursiveTreeMaximumSearch(root->leftSubtree);
    if (target == NULL) return root;
    return target;
}

// O(h)
struct node* sucessorTree(const struct node* specifiedNode) {
    if (specifiedNode->rightSubtree != NULL) {
        // the sucessor of x is just the leftmost node in x's right subtree
        return iterativeTreeMinimumSearch(specifiedNode->rightSubtree);
    }

    // the sucessor is the lowest ancestor of x whose the left child is also an ancestor of x.
    struct node *parent = specifiedNode->parentTree;
    while (parent != NULL && specifiedNode == parent->rightSubtree) {
        specifiedNode = parent;
        parent = parent->parentTree;
    }
    return parent;
}

// O(h)
struct node* predecessorTree(const struct node* specifiedNode) {
    if (specifiedNode->leftSubtree != NULL) {
        // the predecessor of x is just the rightmost node in x's left subtree
        return iterativeTreeMaximumSearch(specifiedNode->leftSubtree);
    }

    // the predecessor is the greater ancestor of x whose the right child is also an ancestor of x.
    struct node *parent = specifiedNode->parentTree;
    while (parent != NULL || specifiedNode == parent->leftSubtree) {
        specifiedNode = parent;
        parent = parent->parentTree;
    }
    return parent;
}

void insert(struct tree *t, struct node *new) {
    struct node *target = t->root;
    struct node *previous = NULL;

    // Search step
    while (target != NULL) {
        previous = target;
        if (new->data < target->data) target = target->leftSubtree;
        else target = target->rightSubtree;
    }

    // Set node step
    new->parentTree = previous;
    if (previous == NULL) t->root = new; // tree was empty
    else if (new->data < previous->data) previous->leftSubtree = new;
    else previous->rightSubtree = new;
}

void transplant(struct tree *t, const struct node *u, struct node *v) {
    struct node *parent = u->parentTree;
    if (parent == NULL) t->root = v;
    else if (u->data == parent->leftSubtree->data) parent->leftSubtree = v;
    else parent->rightSubtree = v;

    if (v != NULL) v->parentTree = parent;
}

void deleteTree(struct tree *t, const struct node *removedNode) {
    if (removedNode->leftSubtree == NULL) {
        // folha → transplant(node, NULL)
        transplant(t, removedNode, removedNode->rightSubtree);
    }
    else if (removedNode->rightSubtree == NULL) {
        // 1 filho → transplant(node, child)
        transplant(t, removedNode, removedNode->leftSubtree);
    }
    else {
        //2 filhos → substituir pelo sucessor
        struct node *sucessorInOrder = iterativeTreeMinimumSearch(removedNode->rightSubtree);
        if (sucessorInOrder != removedNode->rightSubtree) {
            transplant(t, sucessorInOrder, sucessorInOrder->rightSubtree);
            sucessorInOrder->rightSubtree = removedNode->rightSubtree;
            removedNode->rightSubtree->parentTree = sucessorInOrder;
        }
        transplant(t, removedNode, sucessorInOrder);
        sucessorInOrder->leftSubtree = removedNode->leftSubtree;
        sucessorInOrder->leftSubtree->parentTree = sucessorInOrder;
    }
}
