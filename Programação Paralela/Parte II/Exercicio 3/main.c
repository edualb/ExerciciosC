#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <pthread.h>

int wait = 0;
void *multiply(void *args);

int main(int argc, char *argv[]) {
    int threadsCreated = 0;
    while (1) {
        while (wait) {}
        
        printf("\nVocê deseja criar novas threads?\n");
        printf("0 - Sim\n");
        printf("1 - Não\n");
        printf("2 - Encerrar programa\n");

        int answer;
        scanf("%d", &answer);

        switch (answer) {
        case 0:
            threadsCreated++;
            pthread_t *thread;
            thread = (pthread_t *) malloc(sizeof(pthread_t));
            printf("Thread #%d", threadsCreated);

            // intptr_t is necessary because it has the same size of pointer(not int).
            // https://stackoverflow.com/questions/19527965/cast-to-pointer-from-integer-of-different-size-pthread-code
            int rc = pthread_create(thread, NULL, multiply, (void *)(intptr_t)threadsCreated);
            wait = 1;
            
            if (rc) {
                printf("ERROR; return code from pthread_created() is %d\n", rc);
                exit(-1);
            }
            break;
        case 1:
            break;
        case 2:
            pthread_exit(NULL);
        default:
            break;
        }
    }
    pthread_exit(NULL);
}

void *multiply(void *args) {
    int number;
    int answer;
    number = (intptr_t) args;
    printf("Executing thread %d\n\n", number);
    printf("Put a value to multiply to: %d\n", number);
    scanf("%d", &answer);
    wait = 0;
    int result = answer * number;
    printf("Result: %d\n", result);
    pthread_exit(NULL);
}