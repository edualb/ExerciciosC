#include <stdlib.h>
#include <stdio.h>
#include "lib/rubro-negra.h"

void insertNewNode(int value);

int main(int argc, char *argv[]) {

    printTree();

    insertNewNode(5);
    insertNewNode(3);
    insertNewNode(7);
    insertNewNode(4);
    insertNewNode(2);
    printTree();
}

void insertNewNode(int value) {
    Node* node = create(value);
    insert(node);
}