#include <stdio.h>

// Word length histogram for first 5 words

#define IN 1
#define OUT 0

main()
{
    int c, i, j, count, p_state, words[5];

    j = count = 0;
    p_state = OUT;

    for (i = 0; i < 5; ++i)
        words[i] = 0;

    while (j < 5 && (c = getchar()) != EOF) {
        if (c == ' ' || c == '\t' || c == '\n') {
            if (p_state == IN) {
                // Exiting word; save count, increment j, and reset count
                words[j] = count;
                ++j;
                count = 0;
                p_state = OUT;
            }
        } 
        else {
            ++count;
            if (p_state == OUT) {
                // Entering new word; set state
                p_state = IN;
            }
        }
    }

    for (i = 0; i < 5; ++i) {
        if (words[i] == 0)
            continue;

        printf("[");
        for (j = words[i]; j > 0; --j) {
            printf("-");
        }
        printf("]\n");
    }
}