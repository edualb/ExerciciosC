#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

// Threads Functions
void *one(void *args);
void *two(void *args);
void *three(void *args);
void *fourOrFive(void *args);
void *sixOrSeven(void *args);

// General Functions
void catch(int rc);

int main(int argc, char *argv[]) {

    pthread_t *threadOne;
    printf("#1\n");
    threadOne = (pthread_t *) malloc(sizeof(pthread_t));
    int rc = pthread_create(threadOne, NULL, one, NULL);
    catch(rc);
    pthread_exit(NULL);
}

void *one(void *args) {
    printf("Thread 1 running\n");
    pthread_t *threadTwo;
    threadTwo = (pthread_t *) malloc(sizeof(pthread_t));
    printf("#2\n");
    int rc = pthread_create(threadTwo, NULL, two, NULL);
    catch(rc);
    pthread_exit(NULL);
}

void *two(void *args) {
    printf("Thread 2 running\n");
    int threadsNumber = 2;
    int rc;
    for (int i = 0; i < threadsNumber; i++) {
        printf("#4 or 5\n");
        pthread_t *thread;
        thread = (pthread_t *) malloc(sizeof(pthread_t));
        rc = pthread_create(thread, NULL, fourOrFive, NULL);
        catch(rc);
    }
    pthread_t *threadThree;
    threadThree = (pthread_t *) malloc(sizeof(pthread_t));
    printf("#3\n");
    rc = pthread_create(threadThree, NULL, three, NULL);
    catch(rc);
    pthread_exit(NULL);
}

void *three(void *args) {
    printf("Thread 3 running\n");
    pthread_exit(NULL);
}

void *fourOrFive(void *args) {
    printf("Thread 4 or 5 running\n");
    pthread_t *thread;
    thread = (pthread_t *) malloc(sizeof(pthread_t));
    printf("#6 or 7\n");
    int rc = pthread_create(thread, NULL, sixOrSeven, NULL);
    catch(rc);
    pthread_exit(NULL);
}

void *sixOrSeven(void *args) {
    printf("Thread 6 or 7 running\n");
    pthread_exit(NULL);
}

void catch(int rc) {
    if (rc) {
        printf("ERROR; return code from pthread_created() is %d\n", rc);
        exit(-1);
    }
}