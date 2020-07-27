#include "pathfinder.h"

void mx_error_7(char *filename) {
    char **array;
    char *string = mx_file_to_str(filename);
    mx_del_all_numbers_and_com(string);
    int number_of_points = mx_count_words(string, ' ');
    array = mx_strsplit(string, ' ');
    for (int i = 0; i < number_of_points; i++) {
        for (int j = i + 1; j < number_of_points; j++) {
            if (mx_strcmp(array[i], array[j]) == 0) {
                mx_printerr("error: duplicate bridges");
                exit(1);
            }
        }
    }
    mx_strdel(&string);
    mx_strdel(&array[number_of_points - 1]);
    mx_del_strarr(&array);
}