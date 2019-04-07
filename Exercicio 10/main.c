#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "heap-min.h"

typedef struct item {
	char nome[20];
	int chave;
};

int main(int argc, char *argv[]) {
	Item i;
	int j;
	Fp* f = criar_filaprio(10);
	
	for (j = 0 ; j < 10 ; j++) {
		printf("\nDigite:\n");
		strncpy(i.nome, "hello", 20);
		// scanf(" %[^\n]", i.nome);
		scanf("%d", &i.chave);
		insere(f, i);
	}

	imprimeArvore(f);
	
	// printf("%s, %d", i.nome, i.chave);
	return 0;
}
