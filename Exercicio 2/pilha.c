#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

struct pilha {
	Elemento* topo;
};

struct elemento {
	int valor;
	Elemento* prox;
};

Pilha* criaPilha() {
	Pilha* p = (Pilha*) malloc(sizeof(Pilha));
	
	if (p == NULL) {
		printf("Memoria cheia.");
		exit(1);
	}
	
	p->topo = NULL;
	printf("Memoria da pilha criada.");
	return p;
}
