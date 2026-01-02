#include <stdio.h>

// TODO: is LINE_SIZE needed?
#define LINE_SIZE 100
#define OUT_SIZE 10000

// Leave input string untouched
int reverse(char s[]);
int reverse_and_print(char s[]);

int main() {
    int c, i, j;
    char output[OUT_SIZE];

    i = j = 0;

    // OUT_SIZE - 1 to leave room for \0 marker
    while (i < OUT_SIZE - 1 && (c = getchar()) != EOF) {
        output[i] = c;
        ++i;
    }

    output[i] = '\0';

    reverse_and_print(output);

    return 0;
}

int reverse_and_print(char s[]) {
    // Run thru output and reverse + print each time a \n is encountered
    int i, j;
    char line[LINE_SIZE];

    i = j = 0;

    while (i < OUT_SIZE && s[i] != '\0') {
        line[j] = s[i];

        if (line[j] == '\n') {
            line[j] = '\0';

            // Reverse, print, and reset line index
            reverse(line);
            printf("%s\n", line); // TIL printf() stops at the null terminator \0 automatically
            j = 0;
        }
        else {
            ++j;
        }

        ++i;
    }

    return 0;
}

int reverse(char s[]) {
    int i, j;

    i = j = 0;

    // Find end of string
    while (s[i] != '\0' && i < LINE_SIZE) {
        ++i;
    }

    if (i == LINE_SIZE) {
        return 1;  // Error: ran through s[] without finding \0 marker
    }
    else {
        char temp;

        // Roll back before \0 marker
        --i;

        while (j < i) {
            temp = s[j];
            s[j] = s[i];
            s[i] = temp;
            
            ++j;
            --i;
        }
    }

    return 0;
}