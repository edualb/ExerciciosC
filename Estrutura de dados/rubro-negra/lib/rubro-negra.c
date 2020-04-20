#include <stdio.h>
#include <stdlib.h>
#include "rubro-negra.h"
#include "rubro-negra_p.h"

#define RED 1
#define BLACK 0

typedef struct node {
    int value;
    int color;
    Node *right;
    Node *left;
    Node *father;
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

void get(int value) {
    if (mainTree->root == NULL) {
        printf("Arvore vazia\n");
    } else {
        Node *node = search(mainTree->root, value);
        printf("Found: Value: %d, Color: %d\n", node->value, node->color);
    }
}

void push(int value) {
    Node* node = create(value);
    if (mainTree == NULL) {
        mainTree = (Tree *) malloc(sizeof(Tree));
    }
    mainTree->root = insert(mainTree->root, NULL, node);
    mainTree->root->father = NULL;
    mainTree->root->color = BLACK;
}

void delete(int value) {
    if (mainTree->root == NULL) {
        printf("Arvore vazia\n");
    } else {
        mainTree->root = removeNode(mainTree->root, value);
        mainTree->root->father = NULL;
        mainTree->root->color = BLACK;
    }
}

// file:///home/eduardo/Downloads/inf01203-rubronegras%20(2).pdf
Node *removeNode(Node *root, int value) {
    if (root->value == value) {
        Node *father = root->father;

        if (root->left == NULL && root->right == NULL) {
            father->left = father->left == root ? NULL : father->left;
            father->right = father->right == root ? NULL : father->right;

            if (father == NULL || root->color == RED) {
                free(root);
                return father;
            } else {
                Node *brother = father->left != root ? father->left : father->right;
                int isNephewRed = getColor(brother->right) == RED || getColor(brother->left) == RED;
                int isNephewBlack = getColor(brother->right) == BLACK && getColor(brother->left) == BLACK;

                // Case 1 OR Case 3
                if ((getColor(brother) == BLACK && isNephewRed) || (getColor(brother) == RED)) {
                    free(root);
                    return brother == father->left ? rotationRight(father) : rotationLeft(father);
                }
                
                // Case 2
                if (getColor(brother) == BLACK && isNephewBlack) {
                    free(root);
                    father->color = BLACK;
                    brother->color = RED;
                    return father;
                }
            }
        } else if ((root->left == NULL && root->right != NULL) || (root->left != NULL && root->right == NULL)) {
            Node *son = root->left != NULL ? root->left : root->right;
            if (getColor(root) == RED) {
                
            } else {

            }
        } else {

        }
    } else if (value < root->value) {
        root = removeNode(root->left, value);
        root = balance(root);
    } else {
        root = removeNode(root->right, value);
        root = balance(root);
    }

    if (root->father != NULL) {
        return root->father;
    }
    return root;
}

Node *search(Node* node, int value) {
    if (node == NULL || node->value == value) {
        return node;
    }
    if (value < node->value) {
        return search(node->left, value);
    }
    return search(node->right, value);
}

Node* insert(Node *root, Node *father, Node *node) {
    if (root == NULL) {
        root = node;
        root->father = father;
    } else {
        if (node->value < root->value) {
            root->left = insert(root->left, root, node);
        } else if (node->value > root->value) {
            root->right = insert(root->right, root, node);
        }
        root = balance(root);
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
    if (nodeRight->left != NULL) {
        nodeRight->left->father = node;
    }
    nodeRight->left = node;
    nodeRight->father = node->father;
    node->father = nodeRight;
    nodeRight->color = node->color;
    node->color = RED;
    return nodeRight;
}

Node *rotationRight(Node *node) {
    Node *nodeLeft = node->left;
    node->left = nodeLeft->right;
    if (nodeLeft->right != NULL) {
        nodeLeft->right->father = node;
    }
    nodeLeft->right = node;
    nodeLeft->father = node->father;
    node->father = nodeLeft;
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

int isRotationDoubleLeft(Node *node) {
    int isLeftGrandsonRed = node->right != NULL && getColor(node->right->left) == RED;
    int isRightSonRed = getColor(node->right) == RED;

    return getColor(node->left) == BLACK && isRightSonRed && isLeftGrandsonRed;
}

int isRotationDoubleRight(Node *node) {
    int isRightGrandsonRed = node->left != NULL && getColor(node->left->right) == RED;
    int isLeftSonRed = getColor(node->left) == RED;

    return getColor(node->right) == BLACK && isLeftSonRed && isRightGrandsonRed;
}

Node *balance(Node *root) {
    if (isRotationRight(root)) {
        root = rotationRight(root);
    }
    if (isRotationLeft(root)) {
        root = rotationLeft(root);
    }
    if (isRotationDoubleLeft(root)) {
        root->right = rotationRight(root->right);
        root = rotationLeft(root);
    }
    if (isRotationDoubleRight(root)) {
        root->left = rotationLeft(root->left);
        root = rotationRight(root);
    }
    if (isChangeColor(root)) {
        changeColor(root);
    }
    return root;
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