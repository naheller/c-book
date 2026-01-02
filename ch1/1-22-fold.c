#include <stdio.h>

#define MAX_LINE    5
#define MAX_OUT     1000

int main() {
    int c, i, curr_len, last_blank_idx;
    char output[MAX_OUT];

    i = 0;
    curr_len = 0;
    last_blank_idx = -1;

    while (i < MAX_OUT) {
        if (curr_len == MAX_LINE) {
            if (last_blank_idx != -1) {
                output[last_blank_idx] = '\n';
                curr_len = i - last_blank_idx;
                printf("%d\n", curr_len);
                last_blank_idx = -1;
            } else {
                output[i] = '\n';
                ++i;
                curr_len = 0;
            }
        } else {
            c = getchar();

            if (c == EOF) {
                break;
            }

            if (c == ' ') {
                // Avoid consecutive spaces, or adding a space after a line break
                // if (i > 0 && ((output[i-1]) == ' ' || (output[i-1]) == '\n')) {
                //     continue;
                // }
                last_blank_idx = i;
            }

            output[i] = c;
            ++i;
            ++curr_len;
        }
    }

    output[i] = '\0';

    if (output[0] != '\0') {
        printf("%s", output);
    }

    return 0;
}
