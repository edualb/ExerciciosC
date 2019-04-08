#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "palindromo.h"
// #include "pilha.h"

struct pilha {
	Letra* topo;
};

struct letra {
	char valor;
	Letra* prox;
};

void palindromo(Pilha* p, char* s) {
	
	int i;
	char* sInvertida;
	
	for(i = 0 ; i < strlen(s) ; i++) {	
		empilha(p, s[i]);
	}
	
	sInvertida = (char*) malloc(strlen(s) * sizeof(sInvertida));
	desempilhaTUDAO(p, sInvertida);
	
	if (strcmp(s, sInvertida) == 0) {
		printf("A palavra %s e um palindromo.", sInvertida);
	} else {
		printf("A palavra %s nao e um palindromo.", s);
	}
}

void empilha(Pilha* p, char letra) {
	Letra* l = (Letra*) malloc(sizeof(Letra));
	
	if (l == NULL) {
		printf("Memoria cheia.");
		exit(1);
	}
	
	l->valor = letra;
	l->prox = p->topo;
	p->topo = l;
}

void desempilhaTUDAO(Pilha* p, char* sNova) {
	int i = 0;
	while(p->topo != NULL) {
		Letra* l = p->topo;
		p->topo = p->topo->prox;
		sNova[i] = l->valor;
		i++;
		free(l);
	}
	sNova[i] = '\0';
}

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
