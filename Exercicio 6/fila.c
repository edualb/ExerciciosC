#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

typedef struct fila {
	int ini, fim, total;
	float vet[5];
};

Fila* cria() {
	Fila* f = (Fila*) malloc(sizeof(Fila));
	f->ini = 0;
	f->fim = -1;
	f->total = 0;
	return f;
}

int incr(int i) {
	if (i == 4) {
		return 0;
	}
	return i+1;
}

void insere(Fila* f, float v) {
	// Fila cheia -> 
	if (incr(f->fim) == f->ini && f->total > 0) {
		printf("Fila Cheia.\n");
        exit(1);  /* aborta programa */
	}
	
	//Insere elemento na proxima posição
	f->fim = incr(f->fim);
	f->vet[f->fim] = v;
	f->total++;
}

float retira(Fila* f) {
	float v;
	
	if (vazia(f)) {
		printf("Fila Vazia.\n");
        exit(1);  /* aborta programa */
	}
	
	// Remove elemento da fila
	v = f->vet[f->ini];
	f->ini = incr(f->ini);
	f->total--;
	
	if (f->total == 0) {
		f->ini = 0;
		f->fim -1;
	}
	
	return v;
}

int tamanho(Fila* f) {
	return f->total;
}

void libera(Fila* f) {
	free(f);
}

int vazia(Fila* f) {
	if (f->total == 0) {
		return 1;
	}
	return 0;
}

void imprime(Fila *f) {
	int i;
	int fim = 0;
	if (!vazia(f)) {
		i = f->ini; // Seta o inicial da fila
		while(!fim) {
			if (i == f->fim) { // Se o inicial == o fim, então chegamos no fim da fila.
				fim = 1;
			}
			printf("%.2f\n", f->vet[i]);
			i = incr(i); // incrimenta o i para percorrer o looping da fila
		}
	} else {
		printf("Fila Vazia.");
		exit(1);
	}
}
