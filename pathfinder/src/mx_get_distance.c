#include "pathfinder.h"

int mx_get_distance(char *string) {
    int counter = 0;
    int res = 0;
    char *temp_str = mx_strnew(mx_strlen(string));
    temp_str = mx_strcpy(temp_str, string);
    while (!mx_is_number(*temp_str)) {
        temp_str++;
        counter++;
    }
    res = mx_atoi(temp_str);
    temp_str -= counter;
    mx_strdel(&temp_str);
    return res;
}
