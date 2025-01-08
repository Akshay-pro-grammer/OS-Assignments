#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>

void check_palindrome(char *binary) {
    int len = strlen(binary);
    for (int i = 0; i < len / 2; i++) {
        if (binary[i] != binary[len - i - 1]) {
            printf("The binary representation is not a palindrome.\n");
            return;
        }
    }
    printf("The binary representation is a palindrome.\n");
}

void to_binary(int n, char *binary) {
    int i = 0;
    while (n > 0) {
        binary[i++] = (n % 2) + '0';
        n /= 2;
    }
    binary[i] = '\0';
    for (int j = 0; j < i / 2; j++) {
        char temp = binary[j];
        binary[j] = binary[i - j - 1];
        binary[i - j - 1] = temp;
    }
}

int main() {
    int n;
    printf("Enter a non-negative integer: ");
    scanf("%d", &n);

    pid_t pid = fork();
    if (pid == 0) {
        char binary[32];
        to_binary(n, binary);
        printf("Binary representation: %s\n", binary);
        _exit(0);
    } else {
        wait(NULL);
        char binary[32];
        to_binary(n, binary);
        check_palindrome(binary);
    }
    return 0;
}
