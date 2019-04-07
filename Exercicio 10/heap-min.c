#include <stdio.h>
#include <stdlib.h>
#include "heap-min.h"

#define PAI(i) ((i-1) / 2)

typedef struct item {
	char nome[20];
	int chave;
};

typedef struct fp {
	Item* v;
	int n, tamanho;
};

Fp* criar_filaprio(int t) {
	Fp* filaPrio = (Fp*) malloc(sizeof(Fp));
	filaPrio->v = (Item*) malloc(t * sizeof(Item));
	filaPrio->n = 0;
	filaPrio->tamanho = t;
	return filaPrio;
}

void insere(Fp* fp , Item i) {
	fp->v[fp->n] = i;
	fp->n++;
	sobe_no_heap(fp, fp->n - 1);
}

void sobe_no_heap(Fp* fp, int n) {
	if (n > 0 && fp->v[PAI(n)].chave > fp->v[n].chave) {
		troca(&fp->v[PAI(n)], &fp->v[n]);
		sobe_no_heap(fp, PAI(n));
	}
}

void troca(Item* a, Item* b) {
	Item c = *a;
	*a = *b;
	*b = c;
}

void imprimeArvore(Fp* fp) {
	int i;
	for (i = 0 ; i < fp->n ; i++) {
		printf("\n");
		printf("Posicao arvore: %d\n", i);
		printf("Nome: %s\n", (fp->v[i]).nome);
		printf("Chave: %d\n", (fp->v[i]).chave);
		printf("*******************************\n");
	}
}
