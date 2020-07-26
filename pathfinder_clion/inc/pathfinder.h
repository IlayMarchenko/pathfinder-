#ifndef PATHFINDER_H
#define PATHFINDER_H


#include "../libmx/inc/libmx.h"

void mx_error_check(int argc, char *argv[]);
void mx_error_1(int argc);
void mx_error_2(char *filename);
void mx_error_3(char *filename);
void mx_error_4(char *filename);
void mx_error_5(char *filename);
void mx_error_6(char *filename);
int mx_count_character(char *str, char character);
char *mx_read_one_line(int file);
void mx_del_not_alphabet(char *string);
int mx_atoi(const char *str);


#endif