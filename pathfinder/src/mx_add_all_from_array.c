#include "pathfinder.h"

double mx_add_all_from_array(char **array, int len) {
    double result = 0;
    for (int i = 0; i < len; i++) {
        if (mx_strlen(array[i]) > 10) {
            mx_printerr("error: sum of bridges lengths is too big");
            exit(1);
        }
        else if (mx_atoi(array[i]) < 0) {
            mx_printerr("error: sum of bridges lengths is too big");
            exit(1);
        }
        result += (double)mx_atoi(array[i]);
    }
    return result;
}
