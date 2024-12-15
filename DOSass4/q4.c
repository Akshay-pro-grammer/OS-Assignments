#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_SIZE 100

int is_prime(int num) {
    if (num <= 1) return 0;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return 0;
    }
    return 1;
}

void generate_fibonacci(int *fib_array, int length) {
    if (length >= 1) fib_array[0] = 0;
    if (length >= 2) fib_array[1] = 1;

    for (int i = 2; i < length; i++) {
        fib_array[i] = fib_array[i - 1] + fib_array[i - 2];
    }
}

int main() {
    int n;
    printf("Enter the length of the Fibonacci series: ");
    scanf("%d", &n);

    int fib_array[n]; 
    pid_t pid = vfork();

    if (pid == 0) {
        printf("Child process with pid:%d and ppid:%d: Generating Fibonacci series...\n",getpid(),getppid());
        generate_fibonacci(fib_array, n);
        printf("Child process: Fibonacci series generated.\n");
        _exit(0);
    } else {
        wait(NULL);

        printf("Parent process: Fibonacci series:\n");
        for (int i = 0; i < n; i++) {
            printf("%d ", fib_array[i]);
        }
        printf("\n");

        printf("Parent process: Prime Fibonacci numbers with positions:\n");
        for (int i = 0; i < n; i++) {
            if (is_prime(fib_array[i])) {
                printf("Fibonacci[%d] = %d (Prime)\n", i, fib_array[i]);
            }
        }

        printf("Parent process with pid:%d and ppid:%d: Task completed.\n",getpid(),getppid());
    }

    return 0;
}
