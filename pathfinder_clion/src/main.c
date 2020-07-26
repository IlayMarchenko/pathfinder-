#include "../inc/pathfinder.h"

int main(int argc, char *argv[]) {
    mx_error_check(argc, argv);
    system("leaks -q pathfinder_clion");
    return 0;
}

