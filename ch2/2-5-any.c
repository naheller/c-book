#include <stdio.h>

#define MAX_LEN 1000

int any(char[], char[]);

int any(char s1[], char s2[]) {
    int i, j;

    for (i = 0; i < MAX_LEN && s1[i] != '\0'; ++i) {
        for (j = 0; j < MAX_LEN && s2[j] != '\0'; ++j) {
            if (s1[i] == s2[j]) {
                return i;
            }
        }
    }

    return -1;
}

int main() {
    char s1[MAX_LEN], s2[MAX_LEN];
    int i = 0, j = 0;
    int c, d;

    while (i < MAX_LEN && (c = getchar()) != '\n') {
        s1[i] = c;
        ++i;
    }

    while (j < MAX_LEN && (d = getchar()) != '\n') {
        s2[j] = d;
        ++j;
    }

    s1[i] = '\0';
    s2[j] = '\0';

    int match_idx = any(s1, s2);

    printf("Match index: %d\n", match_idx);

    return 0;
}
