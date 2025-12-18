#include <stdio.h>

#define MAX_LINE    5
#define MAX_OUT     1000

int main() {
    int c, i, curr_len, last_blank_idx;
    char output[MAX_OUT];

    i = 0;
    curr_len = 0;
    last_blank_idx = -1;

    while (i < MAX_OUT && (c = getchar()) != EOF) {
        if (curr_len == MAX_LINE) {
            if (last_blank_idx != -1) {
                output[last_blank_idx] = '\n';
                curr_len = i - last_blank_idx;
                last_blank_idx = -1;
            } else {
                output[i] = '\n';
                curr_len = 0;
                ++i; // Advance i so c can be added after new space
            }
        }

        if (c == ' ') {
            last_blank_idx = i;
        }

        output[i] = c;
        ++curr_len;
        ++i;
    }

    output[i] = '\0';

    if (output[0] != '\0') {
        printf("%s", output);
    }

    return 0;
}
