#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "palindromo.h"

int main(int argc, char *argv[]) {
	
	Pilha* pilha;
	char* palavra;
	int i;
	
	palavra = (char*) malloc(128*sizeof(char));
	pilha = criaPilha();
	
	printf("Digite uma palavra:\n");
	scanf("%[^\n]", palavra);
	
	palindromo(pilha, palavra);
	
	return 0;
}
