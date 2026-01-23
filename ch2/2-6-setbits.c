#include <stdio.h>

int setbits(unsigned, int, int, unsigned);

int setbits(unsigned x, int p, int n, unsigned y) {
    int xmask, ymask;

    ymask = ~(~0 << n);
    y = (y & ymask) << ((p - n) + 1);

    xmask = ~(ymask << ((p - n) + 1));
    x &= xmask;

    x |= y;

    return x;
}

int main() {
    unsigned x, y;
    int p, n;

    x = 0;
    y = 7;

    p = 6;
    n = 3;

    /* Should equal 112 */

    unsigned z = setbits(x, p, n, y);

    printf("%u\n", z);

    return 0;
}
