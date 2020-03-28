#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

#define ARRAY_SIZE 1000

void *sumCalculator(void *threadArg);
void *getBiggerValue(void *threadArg);

int main(int argc, char *argv[]) {

    int *values;
    int rc;
    values = (int *) malloc(sizeof(int)*ARRAY_SIZE);

    // srand is necessary to generate always random numbers.
    srand(time(NULL));
    
    printf("Values: ");
    for (int i = 0; i < ARRAY_SIZE; i++) {
        int randomNumber = rand() % (1000 + 1 - 1) + 1;
        values[i] = randomNumber;
        printf("%d, ", values[i]);
    }
    
    pthread_t *sumCalculatorThread;
    sumCalculatorThread = (pthread_t *) malloc(sizeof(pthread_t));
    printf("\n#Thread: 1\n");
    rc = pthread_create(sumCalculatorThread, NULL, sumCalculator, (void *)values);
    if (rc) {
        printf("ERROR; return code from pthread_created() is %d\n", rc);
        exit(-1);
    }

    pthread_t *getBiggerValueThread;
    getBiggerValueThread = (pthread_t *) malloc(sizeof(pthread_t));
    printf("#Thread: 2\n");
    rc = pthread_create(getBiggerValueThread, NULL, getBiggerValue, (void *)values);
    if (rc) {
        printf("ERROR; return code from pthread_created() is %d\n", rc);
        exit(-1);
    }
    pthread_exit(NULL);
}

void *sumCalculator(void *threadArg) {
    int *values;
    values = (int *) threadArg;
    int total = 0;

    for (int i = 0; i < ARRAY_SIZE; i++) {
        total += values[i];
    }
    printf("Total: %d\n", total);
    pthread_exit(NULL);
}

void *getBiggerValue(void *threadArg) {
    int *values;
    values = (int *) threadArg;
    int biggerValue = 0;
    for (int i = 0; i < ARRAY_SIZE; i++) {
        if (biggerValue == 0) {
            biggerValue = values[i];
        } else {
            if (biggerValue < values[i]) {
                biggerValue = values[i];
            }
        }
    }
    printf("Bigger value: %d\n", biggerValue);
    pthread_exit(NULL);
}

// Run: gcc -pthread -o main main.c