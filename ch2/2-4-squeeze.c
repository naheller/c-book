#include <stdio.h>

#define MAX_LEN 1000

void squeeze(char[], char[]);

void squeeze(char s1[], char s2[]) {
    int i, j, k, found_match;
    char s3[MAX_LEN];

    k = 0;

    for (i = 0; i < MAX_LEN && s1[i] != '\0'; ++i) {
        found_match = 0;

        for (j = 0; j < MAX_LEN && s2[j] != '\0'; ++j) {
            if (s1[i] == s2[j]) {
                found_match = 1;
                break;
            }
        }

        if (found_match == 0) {
           s3[k] = s1[i];
           ++k;
        }
    }

    s3[k] = '\0';

    /**
     * Overwrite contents of s1 with those of s3,
     * since exercise calls for s1 to be directly mutated.
     */
    i = k = 0;

    while ((s1[i++] = s3[k++]) != '\0') {
        ;
    }

    s1[i] = '\0';
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

    squeeze(s1, s2);
    printf("%s\n", s1);

    return 0;
}
