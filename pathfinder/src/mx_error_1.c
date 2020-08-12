#include "pathfinder.h"

void mx_error_1(int argc) {
    if (argc != 2) {
        mx_printerr("usage: ./pathfinder [filename]");
        exit(1);
    }
}

