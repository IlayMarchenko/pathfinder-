#include "../inc/pathfinder.h"

double mx_add_all_from_array(char **array, int len) {
    double result = 0;
    for (int i = 0; i < len; i++) {
        result += (double)mx_atoi(array[i]);
    }
    return result;
}