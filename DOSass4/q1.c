#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    pid_t pid = fork(); 
    if (pid == 0) {
        while (1) {
            printf("Child process with PID: %d\n", getpid());
        }
    } else {
    	// wait(NULL);
        while (1) {
            printf("Parent process with PID: %d\n", getpid());
        }
    }
    return 0;
}

