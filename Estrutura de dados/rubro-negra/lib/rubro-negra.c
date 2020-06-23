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

// OK
Node *create(int value) { // O(1)
    Node* node = (Node *) malloc(sizeof(Node)); // c | 1
    node->value = value; // c | 1
    node->color = RED; // c | 1
    node->left = NULL; // c | 1
    node->right = NULL; // c | 1
    return node; // c | 1
}
// ok
void get(int value) {
    if (mainTree->root == NULL) { // c | 1
        printf("Arvore vazia\n"); // c | 1
    } else {
        Node *node = search(mainTree->root, value); // O(log n)
        printf("Found: Value: %d, Color: %d\n", node->value, node->color); // c | 1
    }
}

// ok
void push(int value) {
    Node* node = create(value); // c | 1
    if (mainTree == NULL) { // c | 1
        mainTree = (Tree *) malloc(sizeof(Tree)); // c | 1
    }
    mainTree->root = insert(mainTree->root, NULL, node); // c | ?
    mainTree->root->father = NULL; // c | 1
    mainTree->root->color = BLACK; // c | 1
}

void delete(int value) {
    if (mainTree->root == NULL) { // c | 1
        printf("Arvore vazia\n"); // c | 1
    } else {
        mainTree->root = removeNode(mainTree->root, value); // c | ?
        if (mainTree->root != NULL) { // c | 1
            mainTree->root->father = NULL; // c | 1
            mainTree->root->color = BLACK; // c | 1
        }
    }
}

// file:///home/eduardo/Downloads/inf01203-rubronegras%20(2).pdf
// ok
Node *removeNode(Node *root, int value) { // O((log n)^2)
    if (root->value == value) { // c | 1
        Node *father = root->father; // c | 1
        if (root->left == NULL && root->right == NULL) { // c | 1
            if (father == NULL) { // c | 1
                free(root); // c | 1
                return NULL; // c | 1
            } else {
                Node *brother = father->left != root ? father->left : father->right; // c | 1
                father->left = father->left == root ? NULL : father->left; // c | 1
                father->right = father->right == root ? NULL : father->right; // c | 1
                // c | 1 + 1 + 1
                int isNephewRed = getColor(brother->right) == RED || getColor(brother->left) == RED;
                // c | 1 + 1 + 1
                int isNephewBlack = getColor(brother->right) == BLACK && getColor(brother->left) == BLACK;
                
                if (getColor(root) == RED) { // c | 1
                    free(root); // c | 1
                    return father; // c | 1
                }
                
                // Case 1 OR Case 3
                if ((getColor(brother) == BLACK && isNephewRed) || (getColor(brother) == RED)) { // c | 1 + 1
                    free(root); // c | 1
                    // c | 1 + 1 ||  c | 1 + 1
                    return brother == father->left ? rotationRight(father) : rotationLeft(father);
                }
                
                // Case 2
                if (getColor(brother) == BLACK && isNephewBlack) { // c | 1
                    free(root); // c | 1
                    father->color = BLACK; // c | 1
                    brother->color = RED; // c | 1
                    return father; // c | 1
                }
            }
        } else if ((root->left == NULL && root->right != NULL) || (root->left != NULL && root->right == NULL)) { // c | 1
            Node *son = root->left != NULL ? root->left : root->right; // c | 1
            if (father != NULL) { // c | 1
                if (father->left == root) { // c | 1
                    father->left = son; // c | 1
                } else {
                    father->right = son; // c | 1
                }
            }
            free(root); // c | 1
            son->father = father; // c | 1
            son->color = BLACK; // c | 1 
            return father != NULL ? father : son; // c | 1
        } else {
            Node *farther = getFarther(root->right); // c | log (n/2)
            root->value = farther->value; // c | 1
            farther->value = value; // c | 1
            root = removeNode(root->right, value); // c | T(n/2)
            root = balance(root); // c | 1
            return root->father != NULL ? root->father : root; // c | 1 + 1
        }
    } else if (value < root->value) { // c | 1
        root = removeNode(root->left, value); // c | T(n/2)
        root = balance(root); // c | 1
    } else {
        root = removeNode(root->right, value); // c | T(n/2)
        root = balance(root); // c | 1
    }

    return root->father != NULL ? root->father : root; // c | 1 + 1
}

