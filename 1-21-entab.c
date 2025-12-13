#include <stdio.h>

#define SPACES      4
#define OUT_SIZE    1000

int main() {
    char output[OUT_SIZE];
    int c, i, num_spaces;

    i = 0;
    num_spaces = 0;

    while (i < OUT_SIZE) {
        c = getchar();

        if (c == ' ') {
            ++num_spaces;
        } else {
            if (num_spaces > 0) {
                while (num_spaces > 0) {
                    if (num_spaces % SPACES == 0) {
                        output[i] = '\t';
                        num_spaces -= SPACES;
                    } else {
                        output[i] = ' ';
                        --num_spaces;
                    }
                    ++i;
                }
            }
            if (c == EOF) {
                break;
            } else {
                output[i] = c;
                ++i;
            }
        }
    }

    output[i] = '\0';

    if (output[0] != '\0') {
        printf("%s", output);
    }

    return 0;
}
