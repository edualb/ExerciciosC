#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main(int argc, char *argv[]) {
	Lista* l = NULL;
	int i;
	for (i = 0 ; i < 7 ; i++) {
		int v;
		printf("Digite um valor: \n");
		scanf("%d", &v);
		pushOrdenadoREC(l, v);
	}
	imprimir(l);
	return 0;
}
