#include <stdio.h>
#include <string.h>

void vulnerable_function(char *input) {
    char buffer[64];  // Only 64 bytes of space
    strcpy(buffer, input);  // No bounds checking - DANGER!
    printf("You entered: %s\n", buffer);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <input_string>\n", argv[0]);
        return 1;
    }
    vulnerable_function(argv[1]);
    return 0;
}

