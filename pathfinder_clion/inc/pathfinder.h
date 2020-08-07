#ifndef PATHFINDER_H
#define PATHFINDER_H


#include "../libmx/inc/libmx.h"
#define INF 2147483649


typedef struct bridges {
    char *path[2];
    long distance;


}              bridges;


void mx_error_check(int argc, char *argv[]);
void mx_error_1(int argc);
void mx_error_2(char *filename);
void mx_error_3(char *filename);
void mx_error_4(char *filename);
void mx_error_5(char *filename);
void mx_error_6(char *filename);
void mx_error_7(char *filename);
void mx_error_8(char *filename);
int mx_count_character(char *str, char character);
char *mx_read_one_line(int file);
void mx_del_not_alphabet(char *string);
int mx_atoi(const char *str);
void mx_del_all_numbers_and_com(char *string);
void mx_numbers_only(char *string);
double mx_add_all_from_array(char **array, int len);
int mx_the_biggest_name(char **array, int len);
bridges **mx_struct_init(char *filename);
char *mx_del_dub(char *string);
int mx_get_distance(char *string);
char **mx_append_city_to_arr(char *string);
void mx_floydWarshall(bridges **big_array, int number_of_points);

#endif