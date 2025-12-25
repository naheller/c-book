#include <stdio.h>

#define MAX_OUT 1000

int main() {
    int c, i, idx_start_comment;
    char output[MAX_OUT];

    i = 0;
    idx_start_comment = -1;

    while (i < MAX_OUT && (c = getchar()) != EOF) {
        // Found start of a comment, and we aren't currently inside one already
        if (i > 0 && c == '*' && output[i-1] == '/' && idx_start_comment == -1) {
            idx_start_comment = i - 1;
        // Found end of comment, and we're inside one currently
        } else if (i > 0 && c == '/' && output[i-1] == '*' && idx_start_comment != -1) {
            i = idx_start_comment;
            idx_start_comment = -1;
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
