#include <stdio.h>
#include <stdlib.h>
#include "rubro-negra.h"

// Responsable to print All nodes of the tree.
void printAll(Node* node);

// Responsable to get the father of a node.
Node* getFatherNode(Node* father, Node* node);

// Responsable to recoloring the nodes
void recoloring(Node *node);

// Responsable to get the brother of one node.
Node *getBrotherNode(Node *node);

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
    node->father = NULL;
    node->left = NULL;
    node->right = NULL;
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
    Node* uncle = getBrotherNode(father);

    node->father = father;
    if (node->value < father->value) {
        father->left = node;
    } else if (node->value > father->value) {
        father->right = node;
    }

    if (uncle->color == 'r' && father->color == 'r') {
        recoloring(uncle->father);
    }
}

Node *getBrotherNode(Node *node) {
    Node* father = node->father;
    Node* brother;
    if (father != NULL) {
        if (father->right != NULL) {
            if (father->right->value != node->value) {
                brother = father->right;
            }
        }
        if (father->left != NULL) {
            if (father->left->value != node->value) {
                brother = father->left;
            }
        }
    }
    return brother;
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

void recoloring(Node *node) {
    if (node->left != NULL) {
        node->left->color = node->left->color == 'r' ? 'b' : 'r';
    }

    if (node->right != NULL) {
        node->right->color = node->right->color == 'r' ? 'b' : 'r';
    }

    if (node->father != NULL) {
        node->color = node->color == 'r' ? 'b' : 'r';
        if (node->father->color == 'r') {
            recoloring(node->father);
        }
    } else {
        node->color = 'b';
    }
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