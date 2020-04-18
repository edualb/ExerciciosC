#include <stdio.h>
#include <stdlib.h>

typedef struct node Node;

/*
Node structure {
    value, 
    color (r -> red, b-> black),
    father,
    right son,
    left son,
}
*/
typedef struct node {
    int value;
    char color;
    Node* right;
    Node* left;
    Node* father;
} Node;

/*
Responsable to create a new node, with a value and red color.
*/
Node* create(int value) {
    Node* node = (Node *) malloc(sizeof(Node));
    node->value = value;
    node->color = 'r';
    return node;
}

Node* insert(Node* node) {
    printf("%d\n", node->value);
}