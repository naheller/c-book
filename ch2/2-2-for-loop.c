#include <stdio.h>

#define MAX_OUT 1000

int main() {
    int c, i;
    char s[MAX_OUT];

    /* Read input until new line */
    // for (i = 0; i < MAX_OUT-1 && (c = getchar()) != '\n' && c != EOF; ++i) {
    //     s[i] = c;
    // }

    /* Equivalent loop without using && or || */
    i = 0;
    while (i < MAX_OUT-1) {
        c = getchar();
        if (c == '\n') break;
        if (c == EOF) break;
        s[i] = c;
        ++i;
    }

    s[i] = '\0';

    if (s[0] != '\0') {
        printf("%s\n", s);
    }

    return 0;
}
