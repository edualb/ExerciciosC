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
	printf("Memoria da pilha criada.\n");
	return p;
}

void empilha(Pilha* p) {
	Elemento* e = (Elemento*) malloc(sizeof(Elemento));
	
	if (e == NULL) {
		printf("Memoria cheia.");
		exit(1);
	}
	
	printf("Digite o valor do elemento:\n");
	scanf("%d", &e->valor);
	
	e->prox = p->topo;
	p->topo = e;
}

void desempilha(Pilha* p) {
	Elemento* e = p->topo;
	p->topo = p->topo->prox;
	free(e);
}

void destroiPilha(Pilha* p) {
	while(p->topo != NULL) {
		desempilha(p);
	}
}

void imprimePilha(Pilha* p) {
	Elemento* eAux = p->topo;
	
	printf("\n");
	printf("Pilha:\n");
	while(p->topo != NULL) {
		printf("Valor: %d\n", p->topo->valor);
		printf("\n");
		p->topo = p->topo->prox;
	}
	
	p->topo = eAux;
}