// OK
Node *search(Node* node, int value) { // O(log n)
    if (node == NULL || node->value == value) { // c | 1
        return node; // c | 1
    }
    if (value < node->value) { // c | 1
        return search(node->left, value); // c | T(n/2)
    }
    return search(node->right, value); // c | T(n/2)
}

Node *getFarther(Node *node) { // O(log n)
    if (node->left == NULL) { // c | 1
        return node; // c | 1
    }
    return getFarther(node->left); // c | T(n/2)
}

// OK
Node* insert(Node *root, Node *father, Node *node) { // O(log n)
    if (root == NULL) { // c | 1
        root = node; // c | 1
        root->father = father; // c | 1
    } else {
        if (node->value < root->value) { // c | 1
            root->left = insert(root->left, root, node); // c | T(n/2)
        } else if (node->value > root->value) { // c | 1
            root->right = insert(root->right, root, node); // c | T(n/2)
        }
        root = balance(root); // c | O(1)
    }
    return root; // c | 1
}

// OK
void changeColor(Node *node) { // O(1)
    node->color = !node->color; // c | 1
    if (node->left != NULL) { // c | 1
        node->left->color = !node->left->color; // c | 1
    }
    if (node->right != NULL) { // c | 1
        node->right->color = !node->right->color; // c | 1
    }
}

// OK
int getColor(Node *node) { // O(1)
    if (node == NULL) { // c | 1
        return BLACK; // c | 1
    } else {
        return node->color; // c | 1
    }
}

// OK
Node *rotationLeft(Node *node) { // O(1)
    Node *nodeRight = node->right; // c | 1
    node->right = nodeRight->left; // c | 1
    if (nodeRight->left != NULL) { // c | 1
        nodeRight->left->father = node; // c | 1
    }
    nodeRight->left = node; // c | 1
    nodeRight->father = node->father; // c | 1
    node->father = nodeRight; // c | 1
    nodeRight->color = node->color; // c | 1
    node->color = RED; // c | 1
    return nodeRight; // c | 1
}

// OK
Node *rotationRight(Node *node) { // O(1)
    Node *nodeLeft = node->left; // c | 1
    node->left = nodeLeft->right; // c | 1
    if (nodeLeft->right != NULL) { // c | 1
        nodeLeft->right->father = node; // c | 1
    }
    nodeLeft->right = node; // c | 1
    nodeLeft->father = node->father; // c | 1
    node->father = nodeLeft; // c | 1
    nodeLeft->color = node->color; // c | 1
    node->color = RED; // c | 1
    return nodeLeft; // c | 1
}

// OK
int isChangeColor(Node *node) { // O(1)
    // c | 1 + 1 + 1
    int isRightGrandsonRed = node->right != NULL && 
        (getColor(node->right->right) == RED || getColor(node->right->left) == RED);

    // c | 1 + 1 + 1
    int isLeftGrandsonRed = node->left != NULL && 
        (getColor(node->left->right) == RED || getColor(node->left->left) == RED);

    // c | 1 + 1 + 1
    return getColor(node->right) == RED && getColor(node->left) == RED && (isLeftGrandsonRed || isRightGrandsonRed);
}

// OK
int isRotationRight(Node *node) { // O(1)
    int isRightGrandsonRed = node->left != NULL && getColor(node->left->left) == RED; // c | 1 + 1
    int isRightSonRed = getColor(node->left) == RED; // c | 1 + 1

    return getColor(node->right) == BLACK && isRightSonRed && isRightGrandsonRed; // c | 1 + 1
}

