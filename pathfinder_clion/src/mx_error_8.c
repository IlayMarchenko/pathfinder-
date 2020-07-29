#include "../inc/pathfinder.h"

static void check_error(double result) {
    if (result > 2147483647) {
        mx_printerr("error: sum of bridges lengths is too big");
        exit(1);
    }
}

void mx_error_8(char *filename) {
    char **array;
    double result = 0;
    int len;
    int count = 0;
    char *string = mx_file_to_str(filename);
    len = mx_count_character(string, '-');
    while (*string != '\n') {
        *string = ' ';
        string++;
        count++;
    }
    mx_numbers_only(string);
    array = mx_strsplit(string, ' ');
    result = mx_add_all_from_array(array, len);
    check_error(result);
    mx_strdel(&array[len - 1]);
    mx_del_strarr(&array);
    string -= count;
    mx_strdel(&string);
}
