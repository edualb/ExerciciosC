#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.h"

int verificaexpressaoAritmetica(char* string, Pilha* p) {
	int i;
	
	for(i = 0 ; i < strlen(string); i++) {
		if (string[i] == '(') {
			empilha(p, string[i]);
		}
		if (string[i] == ')') {
			if (vazia(p)) {
				printf("Fecha par�nteses sem abre par�nteses (posi��o i).");
				exit(1);
			} else {
				desempilha(p);
			}
		}
	}
	if (vazia(p) == 0) {
		return 0;
	}
	return 1;
}
