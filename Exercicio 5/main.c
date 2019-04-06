#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main(int argc, char *argv[]) {
	int v, i;
	Lista* l;
	
	l = criaLista();
	
	for (i = 0 ; i < 3 ; i++) {
		printf("digite um numero:\n");
		scanf("%d", &v);
		inserir(l, v);
	}
	
	inserirFinal(l, 5858585858);

	imprimeLista(l);

}
