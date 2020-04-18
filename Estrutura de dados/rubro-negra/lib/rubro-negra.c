#include <stdio.h>
#include <stdlib.h>
#include "rubro-negra.h"

// Responsable to print All nodes of the tree.
void printAll(Node* node);

// Responsable to get the father of a node.
Node* getFatherNode(Node* father, Node* node);

typedef struct node {
    int value;
    char color; // r-> red, b-> black
    Node* right;
    Node* left;
    Node* father;
} Node;

typedef struct tree {
    Node* root;
} Tree;

Tree* mainTree;

Node* create(int value) {
    Node* node = (Node *) malloc(sizeof(Node));
    node->value = value;
    node->color = 'r';
    return node;
}

void insert(Node* node) {
    if (mainTree == NULL) {
        mainTree = (Tree *) malloc(sizeof(Tree));
        node->color = 'b';
        mainTree->root = node;
        return;
    }

    Node* father = getFatherNode(mainTree->root, node);

    node->father = father;
    if (node->value < father->value) {
        father->left = node;
    } else if (node->value > father->value) {
        father->right = node;
    }
}

Node* getFatherNode(Node* father, Node* node) {
    if (node->value < father->value) {
        if (father->left != NULL) {
            return getFatherNode(father->left, node);
        }
    } else if (node->value > father->value) {
        if (father->right != NULL) {
            return getFatherNode(father->right, node);
        }
    }
    return father;
}

void printTree() {
    if (mainTree == NULL) {
        printf("Tree is empty\n");
    } else {
        printAll(mainTree->root);
    }
}

void printAll(Node* node) {
    if (node->right != NULL) {
        printAll(node->right);
    }

    if (node->father != NULL) {
        if (node->father->left->value == node->value) {
            printf("Left son of father: %d - value: %d, color: %c\n", node->father->value, node->value, node->color);
        } else {
            printf("Right son of father: %d - value: %d, color: %c\n", node->father->value, node->value, node->color);
        }

    } else {
        printf("Root - value: %d, color: %c\n", node->value, node->color);
    }

    if (node->left != NULL) {
        printAll(node->left);
    }
}