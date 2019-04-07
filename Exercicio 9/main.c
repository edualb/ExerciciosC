#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main(int argc, char *argv[]) {
	Lista* l = criar();
	int i;
	for (i = 0 ; i < 7 ; i++) {
		int v;
		printf("Digite um valor:\n");
		scanf("%d", &v);
		pushOrdenado(l, v);
	}
	
	imprimir(l);
	return 0;
}
