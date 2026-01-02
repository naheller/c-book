#include <stdio.h>

#define MAX_INPUT_LEN 1000

int htoi(char[]);

int htoi(char s[]) {
    return 1;
}

int main() {
    int c, i, result;
    char s[MAX_INPUT_LEN];

    i = 0;

    while (
        i < MAX_INPUT_LEN
        && (c = getchar()) != '\n'
        && c != EOF
    ) {
        s[i] = c;
        ++i;
    }

    s[i] = '\0';
    result = htoi(s);
    printf("%d\n", result);

    return 0;
}
