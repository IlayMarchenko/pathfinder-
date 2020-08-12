#include "pathfinder.h"

int mx_count_character(char *str, char character) {
    char *str2 = str;
    int result = 0;
    while (*str2) {
        if (*str2 == character)
            result++;
        str2++;
    }
    return result;
}

