#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

int main(int argc, char *argv[]) {
	Pilha* p = criar();
	int i;
	char d;
	
	if(vazia(p)){
		printf("Pilha Vazia\n");
	}
	
	for (i = 0 ; i < 3 ; i++) {
		char c;
		printf("Digite uma letra:\n");
		scanf(" %c", &c);
		push(p, c);
	}
	
	pop(p, &d);
	
	printf("Valor removido: %c\n", d);
	
	libera(p);
	
	if(vazia(p)){
		printf("Pilha Vazia");
	}
	
	imprimir(p);
	
	return 0;
}
