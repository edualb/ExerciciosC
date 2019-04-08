#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

typedef struct elemento {
	char valor;
	struct elemento* prox;
} Elemento;

typedef struct pilha {
	Elemento* topo;
};

Pilha* criar() {
	Pilha* p = (Pilha*) malloc(sizeof(Pilha));
	
	if (p == NULL) {
		printf("Error ao construir pilha.\n");
		exit(1);
	}
	printf("Pilha criada com sucesso!\n");
	p->topo = NULL;
	return p;
}

int push(Pilha* p, char c) {
	Elemento* e = (Elemento*) malloc(sizeof(Elemento));
	
	if (p == NULL || e == NULL) {
		return 0;
	}
	
	e->valor = NULL;
	e->prox = NULL;
	
	if (p->topo == NULL) {
		e->valor = c;
		p->topo = e;
		return 1;
	}
	
	e->valor = c;
	e->prox = p->topo;
	p->topo = e;
	
	return 1;
}

int pop(Pilha* p, char* c) {
	if(vazia(p)) {
		return 0;
	}
	
	Elemento* eAux = p->topo;
	*c = p->topo->valor;
	p->topo = p->topo->prox;
	free(eAux);
	
	return 1;
}

int vazia(Pilha* p) {
	if (p->topo == NULL) {
		return 1;
	}
	return 0;
}

void libera(Pilha* p) {
	Pilha* pAux = p;
	while(pAux->topo != NULL) {
		Elemento* eLibera = p->topo;
		pAux->topo = pAux->topo->prox;
		free(eLibera);
	}
}

void imprimir(Pilha* p) {
	Pilha* pAux = p;
	while (pAux->topo != NULL) {
		printf("%c", pAux->topo->valor);
		pAux->topo = pAux->topo->prox;
	}
}
