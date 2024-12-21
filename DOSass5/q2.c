#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define MAX_NUMBER 20

// Semaphores to control the order of execution
sem_t odd_sem;
sem_t even_sem;

// Function for thread A (prints odd numbers)
void* print_odd(void* arg) {
    for (int i = 1; i <= MAX_NUMBER; i += 2) {
        sem_wait(&odd_sem); // Wait for the odd semaphore
        printf("Thread A: %d\n", i);
        sem_post(&even_sem); // Signal the even semaphore
    }
    pthread_exit(NULL);
}

// Function for thread B (prints even numbers)
void* print_even(void* arg) {
    for (int i = 2; i <= MAX_NUMBER; i += 2) {
        sem_wait(&even_sem); // Wait for the even semaphore
        printf("Thread B: %d\n", i);
        sem_post(&odd_sem); // Signal the odd semaphore
    }
    pthread_exit(NULL);
}

int main() {
    pthread_t threadA, threadB;

    // Initialize semaphores
    sem_init(&odd_sem, 0, 1);  // Start with odd_sem available
    sem_init(&even_sem, 0, 0); // even_sem is initially unavailable

    // Create threads
    pthread_create(&threadA, NULL, print_odd, NULL);
    pthread_create(&threadB, NULL, print_even, NULL);

    // Wait for threads to finish
    pthread_join(threadA, NULL);
    pthread_join(threadB, NULL);

    // Destroy semaphores
    sem_destroy(&odd_sem);
    sem_destroy(&even_sem);

    printf("Alternating number printing completed.\n");
    return 0;
}
