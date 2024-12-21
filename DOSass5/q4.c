#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

#define MAX_COUNT 10

// Semaphores for synchronization
sem_t semDown;
sem_t semUp;

// Thread function for counting down
void* count_down(void* arg) {
    for (int i = MAX_COUNT; i >= 1; i--) {
        sem_wait(&semDown); // Wait for semaphore Down
        printf("Countdown: %d\n", i);
        sem_post(&semUp); // Signal semaphore Up
    }
    pthread_exit(NULL);
}

// Thread function for counting up
void* count_up(void* arg) {
    for (int i = 1; i <= MAX_COUNT; i++) {
        sem_wait(&semUp); // Wait for semaphore Up
        printf("Countup: %d\n", i);
        sem_post(&semDown); // Signal semaphore Down
    }
    pthread_exit(NULL);
}

int main() {
    pthread_t threadDown, threadUp;

    // Initialize semaphores
    sem_init(&semDown, 0, 1); // Start with semDown available
    sem_init(&semUp, 0, 0);   // semUp is initially unavailable

    // Create threads
    pthread_create(&threadDown, NULL, count_down, NULL);
    pthread_create(&threadUp, NULL, count_up, NULL);

    // Wait for threads to complete
    pthread_join(threadDown, NULL);
    pthread_join(threadUp, NULL);

    // Destroy semaphores
    sem_destroy(&semDown);
    sem_destroy(&semUp);

    printf("Countdown and Countup completed.\n");
    return 0;
}
