#include <stdlib.h>
#include <stdio.h>
#include "lib/rubro-negra.h"

void insertNewNode(int value);

int main(int argc, char *argv[]) {

    /* Case 1 and 2 */
    // insertNewNode(11);
    // insertNewNode(2);
    // insertNewNode(14);
    // insertNewNode(1);
    // insertNewNode(7);
    // insertNewNode(5);
    // insertNewNode(8);
    // insertNewNode(13);
    // insertNewNode(15);

    /* Case 3A */
    // insertNewNode(11);
    // insertNewNode(5);
    // insertNewNode(1);

    /* Case 3B */
    // insertNewNode(11);
    // insertNewNode(14);
    // insertNewNode(15);

    /* Case 3C */
    insertNewNode(11);
    insertNewNode(14);
    insertNewNode(15);
    printTree();
}

void insertNewNode(int value) {
    Node* node = create(value);
    insert(node);
}