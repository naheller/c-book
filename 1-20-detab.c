#include <stdio.h>

#define SPACES  4
#define SIZE    1000

int main() {
    char input[SIZE], output[SIZE];
    int c, i, j;

    i = 0;

    while (i < SIZE && (c = getchar()) != EOF) {
        if (c == '\t') {
            j = SPACES;
            while (j > 0 && i < SIZE) {
                output[i] = ' ';
                ++i;
                --j;
            }
        } else {
            output[i] = c;
            ++i;
        }
    }

    output[i] = '\0';

    if (output[0] != '\0') {
        printf("%s", output);
    }

    return 0;
}