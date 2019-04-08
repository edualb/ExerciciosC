#include <stdio.h>
#include <stdlib.h>
#include "expressaoValida.h"

int main(int argc, char *argv[]) {
	char* exp = (char*) malloc(128*sizeof(char));
	
	scanf(" %[^\n]", exp);
	
	if(ehExpressaoValida(exp)) {
		printf("Expressao OK!");
	} else {
		printf("Ha parenteses abertos que nao foram fechados.");
	}
	return 0;
}
