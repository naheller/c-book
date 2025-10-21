#include <stdio.h>

float ftoc(int fahr);

int main() {
    int i;

    for (i = 0; i <= 300; i = i + 20) {
        printf("%3d -> %6.1f\n", i, ftoc(i));
    }
}

float ftoc(int fahr) {
    return (5.0/9.0) * (fahr-32);
}