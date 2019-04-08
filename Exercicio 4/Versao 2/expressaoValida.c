#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.h"

int ehExpressaoValida(char* expressao) {
	Pilha* p = criar();
	char c;
	int i;
	
	for(i = 0 ; i < (int) strlen(expressao) ; i++) {		
		if (expressao[i] == '(') {
			push(p, expressao[i]);
		}
		
		if (expressao[i] == ')') {
			if (vazia(p)) {
				printf("Fecha parenteses sem abre parenteses (posicao %d).", i);
				exit(1);
			} else {
				pop(p, &c);
			}
		}
	}
	if (vazia(p)) {
		return 1;
	}
	return 0;
}
