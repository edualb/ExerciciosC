#include <stdlib.h>
#include <stdio.h>
#include "lib/rubro-negra.h"

int main(int argc, char *argv[]) {

    // References:
    // http://www.ufjf.br/jairo_souza/files/2012/11/5-Indexa%C3%A7%C3%A3o-Arvore-Vermelho-Preta.pdf
    // https://www.youtube.com/watch?v=L4gWuqpvk4E&list=PL8iN9FQ7_jt6H5m4Gm0H89sybzR9yaaka&index=110

    /* Case 1 and 2 */
    // push(11);
    // push(2);
    // push(14);
    // push(1);
    // push(7);
    // push(5);
    // push(8);
    // push(13);
    // push(15);

    /* Case 3A */
    // push(11);
    // push(5);
    // push(1);

    /* Case 3B */
    // push(11);
    // push(14);
    // push(15);

    /* Case 3C */
    // push(11);
    // push(14);
    // push(13);

    /* Case 3D */
    // push(11);
    // push(8);
    // push(10);

    /* EXAMPLE */
    // push(2);
    // push(1);
    // push(4);
    // push(3);
    // push(5);
    // push(6);
    // INSERT 7
    // push(7);

    // push(2);
    // push(1);
    // push(48);
    // push(30);
    // push(60);
    // push(50);
    // push(70);
    // push(25);
    // push(20);
    // push(35);

    push(30);
    push(20);
    push(40);
    push(45);
    push(50);
    printTree();
    printf("\n\n\n");
    delete(50);
    printTree();
    printf("\n\n\n");
    delete(45);
    printTree();
    printf("\n\n\n");

    //SEARCHING
    // get(7);
}