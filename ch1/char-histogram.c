#include <stdio.h>

#define ALPHA_RANGE     26
#define NUM_RANGE       10
#define TOTAL_RANGE     ALPHA_RANGE + NUM_RANGE

main()
{
    int c, i, j, chars[TOTAL_RANGE];

    for (i = 0; i < TOTAL_RANGE; ++i) {
        chars[i] = 0;
    }

    while ((c = getchar()) != EOF) {
        if (c >= 'a' && c <= 'z') {
            ++chars[c - 'a'];
        }
        else if (c >= '0' && c <= '9') {
            ++chars[c - '0' + ALPHA_RANGE];
        }
    }

    // TODO: Label each bar with its character?
    for (i = 0; i < TOTAL_RANGE; ++i) {
        printf("[");
        for (j = chars[i]; j > 0; --j) {
            printf("-");
        }
        printf("]\n");
    }
}