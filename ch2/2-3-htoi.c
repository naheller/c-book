#include <linux/limits.h>
#include <stdio.h>

#define MAX_LINE 1000

int get_line(char input[]);
int htoi(char hex[], int len);

int main() {
    char input[MAX_LINE];
    int len = get_line(input);

    int result = htoi(input, len);
    printf("integer: %d\n", result);

    return 0;
}

int get_line(char input[]) {
    int c, i;
    i = 0;

    while (i < MAX_LINE && (c = getchar()) != '\n') {
        if (
            i == 1
            && input[0] == '0'
            && (c == 'x' || c == 'X')
        ) {
            /* if input starts with 0x or 0X, overwrite it */
            i = 0;
        } else {
            input[i] = c;
            ++i;
        }
    }

    input[i] = '\0';

    printf("string: %s\n", input);

    return i;
}

int htoi(char hex[], int len) {
    printf("hex: %s\n", hex);
    int result = 0;

    for (int i = 0; i < len; ++i) {
        result = result << 4;
        int value;
        if (hex[i] >= '0' && hex[i] <= '9') {
            value = hex[i] - '0';
        } else if (
            (hex[i] >= 'a' && hex[i] <= 'f')
            || (hex[i] >= 'A' && hex[i] <= 'F')
        ) {
            /* TODO: How and why does this work? */
            value = hex[i] - 'a' + 10;
        }
        printf("value: %d\n", value);
        result += value;
    }

    return result;
}
