#include <stdio.h>
#include <stdlib.h>
#include "listaDupEnc.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	Lista* l = NULL;
	int i;
	
	l = criaLista();
	
	for (i = 0 ; i < 2 ; i++) {
		inserir(l);	
	}
	
	imprimir(l);
	return 0;
}
