#include <stdio.h>
#include <stdlib.h>

int busca_sequencial(int array[], int tamanho, int chave);
void ordenacao_insercao(int array[], int tamanho);

int main(int argc, char *argv[]) {
    int array[6] = {10, 15, 17, 5, 13, 100};

    int value = busca_sequencial(array, 6, 13);
    printf("Achei: %d\n", value);

    printf("Desordenado:\n");
    for (int i = 0; i < 6; i++) {
        printf("Desordenado: %d\n", array[i]);
    }

    ordenacao_insercao(array, 6);
    printf("\nOrdenado:\n");
    for (int i = 0; i < 6; i++) {
        printf("Orrdenado: %d\n", array[i]);
    }
    
}

int busca_sequencial(int array[], int tamanho, int chave) {
    for (int i = 0; i < tamanho; i++) {
        if (array[i] == chave) {
            return array[i];
        }
    }
    return -1;
}

void ordenacao_insercao(int *array, int tamanho) {
    for (int i = 1; i < tamanho; i++) {
        int chave = array[i];
        int j = i - 1;
        while (j >= 0 && array[j] > chave) {
            array[j+1] = array[j];
            j--;
        }
        array[j+1] = chave;    
    }
}