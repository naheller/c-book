#include <stdio.h>

#define MAX_OUT 1000

void printout(char output[]);

int main() {
    int c, i;
    char output[MAX_OUT];

    i = 0;

    // TODO: Handle very first line
    while (i < MAX_OUT && (c = getchar()) != EOF) {
        if (c == '\n') {
            // Skip trailing spaces, tabs, and newlines
            if (output[i-1] == '\n' || output[i-1] == '\t' || output[i-1] == ' ') {
                continue;
            }
        }
        output[i] = c;
        ++i;
    }

    output[i] = '\0';

    // printout(output);
    printf("%s", output);

    return 0;
}

void printout(char output[]) {
    int i;

    printf("Output:\n");
    for (i = 0; output[i] != '\0' && i < MAX_OUT; ++i) {
        putchar(output[i]);
    }
}