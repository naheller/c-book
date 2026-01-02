#include <stdio.h>
#include <limits.h>

/* Header found at /usr/include/limits.h */

void get_char_ranges();
void get_int_ranges();

void get_char_ranges() {
    unsigned char uchar;
    signed char schar;

    schar = -1;

    printf("-- by calculation --\n");

    while (schar < 0) {
        --schar;
    }

    /**
     * Roll back schar to value right before wrap around.
     * Same is done with the other values.
     */
    printf("schar low: %d\n", ++schar);

    schar = 1;

    while (schar > 0) {
        ++schar;
    }

    printf("schar high: %d\n", --schar);

    uchar = 1;

    while (uchar > 0) {
        ++uchar;
    }

    printf("uchar low: 0\n");
    printf("uchar high: %d\n", --uchar);
}

void get_int_ranges() {
    printf("-- by referencing limits.h --\n");
    printf("INT_MIN %d\n", INT_MIN);
    printf("INT_MAX %d\n", INT_MAX);
    printf("UINT_MIN 0\n");
    printf("UINT_MAX %u\n", UINT_MAX);
}

int main() {
    get_char_ranges();
    get_int_ranges();
    return 0;
}