// OK
int isRotationLeft(Node *node) { // O(1)
    int isRightGrandsonRed = node->right != NULL && getColor(node->right->right) == RED; // c | 1 + 1
    int isRightSonRed = getColor(node->right) == RED; // c | 1 + 1

    return getColor(node->left) == BLACK && isRightSonRed && isRightGrandsonRed; // c | 1 + 1
}

// OK
int isRotationDoubleLeft(Node *node) { // O(1)
    int isLeftGrandsonRed = node->right != NULL && getColor(node->right->left) == RED; // c | 1 + 1
    int isRightSonRed = getColor(node->right) == RED; // c | 1 + 1

    return getColor(node->left) == BLACK && isRightSonRed && isLeftGrandsonRed; // c | 1 + 1
}

// OK
int isRotationDoubleRight(Node *node) { // O(1)
    int isRightGrandsonRed = node->left != NULL && getColor(node->left->right) == RED;// c | 1 + 1
    int isLeftSonRed = getColor(node->left) == RED; // c | 1 + 1

    return getColor(node->right) == BLACK && isLeftSonRed && isRightGrandsonRed; // c | 1 + 1
}

// OK
Node *balance(Node *root) { // O(1)
    if (isRotationRight(root)) { // c | 1
        root = rotationRight(root); // c | 1 + 1
    }
    if (isRotationLeft(root)) { // c | 1
        root = rotationLeft(root); // c | 1 + 1
    }
    if (isRotationDoubleLeft(root)) { // c | 1
        root->right = rotationRight(root->right); // c | 1 + 1
        root = rotationLeft(root); // c | 1 + 1
    }
    if (isRotationDoubleRight(root)) { // c | 1
        root->left = rotationLeft(root->left); // c | 1 + 1
        root = rotationRight(root); // c | 1 + 1
    }
    if (isChangeColor(root)) { // c | 1
        changeColor(root); // c | 1 + 1
    }
    return root; // c | 1
}

/*
* Print tree
*/
void printTree() {
    if (mainTree == NULL) { // c | 1
        printf("Tree is empty\n"); // c | 1
    } else {
        if (mainTree->root == NULL) {
            printf("Tree is empty\n"); // c | 1
            return; // c | 1
        }
        printAll(mainTree->root); // c | ?
    }
}

void printAll(Node *node) {
    if (node->right != NULL) { // c | 1
        printAll(node->right); // c | T(n/2)
    }

    if (node->right != NULL && node->left != NULL) { // c | 1
        if (mainTree->root == node) { // c | 1
            printf("** ROOT **   "); // c | 1
        } else {
            printf("** NODE **   "); // c | 1
        }
        // c | 1
        printf("value: %d, color: %d | right: %d, left: %d\n", node->value, node->color, node->right->value, node->left->value);
    } else if (node->right != NULL && node->left == NULL) { // c | 1
        if (mainTree->root == node) { // c | 1
            printf("** ROOT **   "); // c | 1
        } else {
            printf("** NODE **   "); // c | 1
        }
        // c | 1
        printf("value: %d, color: %d | right: %d, left: NULL\n", node->value, node->color, node->right->value);
    } else if (node->right == NULL && node->left != NULL) { // c | 1
        if (mainTree->root == node) { // c | 1
            printf("** ROOT **   "); // c | 1
        } else {
            printf("** NODE **   "); // c | 1
        }
        // c | 1
        printf("value: %d, color: %d | right: NULL, left: %d\n", node->value, node->color, node->left->value);
    } else {
        if (mainTree->root == node) { // c | 1
            printf("** ROOT **   "); // c | 1
        } else {
            printf("** NODE **   "); // c | 1
        }
        // c | 1
        printf("value: %d, color: %d | right: NULL, left: NULL\n", node->value, node->color);
    }
    
    if (node->left != NULL) { // c | 1
        printAll(node->left); // c | T(n/2)
    }
}