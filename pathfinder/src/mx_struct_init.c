#include "pathfinder.h"


static void path_init(char *filename, bridges **big_array) {
    char **array = NULL;
    int n = 0;
    char *string = mx_file_to_str(filename);
    mx_del_not_alphabet(string);
    string = mx_del_dub(string);
    array = mx_strsplit(string, ' ');
    int length = mx_the_biggest_name(array, mx_count_words(string, ' '));
    for (int i = 0; i < mx_count_words(string, ' '); i++) {
        for (int j = 0; j < mx_count_words(string, ' '); j++) {
            big_array[n]->path[0] = malloc(sizeof(char) * length);
            big_array[n]->path[1] = malloc(sizeof(char) * length);
            big_array[n]->path[0] = mx_strcpy(big_array[n]->path[0], array[i]);
            big_array[n]->path[1] = mx_strcpy(big_array[n]->path[1], array[j]);
            n++;
        }
    }
    mx_strdel(&string);
    mx_del_strarr(&array);
}

static void distance_init(char *filename, bridges **big_array, int number_of_strings_in_file, int number_of_bridges) {
    char **array = NULL;
    int temp_distance;
    int file = open(filename, O_RDONLY);
    char *temp_str = mx_read_one_line(file);
    mx_strdel(&temp_str);
    for (int i = 0; i < number_of_strings_in_file; i++) {
        temp_str = mx_read_one_line(file);
        temp_distance = mx_get_distance(temp_str);
        array = mx_append_city_to_arr(temp_str);
        for (int j = 0; j < number_of_bridges; j++) {
            if ((mx_strcmp(big_array[j]->path[0], array[0]) == 0) && (mx_strcmp(big_array[j]->path[1], array[1]) == 0) && (big_array[j]->distance == -1 || big_array[j]->distance == INF)) {
                big_array[j]->distance = temp_distance;
            }
            else if ((mx_strcmp(big_array[j]->path[0], array[1]) == 0) && (mx_strcmp(big_array[j]->path[1], array[0]) == 0) && (big_array[j]->distance == -1 || big_array[j]->distance == INF)) {
                big_array[j]->distance = temp_distance;
            }
            else if ((mx_strcmp(big_array[j]->path[0], big_array[j]->path[1]) == 0) && (big_array[j]->distance == -1)) {
                big_array[j]->distance = 0;
            }
            else if (big_array[j]->distance == -1) {
                big_array[j]->distance = INF;
            }
        }
        mx_strdel(&temp_str);
        mx_strdel(&array[1]);
        mx_del_strarr(&array);
    }
    close(file);
}

static void init_main_struct (char *filename, t_main *stct) {
    stct->arr_v = NULL;
    char *string = mx_file_to_str(filename);
    mx_del_not_alphabet(string);
    string = mx_del_dub(string);
    stct->arr_v = mx_strsplit(string, ' ');
    mx_strdel(&string);
}

bridges **mx_struct_init(char *filename, t_main *stct) {
    int number_of_bridges;
    int number_of_strings_in_file;
    int file = open(filename, O_RDONLY);
    char *temp_str = mx_read_one_line(file);
    int first_line = mx_atoi(temp_str);
    stct->count = first_line;
    mx_strdel(&temp_str);
    close(file);
    number_of_bridges = (int)mx_pow(first_line, 2);
    bridges **big_array = malloc(sizeof(bridges) * number_of_bridges);
    for (int i = 0; i < number_of_bridges; i++) {
        big_array[i] = malloc(sizeof(bridges));
    }
    for (int i = 0; i < number_of_bridges; i++) {
        big_array[i]->distance = -1;
    }
    temp_str = mx_file_to_str(filename);
    number_of_strings_in_file = mx_count_character(temp_str, '\n') - 1;
    path_init(filename, big_array);
    distance_init(filename, big_array, number_of_strings_in_file, number_of_bridges);
    mx_strdel(&temp_str);
    init_main_struct(filename, stct);
    return big_array;
}

