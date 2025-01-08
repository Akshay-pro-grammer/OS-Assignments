#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    char str[100], reversed[100];
    int length, i;

    printf("Enter a string: ");
    scanf("%s", str);

    pid_t pid = vfork(); 

    if (pid == 0) {
        length = strlen(str);
        for (i = 0; i < length; i++) {
            reversed[i] = str[length - i - 1];
        }
        reversed[length] = '\0';
        printf("Reversed string: %s\n", reversed);
        _exit(0);
    } else {
        wait(NULL);
        if (strcmp(str, reversed) == 0) {
            printf("The string is a palindrome.\n");
        } else {
            printf("The string is not a palindrome.\n");
        }
    }

    return 0;
}
