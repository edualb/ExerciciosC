#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

int main(int argc, char *argv[]) {
	Pilha* p = criaPilha();
	
	empilha(p);
	
	imprimePilha(p);
	return 0;
}
