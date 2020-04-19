#include <stdlib.h>
#include <stdio.h>
#include "lib/rubro-negra.h"

void insertNewNode(int value);

int main(int argc, char *argv[]) {

    // References:
    // http://www.ufjf.br/jairo_souza/files/2012/11/5-Indexa%C3%A7%C3%A3o-Arvore-Vermelho-Preta.pdf
    // https://www.youtube.com/watch?v=L4gWuqpvk4E&list=PL8iN9FQ7_jt6H5m4Gm0H89sybzR9yaaka&index=110

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
    // insertNewNode(11);
    // insertNewNode(14);
    // insertNewNode(13);

    /* Case 3D */
    // insertNewNode(11);
    // insertNewNode(8);
    // insertNewNode(10);

    /* EXAMPLE */
    insertNewNode(2);
    insertNewNode(1);
    insertNewNode(4);
    insertNewNode(3);
    insertNewNode(5);
    insertNewNode(6);
    // INSERT 7
    insertNewNode(7);
    printTree();
}

void insertNewNode(int value) {
    Node* node = create(value);
    insert(node);
}