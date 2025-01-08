#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

#define MAX_COUNT 20

sem_t semA, semB, semC;

void* thread_A(void* arg) {
    for (int i = 1; i <= MAX_COUNT; i += 3) {
        sem_wait(&semA); 
        printf("A%d ", i);
        sem_post(&semB); 
    }
    pthread_exit(NULL);
}

void* thread_B(void* arg) {
    for (int i = 2; i <= MAX_COUNT; i += 3) {
        sem_wait(&semB); 
        printf("B%d ", i);
        sem_post(&semC); 
    }
    pthread_exit(NULL);
}

void* thread_C(void* arg) {
    for (int i = 3; i <= MAX_COUNT; i += 3) {
        sem_wait(&semC); 
        printf("C%d ", i);
        sem_post(&semA); 
    }
    pthread_exit(NULL);
}

int main() {
    pthread_t threadA, threadB, threadC;

    sem_init(&semA, 0, 1); 
    sem_init(&semB, 0, 0); 
    sem_init(&semC, 0, 0); 

    pthread_create(&threadA, NULL, thread_A, NULL);
    pthread_create(&threadB, NULL, thread_B, NULL);
    pthread_create(&threadC, NULL, thread_C, NULL);

    pthread_join(threadA, NULL);
    pthread_join(threadB, NULL);
    pthread_join(threadC, NULL);

    sem_destroy(&semA);
    sem_destroy(&semB);
    sem_destroy(&semC);

    printf("\nSequence Printing Completed.\n");
    return 0;
}