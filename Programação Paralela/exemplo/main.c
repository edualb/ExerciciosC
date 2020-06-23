#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    
}

void print_array(int array[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d\n", array[i]);
    }
}

void selection_sort(int array[], int size) {        // custo | vezes
    int min, aux;                                   // c     | 1
    for (int i = 0; i < size; i++) {                // c     | n
        min = i;                                    // c     | (n-1)
        for (int j = 0; j < size; j++) {            // c     | (somatório de i = 0 até n de j) - 1
            if (array[j] < array[min]) {            // c     | somatório de i = 0 até n de (j-1)
                min = j;                            // c     | somatório de i = 0 até n de (j-1)
            }
        }
        if (array[i] != array[min]) {               // c     | (n - 1)
            aux = array[i];                         // c     | (n - 1)
            array[i] = array[min];                  // c     | (n - 1)
            array[min] = aux;                       // c     | (n - 1)
        }
    }
    
}