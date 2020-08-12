#include "pathfinder.h"

void mx_error_2(char *filename) {
    int result = open(filename, O_RDONLY);
    if (result < 0) {
        mx_printerr("error: file ");
        mx_printerr(filename);
        mx_printerr(" does not exist");
        exit(1);
    }
    close(result);
}
