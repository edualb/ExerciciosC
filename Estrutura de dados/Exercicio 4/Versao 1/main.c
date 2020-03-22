#include <stdio.h>
#include <stdlib.h>
#include "verificador.h"
#include "pilha.h"

int main(int argc, char *argv[]) {
	char* expressao;
	Pilha* p;
	
	p = criaPilha();
	
	expressao = (char*) malloc(120*sizeof(char));
	
	scanf(" %[^\n]", expressao);
	
	if (verificaexpressaoAritmetica(expressao, p) == 0) {
		printf("H� par�nteses abertos que n�o foram fechados.");
	} else {
		printf("express�o OK!");
	}
	return 0;
}
