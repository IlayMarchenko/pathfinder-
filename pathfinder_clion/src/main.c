#include "../inc/pathfinder.h"

static int get_number_of_bridges(char *filename);


int main(int argc, char *argv[]) {
    mx_error_check(argc, argv);
    t_main stct;
    bridges **big_array = mx_struct_init(argv[1], &stct);
    int number_of_points = get_number_of_bridges(argv[1]);
    mx_floydWarshall(big_array, number_of_points, &stct);
    for (int i = 0; i < stct.count; i++) {
        for (int j = 0; j < stct.count; j++) {
            if (i < j)
                mx_find_all_paths(&stct, i, j);
        }
    }
    printf("\n\n");
    system("leaks -q pathfinder_clion");
    return 0;
}

static int get_number_of_bridges(char *filename) {
    int file = open(filename, O_RDONLY);
    char *line = mx_read_one_line(file);
    int res = mx_atoi(line);
    mx_strdel(&line);
    return res;
}


