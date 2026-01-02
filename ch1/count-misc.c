#include <stdio.h>

main()
{
    int c, t, b, nl;

    t = 0;
    b = 0;
    nl = 0;

    while ((c = getchar()) != EOF) {
        if (c == '\n')
            ++nl;
        if (c == '\t')
            ++t;
        if (c == ' ')
            ++b;
    }

    printf("%s %d\n", "Tabs:", t);
    printf("%s %d\n", "Blanks:", b);
    printf("%s %d\n", "New lines:", nl);
}