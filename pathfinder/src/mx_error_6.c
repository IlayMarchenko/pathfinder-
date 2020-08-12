#include "pathfinder.h"

static void check_result(char *filename, int result) {
    int file = open(filename, O_RDONLY);
    char *first_line = mx_read_one_line(file);
    int f_line = mx_atoi(first_line);
    if (f_line != result) {
        mx_printerr("error: invalid number of islands");
        exit(1);
    }
    mx_strdel(&first_line);
}

void mx_error_6(char *filename) {
    char *string = mx_file_to_str(filename);
    char **array;
    int counter = 0;
    int number_of_identical_points;
    mx_del_not_alphabet(string);
    int number_of_points = mx_count_words(string, ' ');
    array = mx_strsplit(string, ' ');
    for (int i = 0; i < number_of_points; i++) {
        for (int j = i + 1; j < number_of_points; j++) {
            if ((mx_strcmp(array[i], array[j]) == 0) && (mx_strcmp(array[i], "p i d o r") != 0 || mx_strcmp(array[j], "p i d o r") != 0)) {
                mx_strdel(&array[j]);
                array[j] = mx_strnew(9);
                array[j] = mx_strcpy(array[j], "p i d o r");
                counter++;
            }
        }
    }
    mx_strdel(&string);
    mx_strdel(&array[number_of_points - 1]);
    mx_del_strarr(&array);
    number_of_identical_points = number_of_points - counter;
    check_result(filename, number_of_identical_points);
}
