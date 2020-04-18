#include <stdio.h>
#include <stdlib.h>
#include "rubro-negra.h"

#define RED 1
#define BLACK 0

// Responsable to print All nodes of the tree.
void printAll(Node *node);

// Responsable to insert a new node.
Node *insertNode(Node* root, Node* node);

// Responsable to recoloring the nodes
void changeColor(Node *node);

// Responsable to get the color of the node
int getColor(Node *node);

int isChangeColor(Node *node);
int isRotationRight(Node *node);
int isRotationLeft(Node *node);
Node *rotationRight(Node *node);
Node *rotationLeft(Node *node);

typedef struct node {
    int value;
    int color; // 1-> RED, 0-> BLACK
    Node *right;
    Node *left;
} Node;

typedef struct tree {
    Node *root;
} Tree;

Tree *mainTree;

Node *create(int value) {
    Node* node = (Node *) malloc(sizeof(Node));
    node->value = value;
    node->color = RED;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void insert(Node *node) {
    if (mainTree == NULL) {
        mainTree = (Tree *) malloc(sizeof(Tree));
    }

    mainTree->root = insertNode(mainTree->root, node);
    mainTree->root->color = BLACK;
}

Node* insertNode(Node* root, Node* node) {
    if (root == NULL) {
        root = node;
    } else {
        if (node->value < root->value) {
            root->left = insertNode(root->left, node);
        } else if (node->value > root->value) {
            root->right = insertNode(root->right, node);
        }

        if (isRotationRight(root)) {
            root = rotationRight(root);
        }

        if (isRotationLeft(root)) {
            root = rotationLeft(root);
        }

        if (isChangeColor(root)) {
            changeColor(root);
        }
    }
    return root;
}

void changeColor(Node *node) {
    node->color = !node->color;
    if (node->left != NULL) {
        node->left->color = !node->left->color;
    }
    if (node->right != NULL) {
        node->right->color = !node->right->color;
    }
}

int getColor(Node *node) {
    if (node == NULL) {
        return BLACK;
    } else {
        return node->color;
    }
}

Node *rotationLeft(Node *node) {
    Node *nodeRight = node->right;
    node->right = nodeRight->left;
    nodeRight->left = node;
    nodeRight->color = node->color;
    node->color = RED;
    return nodeRight;
}

Node *rotationRight(Node *node) {
    Node *nodeLeft = node->left;
    node->left = nodeLeft->right;
    nodeLeft->right = node;
    nodeLeft->color = node->color;
    node->color = RED;
    return nodeLeft;
}

int isChangeColor(Node *node) {
    int isRightGrandsonRed = node->right != NULL && 
        (getColor(node->right->right) == RED || getColor(node->right->left) == RED);

    int isLeftGrandsonRed = node->left != NULL && 
        (getColor(node->left->right) == RED || getColor(node->left->left) == RED);

    return getColor(node->right) == RED && getColor(node->left) == RED && (isLeftGrandsonRed || isRightGrandsonRed);
}

int isRotationRight(Node *node) {
    int isRightGrandsonRed = node->left != NULL && getColor(node->left->left) == RED;
    int isRightSonRed = getColor(node->left) == RED;

    return getColor(node->right) == BLACK && isRightSonRed && isRightGrandsonRed;
}

int isRotationLeft(Node *node) {
    int isRightGrandsonRed = node->right != NULL && getColor(node->right->right) == RED;
    int isRightSonRed = getColor(node->right) == RED;

    return getColor(node->left) == BLACK && isRightSonRed && isRightGrandsonRed;
}

/*
* Print tree
*/
void printTree() {
    if (mainTree == NULL) {
        printf("Tree is empty\n");
    } else {
        printAll(mainTree->root);
    }
}

void printAll(Node *node) {
    if (node->right != NULL) {
        printAll(node->right);
    }

    if (node->right != NULL && node->left != NULL) {
        if (mainTree->root == node) {
            printf("** ROOT **   ");
        } else {
            printf("** NODE **   ");
        }
        printf("value: %d, color: %d | right: %d, left: %d\n", node->value, node->color, node->right->value, node->left->value);
    } else if (node->right != NULL && node->left == NULL) {
        if (mainTree->root == node) {
            printf("** ROOT **   ");
        } else {
            printf("** NODE **   ");
        }
        printf("value: %d, color: %d | right: %d, left: NULL\n", node->value, node->color, node->right->value);
    } else if (node->right == NULL && node->left != NULL) {
        if (mainTree->root == node) {
            printf("** ROOT **   ");
        } else {
            printf("** NODE **   ");
        }
        printf("value: %d, color: %d | right: NULL, left: %d\n", node->value, node->color, node->left->value);
    } else {
        if (mainTree->root == node) {
            printf("** ROOT **   ");
        } else {
            printf("** NODE **   ");
        }
        printf("value: %d, color: %d | right: NULL, left: NULL\n", node->value, node->color);
    }
    
    if (node->left != NULL) {
        printAll(node->left);
    }
}