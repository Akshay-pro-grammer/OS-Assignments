#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#define MAX_BUFFER 1024

void copy_file(const char *source, const char *destination) {
    FILE *src = fopen(source, "r");
    FILE *dest = fopen(destination, "w");

    char buffer[MAX_BUFFER];
    while (fgets(buffer, MAX_BUFFER, src)) {
        fputs(buffer, dest);
    }

    fclose(src);
    fclose(dest);
}

void display_file(const char *filename) {
    FILE *file = fopen(filename, "r");

    char buffer[MAX_BUFFER];
    while (fgets(buffer, MAX_BUFFER, file)) {
        printf("%s", buffer);
    }

    fclose(file);
}

char *allocate(const char *str) {
    char *dup = malloc(strlen(str) + 1);
    if (dup) strcpy(dup, str);
    return dup;
}

void display_sorted_reverse(const char *filename) {
    FILE *file = fopen(filename, "r");

    char *lines[MAX_BUFFER];
    int count = 0;

    char buffer[MAX_BUFFER];
    while (fgets(buffer, MAX_BUFFER, file)) {
        lines[count] = allocate(buffer); 
        count++;
    }
    fclose(file);
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (strcmp(lines[i], lines[j]) > 0) {
                char *temp = lines[i];
                lines[i] = lines[j];
                lines[j] = temp;
            }
        }
    }

    for (int i = count - 1; i >= 0; i--) {
        printf("%s", lines[i]);
        free(lines[i]); 
    }
}

int main() {
    pid_t pid1, pid2, pid3;

    if ((pid1 = fork()) == 0) {
        printf("\nFirst child process: PID = %d, Parent PID = %d\n", getpid(), getppid());
        printf("i am first child ,Copying file1.txt to file2.txt...\n");
        copy_file("file1.txt", "file2.txt");
        exit(0);
    }

    sleep(1);

    if ((pid2 = fork()) == 0) {
        printf("\nSecond child process: PID = %d, Parent PID = %d\n", getpid(), getppid());
        printf("i am second child ,Displaying content of file2.txt...\n");
        printf("Content of file2:\n");
        display_file("file2.txt");
        exit(0);
    }

    sleep(1);

    if ((pid3 = fork()) == 0) {
        printf("\nThird child process: PID = %d, Parent PID = %d\n", getpid(), getppid());
        printf("i am third child ,displaying Sorted content of file2 in reverse order:\n");
        display_sorted_reverse("file2.txt");
        exit(0);
    }

    wait(NULL);
    wait(NULL);
    wait(NULL);

    printf("Parent process: PID = %d, All child processes completed.\n", getpid());
    printf("i am parent ,All child processes completed.\n");

    return 0;
}
