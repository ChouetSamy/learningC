#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node* left;
    struct Node* right;
} Node;

// Création d'un node
Node* createNode(int val) {
    Node* n = malloc(sizeof(Node));
    n->value = val;
    n->left = n->right = NULL;
    return n;
}

// Insertion dans un BST
Node* insert(Node* root, int val) {
    if (!root) return createNode(val);
    if (val < root->value) root->left = insert(root->left, val);
    else root->right = insert(root->right, val);
    return root;
}

// Parcours infixe (gauche → parent → droite)
void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    printf("%d ", root->value);
    inorder(root->right);
}

int main() {
    Node* root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 40);
    inorder(root); // 30 40 50 70
}