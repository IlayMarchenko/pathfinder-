#include "pathfinder.h"

void mx_del_all_numbers_and_com(char *string) {
    int count = 0;
    while (*string != '\0') {
        if (!mx_in_alphabet(*string) && *string != '-') {
            *string = ' ';
        }
        string++;
        count++;
    }
    string -= count;
}
