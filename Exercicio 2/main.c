#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

int main(int argc, char *argv[]) {
	Pilha* p = criaPilha();
	int i;
	
	for (i = 0 ; i < 3 ; i++) {
		empilha(p);
	}
	
	printf("\n");
	printf("*** Pilha completa:\n");
	imprimePilha(p);
	
	printf("\n");
	printf("*** Pilha com um elemento removido:\n");
	desempilha(p);
	imprimePilha(p);
	
	printf("\n");
	printf("*** Pilha com todos os elementos removidos:\n");
	destroiPilha(p);
	imprimePilha(p);

	return 0;
}
