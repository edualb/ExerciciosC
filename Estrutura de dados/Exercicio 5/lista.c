#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

struct lista {
	Elemento* topo;
};

struct elemento {
	int valor;
	Elemento* prox;
};

Lista* criaLista() {
	Lista* p = (Lista*) malloc(sizeof(Lista));
	
	if (p == NULL) {
		printf("Memoria cheia.");
		exit(1);
	}
	
	p->topo = NULL;
	printf("Memoria da pilha criada.\n");
	return p;
}

void inserir(Lista* p, int v) {
	Elemento* e = (Elemento*) malloc(sizeof(Elemento));
	
	if (e == NULL) {
		printf("Memoria cheia.");
		exit(1);
	}
	
	e->valor = v;
	e->prox = p->topo;
	p->topo = e;
}

void inserirFinal(Lista* l, int v) {
	Elemento* eAux;
	Elemento* eAux2 = l->topo;
	
	while(l->topo != NULL) {
		eAux = l->topo;
		l->topo = l->topo->prox;
	}
	
	Elemento* eCriado = (Elemento*) malloc(sizeof(Elemento));
	eCriado->prox = NULL;
	eCriado->valor = v;
	
	eAux->prox = eCriado;
	l->topo = eAux2;
}

void remover(Lista* p) {
	Elemento* e = p->topo;
	p->topo = p->topo->prox;
	free(e);
}

void destroiLista(Lista* p) {
	while(p->topo != NULL) {
		remover(p);
	}
}

void imprimeLista(Lista* p) {
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
