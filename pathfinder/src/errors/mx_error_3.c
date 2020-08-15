#include "pathfinder.h"

void mx_error_3(char *filename) {
    char *result = NULL;
    result = mx_file_to_str(filename);
    if (result == NULL) {
        mx_strdel(&result);
        mx_printerr("error: file ");
        mx_printerr(filename);
        mx_printerr(" is empty\n");
        exit(1);
    }
    mx_strdel(&result);
}
