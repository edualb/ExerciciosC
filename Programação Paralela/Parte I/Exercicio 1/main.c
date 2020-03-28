#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

#define NUM_THREADS 5

typedef struct threadArgs {
    int id;
    int randomNumber;
} *ThreadArgs;

void *multiply(void *id);

int main (int argc, char *argv[]) {
    pthread_t threads[NUM_THREADS];
    int rc;

    for(int i = 1 ; i < NUM_THREADS ; i++ ) {       
        printf("this is thread: %d\n", i);

        ThreadArgs args = (ThreadArgs) malloc(sizeof(struct threadArgs));
        args->id = i;
        args->randomNumber = rand() % (10 + 1 - 1) + 1;
        
        rc = pthread_create(&threads[i], NULL, multiply, (void *)args);
        if (rc) {
            printf("ERROR; return code from pthread_created() is %d\n", rc);
            exit(-1);
        }
    }
    pthread_exit(NULL);
}

void *multiply(void *agrs) {
    ThreadArgs my_data;
    my_data = (ThreadArgs) agrs;

    printf("Random number: %d\n", my_data->randomNumber);
    printf("Product number: %d\n", my_data->id * my_data->randomNumber);
    pthread_exit(NULL);
}

// Run: gcc -pthread -o main main.c