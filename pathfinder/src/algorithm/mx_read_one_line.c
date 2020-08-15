#include "pathfinder.h"

char *mx_read_one_line(int file) {
    char buff;
    char *string = mx_strnew(200);
    int length = 0;
    while (true) {
        if (read(file, &buff, 1)) {
            if (buff == '\n') {
                break;
            } else {
                *string = buff;
                string++;
                length++;
            }
        } else {
            string -= length;
            mx_strdel(&string);
            return NULL;
        }
    }
    if (length == 0) {
        string = mx_realloc(string, 1);
    } else {
        string -= length;
        string = mx_realloc(string, length);
    }
    return string;
}

