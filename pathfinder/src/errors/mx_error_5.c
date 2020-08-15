#include "pathfinder.h"

static void error(int line_count);
static void check_all_lines(int line_count, char *string);

void mx_error_5(char *filename) {
    int line_count = 2;
    int counter = 0;
    char *string = mx_file_to_str(filename);
    while (*string != '\n') {
        string++;
        counter++;
    }
    string++;
    counter++;
    check_all_lines(line_count, string);
    string -= counter;
    mx_strdel(&string);
}

static void error(int line_count) {
    char *count;
    count = mx_itoa((int)(line_count));
    mx_printerr("error: line ");
    mx_printerr(count);
    mx_printerr(" is not valid\n");
    exit(1);
}
static void check_all_lines(int line_count, char *string) {
    int i;
    if (*string != '\0') {
        if (string[0] == '\n')
            error(line_count);
        for (i = 0; string[i] != '-'; i++) {
            if (!mx_in_alphabet(string[i]))
                error(line_count);
        }
        if (!mx_in_alphabet(string[i - 1]) || !mx_in_alphabet(string[i + 1]))
            error(line_count);
        for (i = i + 1; string[i] != ','; i++) {
            if (!mx_in_alphabet(string[i]))
                error(line_count);
        }
        for (i = i + 1; string[i] != '\n'; i++) {
            if (!mx_is_number(string[i]))
                error(line_count);
        }
        line_count += 1;
        i += 1;
        check_all_lines(line_count, string + i);
    }
}

