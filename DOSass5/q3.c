#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define MAX_COUNT 20

// Semaphores to synchronize threads
sem_t semA;
sem_t semB;

// Thread function for printing 'A'
void* print_A(void* arg) {
    for (int i = 0; i < MAX_COUNT; i++) {
        sem_wait(&semA); // Wait for semaphore A
        printf("A");
        fflush(stdout);
        sem_post(&semB); // Signal semaphore B
    }
    pthread_exit(NULL);
}

// Thread function for printing 'B'
void* print_B(void* arg) {
    for (int i = 0; i < MAX_COUNT; i++) {
        sem_wait(&semB); // Wait for semaphore B
        printf("B");
        fflush(stdout);
        sem_post(&semA); // Signal semaphore A
    }
    pthread_exit(NULL);
}

int main() {
    pthread_t threadA, threadB;

    // Initialize semaphores
    sem_init(&semA, 0, 1); // Start with semA available
    sem_init(&semB, 0, 0); // semB is initially unavailable

    // Create threads
    pthread_create(&threadA, NULL, print_A, NULL);
    pthread_create(&threadB, NULL, print_B, NULL);

    // Wait for threads to complete
    pthread_join(threadA, NULL);
    pthread_join(threadB, NULL);

    // Destroy semaphores
    sem_destroy(&semA);
    sem_destroy(&semB);

    printf("\nAlternating characters completed.\n");
    return 0;
}
