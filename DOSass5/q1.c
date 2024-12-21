#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define BUFFER_SIZE 10
#define ITERATIONS 5

int buffer[BUFFER_SIZE];
int count = 0; 

pthread_mutex_t mutex;
sem_t empty;  
sem_t full;
void* producer(void* arg) {
    for (int i = 1; i <= ITERATIONS; i++) {
        sem_wait(&empty); 
        pthread_mutex_lock(&mutex);

        buffer[count] = i;
        printf("Producer: Produced %d\n", buffer[count]);
        count++;

        pthread_mutex_unlock(&mutex); 
        sem_post(&full); 

        sleep(1); 
    }
    pthread_exit(NULL);
}

void* consumer(void* arg) {
    for (int i = 1; i <= ITERATIONS; i++) {
        sem_wait(&full); 
        pthread_mutex_lock(&mutex); 

        count--;
        int item = buffer[count];
        printf("Consumer: Consumed %d\n", item);

        pthread_mutex_unlock(&mutex); 
        sem_post(&empty); 

        sleep(1); 
    }
    pthread_exit(NULL);
}

int main() {
    pthread_t producer_thread, consumer_thread;

    pthread_mutex_init(&mutex, NULL);
    sem_init(&empty, 0, BUFFER_SIZE); 
    sem_init(&full, 0, 0);

    pthread_create(&producer_thread, NULL, producer, NULL);
    pthread_create(&consumer_thread, NULL, consumer, NULL);

    pthread_join(producer_thread, NULL);
    pthread_join(consumer_thread, NULL);

    pthread_mutex_destroy(&mutex);
    sem_destroy(&empty);
    sem_destroy(&full);

    printf("Producer-Consumer simulation completed.\n");
    return 0;
}
