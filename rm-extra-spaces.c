#include <stdio.h>

main()
{
    int c, d;

    d = ' ';

    while ((c = getchar()) != EOF) {
        if (c == ' ' && d == ' ') {
            ;
        }
        else {
            putchar(c);
        }
        d = c;
    }
}