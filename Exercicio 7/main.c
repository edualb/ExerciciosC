#include <stdio.h>
#include <stdlib.h>

int buscaBincaria(int* vet, int v, int inicio, int fim);

int main(int argc, char *argv[]) {
	int vet[] = {1, 4, 8, 10, 16};
	int tamanhoVet = (int) sizeof(vet) / sizeof(vet[0]);
	printf("****** INICIO DA RECURSIVIDADE ******\n");
	int indice = buscaBincaria(vet, 16, 0, tamanhoVet);
	printf("****** FIM DA RECURSIVIDADE ******\n\n");
	printf("Indice: %d\n", indice);
	return 0;
}

int buscaBincaria(int* vet, int key, int inicio, int fim) {
	int meio = (int) (inicio + fim) / 2;
	printf("Inicio: %d\n", inicio);
	printf("Fim: %d\n", fim);
	printf("Meio: %d\n", meio);
	printf("-------------\n\n");
	if (vet[meio] == key) {
		return meio;
	}
	
	while(inicio < fim) {
		if (key > vet[meio]) {
			return buscaBincaria(vet, key, meio + 1, fim);
		}
		
		if (key < vet[meio]) {
			return buscaBincaria(vet, key, inicio, meio - 1);
		}
	}
	
	return -1;
}
