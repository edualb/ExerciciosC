#include <stdio.h>
#include <stdlib.h>
#include "listaDupEnc.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	Lista* l = NULL;
	
	l = criaLista();
	
	inserir(l);
	
	imprimir(l);
	return 0;
}
