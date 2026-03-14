/*
* - height = O(log n) em árvores balanceadas (ex: AVL tree)
 *
 * - propriedade:
 *   node.height = height of the subtree rooted at node
 *   node.height = max(node.left.height, node.right.height) + 1
 *   - por essa definição, uma posição de folha tem altura 1, enquanto a altura de null é 0;
 *   - essa operação é O(1), pois usa apenas as alturas dos filhos. Durante insert e delete atualizamos os nós no caminho até a raiz.
 *
 * - Rotação: ferramenta usada para rebalancear a árvore
 *   - mantém a ordem do inOrderTreeWalk preservada
 *     (a, x, b, y, c) → (a, x, b, y, c)
 *
 * - HeightBalanced:
 *   balance_factor(node) = node.right.height - node.left.height
 *   ∈ {-1, 0, 1}
 */

#include <stddef.h>
#include <stdio.h>

struct node {
    struct node *left, *right;
    struct node *parent;
    int data;

    int height; // height of the subtree rooted at node
    int balance;
    int size; // amount of nodes in subtrees; node.size = node.left.size + node.right.size + 1;
};

struct avl {
    struct node *root;
};

int height(struct node *n) {
    if (n == NULL) return 0;
    else return n->height;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

void updateHeight(struct node*n) {
    int leftHeight = height(n->left);
    int rightHeight = height(n->right);
    n -> height = max(leftHeight, rightHeight) + 1;
}

int balanceFactor(struct node *n) {
    if (n == NULL) return 0;
    else return height(n->left) - height(n->right);
}

void rotateLeft(struct node *root) {
    struct node *rightChild = root->right;
    struct node *subtreeBetween = rightChild->left;

    rightChild->left = root;
    root->right = subtreeBetween; // disconnect right child

    if (subtreeBetween != NULL) {
        subtreeBetween->parent = root;
    }

    rightChild->parent = root->parent;
    root->parent = rightChild;

    updateHeight(root);
    updateHeight(rightChild);
}

void rotateRight(struct node *root) {
    struct node *leftChild = root->left;
    struct node *subtreeBetween = leftChild->right;

    leftChild->right = root;
    root->left = subtreeBetween;
    if (subtreeBetween != NULL) {
        subtreeBetween->parent = root;
    }

    leftChild->parent = root->parent;

    if (root->parent != NULL) {
        if (leftChild->data < root->parent->data) root->parent->left = leftChild;
        else root->parent->right = leftChild;
    }

    root->parent = leftChild;

    updateHeight(root);
    updateHeight(leftChild);
}

void rebalance(struct node *root) {

    int balance = balanceFactor(root);

    // Left heavy
    if (balance > 1) {

        // LL
        if (balanceFactor(root->left) >= 0) {
            rotateRight(root);
        }

        // LR
        else {
            rotateLeft(root->left);
            rotateRight(root);
        }
    }

    // Right heavy
    else if (balance < -1) {

        // RR
        if (balanceFactor(root->right) <= 0) {
            rotateLeft(root);
        }

        // RL
        else {
            rotateRight(root->right);
            rotateLeft(root);
        }
    }
}


void insert(struct avl *t, struct node *new) {
    struct node *target = t->root;
    struct node *previous = NULL;

    // Find a valid position
    while (target != NULL) {
        previous = target;
        if (new->data < target->data) target = target->left;
        else target = target->right;
    }

    // Set node
    new->parent = previous;
    if (previous == NULL) t->root = new;
    else if (new->data < previous->data) previous->left = new;
    else previous->right = new;

    // Pós processamento AVL
    struct node *current = new->parent;

    // Subir pela árvore
    while (current != NULL) {

        // UpdateHeight
        updateHeight(current);

        // balanceFactor
        int balance = balanceFactor(current);

        if (balance > 1 || balance < -1) {
            rebalance(current);
        }

        current = current->parent;
    }
}


void transplant(struct avl *t, struct node *old, struct node *new) {
    struct node *parent = old->parent;
    if (parent == NULL) t->root = new;
    else if (old->data < parent->data) parent->left = new;
    else parent->right = new;
    if (new != NULL) new->parent = parent;
}

struct node *minimumSearch(struct node *root) {
    if (root == NULL) return NULL;
    struct node *target = minimumSearch(root->left);
    if (target == NULL) return root;
    else return target;
}

void delete(struct avl *t, struct node *removedNode){
    if (removedNode->left == NULL) {
        transplant(t, removedNode, removedNode->right);
    }
    else if (removedNode->right == NULL) {
        transplant(t, removedNode, removedNode->left);
    }
    else {
        struct node *sucessor = minimumSearch(removedNode->right);
        if (sucessor != removedNode->right) {
            transplant(t, sucessor, sucessor->right);
            sucessor->right = removedNode->right;
            removedNode->right->parent = sucessor;
        }
        transplant(t, removedNode, sucessor);
        sucessor->left = removedNode->left;
        removedNode->left->parent = sucessor;
    }
}