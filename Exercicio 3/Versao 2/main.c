#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.h"

int ehPalindromo(char* palavra);

int main(int argc, char *argv[]) {
	char* palavra;
	
	palavra = (char*) malloc(120 * sizeof(char));
	
	printf("Digite uma palavra:\n");
	scanf(" %[^\n]", palavra);
	
	if(ehPalindromo(palavra)) {
		printf("Eh um palindromo!");
	} else {
		printf("Nao eh um palindromo!");
	}
	return 0;
}

int ehPalindromo(char* palavra) {
	Pilha* p = criar();
	int i;
	
	for (i = 0 ; i < (int) strlen(palavra) ; i++) {
		push(p, palavra[i]);
	}
	
	for (i = 0 ; i < (int) strlen(palavra) ; i++) {
		char c;
		pop(p, &c);
		if (c != palavra[i]) {
			return 0;
		}
	}
	
	return 1;
}
