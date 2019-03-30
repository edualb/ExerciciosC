#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

int main(int argc, char *argv[]) {
	Pilha* p = criaPilha();
	int i;
	
	for (i = 0 ; i < 3 ; i++) {
		empilha(p);
	}
	
	desempilha(p);
	
	imprimePilha(p);
	return 0;
}
