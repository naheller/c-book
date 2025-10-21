#include <stdio.h>

/* print fahrenheit-celsius table for fahr = 0, 20, ... 300 */

#define     LOWER   0
#define     UPPER   300
#define     STEP    20

main()
{
    // float fahr, celsius;
    // int lower, upper, step;

    // lower = 0;
    // upper = 300;
    // step = 26;

    // celsius = lower;

    // printf("Fahrenheit-Celsius\n");
    // while (fahr <= upper) {
    //     celsius = (5.0/9.0) * (fahr-32.0);
    //     printf("%3.0f %6.1f\n", fahr, celsius);
    //     fahr = fahr + step;
    // }

    // printf("Celsius-Fahrenheit\n");
    // while (celsius <= upper) {
    //     fahr = celsius * (9.0/5.0) + 32.0;
    //     printf("%3.0f %6.1f\n", celsius, fahr);
    //     celsius = celsius + step;
    // }

    int fahr;

    for (fahr = UPPER; fahr >= LOWER; fahr = fahr - STEP) {
        printf("%3d %6.1f\n", fahr, (5.0/9.0) * (fahr-32));
    }
}