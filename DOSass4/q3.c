#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid1, pid2, pid3;

    if ((pid1 = fork()) == 0) {
        // First child: Copy file1.txt to file2.txt using `cp`
        printf("\nFirst child process: PID = %d, Parent PID = %d\n", getpid(), getppid());
        printf("I am the first child. Copying file1.txt to file2.txt...\n");
        execlp("cp", "cp", "file1.txt", "file2.txt", NULL);
        perror("execlp failed"); // If execlp fails
        exit(1);
    }

    wait(NULL); // Wait for the first child to complete

    if ((pid2 = fork()) == 0) {
        // Second child: Display the content of file2.txt using `cat`
        printf("\nSecond child process: PID = %d, Parent PID = %d\n", getpid(), getppid());
        printf("I am the second child. Displaying content of file2.txt...\n");
        execlp("cat", "cat", "file2.txt", NULL);
        perror("execlp failed"); // If execlp fails
        exit(1);
    }

    wait(NULL); // Wait for the second child to complete

    if ((pid3 = fork()) == 0) {
        // Third child: Display sorted content of file2.txt in reverse order using `sort -r`
        printf("\nThird child process: PID = %d, Parent PID = %d\n", getpid(), getppid());
        printf("I am the third child. Displaying sorted content of file2.txt in reverse order...\n");
        execlp("sort", "sort", "-r", "file2.txt", NULL);
        perror("execlp failed"); // If execlp fails
        exit(1);
    }

    wait(NULL); // Wait for the third child to complete

    // Parent process
    printf("\nParent process: PID = %d. All child processes completed.\n", getpid());
    printf("I am the parent. All child processes completed.\n");

    return 0;
}
