#include <stdio.h>

#define MAX_OUT 1000

int main() {
    int c, i, idx_start_comment, in_quote, in_char_const;
    char output[MAX_OUT];

    i = 0;
    idx_start_comment = -1;
    in_char_const = 0;
    in_quote = 0;

    while (i < MAX_OUT && (c = getchar()) != EOF) {
        /**
         * Found start of a comment,
         * and we aren't currently inside one already,
         * and we aren't inside quotes or a char const
         */
        if (
            i > 0
            && c == '*'
            && output[i-1] == '/'
            && idx_start_comment == -1
            && in_char_const == 0
            && in_quote == 0
        ) {
            idx_start_comment = i - 1;
            /**
             * Found end of a comment,
             * and we're currently inside one,
             * but we aren't inside quotes or a char const
             */
        } else if (
            i > 0
            && c == '/'
            && output[i-1] == '*'
            && idx_start_comment != -1
            && in_char_const == 0
            && in_quote == 0
        ) {
            i = idx_start_comment;
            idx_start_comment = -1;
        } else {
            if (c == '\'') {
                if (in_char_const == 0) {
                    in_char_const = 1;
                } else {
                    in_char_const = 0;
                }
            }
            if (c == '"') {
                if (in_quote == 0) {
                    in_quote = 1;
                } else {
                    in_quote = 0;
                }
            }
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
