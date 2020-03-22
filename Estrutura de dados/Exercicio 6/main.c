#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

int main(int argc, char *argv[]) {
	Fila* f = cria();
	int i;
	for (i = 0 ; i < 3 ; i++) {
		insere(f, (float) i);
	}
	imprime(f);
}
