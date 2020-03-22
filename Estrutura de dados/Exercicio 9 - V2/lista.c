#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

typedef struct lista {
	int v;
	struct lista *prox;
};

Lista *pushOrdenadoREC(Lista* l, int v) {	
	Lista *rl = NULL;
	
	// Primeira inserção
	if(l == NULL) {
		rl = (Lista*)malloc(sizeof(Lista));
		rl->valor = v;
		rl->prox = NULL;
	}
	else if(l->valor < v){
		l->prox = pushOrdenadoREC(l->prox, v);
		rl = l;	
	}
	else if (l->valor > v) {
		rl = (Lista*)malloc(sizeof(Lista));
		rl->valor = v;
		rl->prox = l;
	}
	return rl;
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
