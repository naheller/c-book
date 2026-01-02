#include <stdio.h>

#define TEST_LIMIT      5
#define LINE_SIZE      100
#define OUTPUT_SIZE     1000

int write_line_and_ret_length(char line[], int limit);
int append_line_to_output(char output[], char line[], int start_idx);

int main() {
    char output[OUTPUT_SIZE];
    char line[LINE_SIZE];

    int i, len;
    int output_idx; // index marking next available slot in output

    output_idx = 0;

    // TODO: check whether there's enough room for another line in output
    while((len = write_line_and_ret_length(line, LINE_SIZE)) > 0) {
        if (len > TEST_LIMIT) {
            output_idx = append_line_to_output(line, output, output_idx);
        }
    }

    output[output_idx] = '\0'; // Closing off the end of the output

    // At least one line longer than TEST_LIMIT was added
    if (output[0] != '\0') {
        printf("%s %d\n", "Lines longer than", TEST_LIMIT);
        for (i = 0; i < OUTPUT_SIZE && output[i] != '\0'; ++i) {
            putchar(output[i]);
        }
    }
}

int write_line_and_ret_length(char line[], int limit) {
    int i, c;

    // limit - 1 to leave room for end line marker
    for (i = 0; i < limit - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
        line[i] = c;
    }

    // Copy over \n so output array can be printed easily
    // NOTE: However not incrementing i because while \n is a character,
    // user won't perceive it and thus it shouldn't be included in line length
    if (c == '\n') {
        line[i] = c;
        // ++i;
    }

    return i;
}

// Updating input arrays directly
int append_line_to_output(char line[], char output[], int start_idx) {
    int i;

    for (i = 0; i + start_idx < OUTPUT_SIZE && line[i] != '\n'; ++i) {
        output[i + start_idx] = line[i];
    }

    if (line[i] == '\n') {
        output[i + start_idx] = line[i];
    }

    // +1 to move marker to next available slot
    return i + start_idx + 1;
}