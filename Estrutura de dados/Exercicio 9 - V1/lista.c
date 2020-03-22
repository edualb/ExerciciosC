#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

typedef struct elemento {
	int valor;
	struct elemento* prox;
} Elemento;

typedef struct lista {
	Elemento* topo; // primeiro
};

Lista* criar() {
	Lista* p = (Lista*) malloc(sizeof(Lista));
	
	if (p == NULL) {
		printf("Error ao construir pilha.\n");
		exit(1);
	}
	printf("Pilha criada com sucesso!\n");
	p->topo = NULL;
	return p;
}

int pushOrdenado(Lista* l, int v) {
	Elemento* eAux = l->topo;
	
	// Primeira inserção
	if(eAux == NULL) {
		Elemento* e = (Elemento*) malloc(sizeof(Elemento));
		e->valor = v;
		e->prox = NULL;
		l->topo = e;
		return 1;
	}
	
	// Caso o primeiro elemento da lista seja > que v.
	if (eAux->valor > v) {
		Elemento* e = (Elemento*) malloc(sizeof(Elemento));
		e->valor = v;
		e->prox = eAux;
		l->topo = e;
		return 1;
	} else {
		ordena(eAux, v);
	}
}

void ordena(Elemento* e, int v) {
	//Insere no ultimo
	if (e->prox == NULL) {
		Elemento* eAux = (Elemento*) malloc(sizeof(Elemento));
		eAux->valor = v;
		eAux->prox = NULL;
		e->prox = eAux;
		return;
	}
	
	// Precisa enchergar o atual e o proximo do atual
	if (v > e->valor && v > e->prox->valor) {
		ordena(e->prox, v);
	} else {
		Elemento* eAux = (Elemento*) malloc(sizeof(Elemento));
		eAux->valor = v;
		eAux->prox = e->prox;
		e->prox = eAux;
	}
}

int push(Lista* p, int v) {
	Elemento* e = (Elemento*) malloc(sizeof(Elemento));
	
	if (p == NULL || e == NULL) {
		return 0;
	}
	
	e->valor = NULL;
	e->prox = NULL;
	
	if (p->topo == NULL) {
		e->valor = v;
		p->topo = e;
		return 1;
	}
	
	e->valor = v;
	e->prox = p->topo;
	p->topo = e;
	
	return 1;
}

int pop(Lista* p, int* c) {
	if(vazia(p)) {
		return 0;
	}
	
	Elemento* eAux = p->topo;
	*c = p->topo->valor;
	p->topo = p->topo->prox;
	free(eAux);
	
	return 1;
}

int vazia(Lista* p) {
	if (p->topo == NULL) {
		return 1;
	}
	return 0;
}

void libera(Lista* p) {
	Lista* pAux = p;
	while(pAux->topo != NULL) {
		Elemento* eLibera = p->topo;
		pAux->topo = pAux->topo->prox;
		free(eLibera);
	}
}

void imprimir(Lista* p) {
	Lista* pAux = p;
	while (pAux->topo != NULL) {
		printf("%d, ", pAux->topo->valor);
		pAux->topo = pAux->topo->prox;
	}
}
