#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <pthread.h>

int wait = 0;
int answer;
void *multiply(void *args);
void *buildMenu(void *args);

int main(int argc, char *argv[]) {
    int threadsCreated = 0;
    int rc;

    while (1) {
        while (wait) {}

        pthread_t *threadMenu;
        threadMenu = (pthread_t *) malloc(sizeof(pthread_t));
        threadsCreated++;
        printf("Thread menu #%d\n", threadsCreated);
        rc = pthread_create(threadMenu, NULL, buildMenu, NULL);
        wait = 1;

        if (rc) {
            printf("ERROR; return code from pthread_created() is %d\n", rc);
            exit(-1);
        }

        while (wait) {}

        switch (answer) {
        case 0: ;
            pthread_t *thread;
            thread = (pthread_t *) malloc(sizeof(pthread_t));
            threadsCreated++;
            printf("Thread multiply #%d\n", threadsCreated);

            // intptr_t is necessary because it has the same size of pointer(not int).
            // https://stackoverflow.com/questions/19527965/cast-to-pointer-from-integer-of-different-size-pthread-code
            rc = pthread_create(thread, NULL, multiply, (void *)(intptr_t)threadsCreated);
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
    printf("Put a value to multiply to: %d\n", number);
    scanf("%d", &answer);
    int result = answer * number;
    printf("Result: %d\n", result);
    wait = 0;
    pthread_exit(NULL);
}

void *buildMenu(void *args) {
    printf("\nVocê deseja criar novas threads?\n");
    printf("0 - Sim\n");
    printf("1 - Não\n");
    printf("2 - Encerrar programa\n");

    scanf("%d", &answer);
    wait = 0;
    pthread_exit(NULL);
}