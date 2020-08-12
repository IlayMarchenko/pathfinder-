#include "pathfinder.h"

static void error(int number_of_str) {
    mx_printerr("error: line ");
    mx_printerr(mx_itoa(number_of_str));
    mx_printerr(" is not valid");
    exit(1);
}

static void check_the_same_name(char *filename) {
    char **array = NULL;
    int number_of_str = 2;
    char *string = mx_file_to_str(filename);
    int len = mx_count_character(string, '-') * 2;
    mx_del_not_alphabet(string);
    array = mx_strsplit(string, ' ');
    for (int i = 0; i < len; i += 2, number_of_str++) {
        if (mx_strcmp(array[i], array[i + 1]) == 0) {
            error(number_of_str);
        }
    }
    mx_strdel(&string);
    mx_strdel(&array[len - 1]);
    mx_del_strarr(&array);
}

void mx_error_5(char *filename) {
    int file = open(filename, O_RDONLY);
    char *temp_str;
    int number_of_str = 2;
    int count = 0;
    char *check_last;
    temp_str = mx_read_one_line(file);
    mx_strdel(&temp_str);
    while (true) {
        temp_str = mx_read_one_line(file);
        // if we get EOF
        if (!temp_str) {
            break;
        }

        // if line has more or less then 1 ',' OR line is empty OR if number of dashes != 1
        if ((mx_count_character(temp_str, ',') != 1) || (temp_str == '\0') || (mx_count_character(temp_str, '-') != 1)) {
            mx_strdel(&temp_str);
            error(number_of_str);
        }
        while (*temp_str != ',') {
            if (!mx_in_alphabet(*temp_str) && *temp_str != '-') {
                temp_str -= count;
                mx_strdel(&temp_str);
                error(number_of_str);
            }
            temp_str++;
            count++;
        }
        temp_str++;
        count++;

        // if number - not number
        while (*temp_str) {
            if (!mx_is_number(*temp_str)) {
                temp_str -= count;
                mx_strdel(&temp_str);
                error(number_of_str);
            }
            temp_str++;
            count++;
        }
        temp_str -= count;
        mx_strdel(&temp_str);
        number_of_str++;
        count = 0;
    }
    close(file);
    check_last = mx_file_to_str(filename);
    if (check_last[mx_strlen(check_last) - 1] != '\n') {
        mx_strdel(&check_last);
        error(number_of_str);
    }
    mx_strdel(&check_last);
    check_the_same_name(filename);
}
