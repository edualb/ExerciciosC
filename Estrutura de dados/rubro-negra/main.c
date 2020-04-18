#include <stdlib.h>
#include <stdio.h>
#include "lib/rubro-negra.h"

void insertNewNode(int value);

int main(int argc, char *argv[]) {

    insertNewNode(11);
    insertNewNode(2);
    insertNewNode(14);
    insertNewNode(1);
    insertNewNode(7);
    insertNewNode(5);
    insertNewNode(8);
    insertNewNode(13);
    insertNewNode(15);
    printTree();
}

void insertNewNode(int value) {
    Node* node = create(value);
    insert(node);
}