#include <stdlib.h>
#include <stdio.h>
#include "lib/rubro-negra.h"

int main(int argc, char *argv[]) {

    // References:
    // http://www.ufjf.br/jairo_souza/files/2012/11/5-Indexa%C3%A7%C3%A3o-Arvore-Vermelho-Preta.pdf
    // https://www.youtube.com/watch?v=L4gWuqpvk4E&list=PL8iN9FQ7_jt6H5m4Gm0H89sybzR9yaaka&index=110

    // INSERT
    push(30);
    push(20);
    push(40);
    push(25);
    push(28);
    printTree();
    printf("\n\n");

    // REMOVE
    // delete(40);
    // delete(30);
    // delete(20);
    // delete(25);
    // delete(28);
    // printTree();
    // printf("\n\n");

    // SEARCHING
    // get(28);
}