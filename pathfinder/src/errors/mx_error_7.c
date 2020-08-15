#include "pathfinder.h"

typedef struct error_7 {
    char *array_struct[2];
}              error_7;

static void check(int number_of_bridges, error_7 **structure);

void mx_error_7(char *filename) {
    char **array;
    char *string = mx_file_to_str(filename);
    int number_of_bridges = mx_count_character(string, '-');
    mx_del_not_alphabet(string);
    array = mx_strsplit(string, ' ');
    error_7 **structure = malloc(sizeof(error_7) * number_of_bridges);
    for (int i = 0; i < number_of_bridges; i++) {
        structure[i] = malloc(sizeof(error_7));
    }
    for (int i = 0, j = 0; i < number_of_bridges * 2; i += 2, j++) {
        structure[j]->array_struct[0] = array[i];
        structure[j]->array_struct[1] = array[i+1];
    }
    check(number_of_bridges, structure);
    mx_strdel(&string);
    mx_strdel(&array[(number_of_bridges * 2) - 1]);
    mx_del_strarr(&array);
    for (int i = 0; i < number_of_bridges; i++)
        free(structure[i]);
    free(structure);
}

static void check(int number_of_bridges, error_7 **structure) {
    for (int i = 0; i < number_of_bridges; i++) {
        for (int j = i + 1; j < number_of_bridges; j++) {
            if (mx_strcmp(structure[i]->array_struct[0], structure[j]->array_struct[1]) == 0
                && mx_strcmp(structure[i]->array_struct[1], structure[j]->array_struct[0]) == 0) {
                mx_printerr("error: duplicate bridges\n");
                exit(1);
            }
            else if (mx_strcmp(structure[i]->array_struct[0], structure[j]->array_struct[0]) == 0
                     && mx_strcmp(structure[i]->array_struct[1], structure[j]->array_struct[1]) == 0) {
                mx_printerr("error: duplicate bridges\n");
                exit(1);
            }
        }
    }
}
