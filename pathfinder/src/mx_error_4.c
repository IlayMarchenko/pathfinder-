#include "pathfinder.h"
static void error() {
    mx_printerr("error: line 1 is not valid");
    exit(1);
}
void mx_error_4(char *filename) {
    int file = open(filename, O_RDONLY);
    char *result = mx_strnew(20);
    int count = 0;
    result = mx_read_one_line(file);
    int len = mx_strlen(result);
    if (len == 0){
        mx_strdel(&result);
        error();
    }
    while (*result) {
        if (!mx_is_number(*result)) {
            result -= count;
            mx_strdel(&result);
            error();
        }
        result++;
        count++;
    }
    result -= count;
    mx_strdel(&result);
    close(file);
}
