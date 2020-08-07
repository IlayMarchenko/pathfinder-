#include "../inc/pathfinder.h"

static int get_number_of_bridges(char *filename);


int main(int argc, char *argv[]) {
    mx_error_check(argc, argv);
    bridges **big_array = mx_struct_init(argv[1]);
    int number_of_points = get_number_of_bridges(argv[1]);
    mx_floydWarshall(big_array, number_of_points);
    system("leaks -q pathfinder_clion");

    // print matrix of path
    for (int i = 0; i < (int)mx_pow(number_of_points, 2); ++i) {
        for (int j = 0; j < 2; ++j) {
            printf("%s", big_array[i]->path[j]);
        }
        printf("\t\t\t");
        if (i == 4 || i == 9 || i == 14 || i == 19)
            printf("\n");
    }

    printf("\n\n");

    // print matrix of distance
    for (int i = 0; i < (int)mx_pow(number_of_points, 2); ++i) {
        if (big_array[i]->distance != INF)
            printf("%ld", big_array[i]->distance);
        else
            printf("inf");

        printf("\t\t\t");
        if (i == 4 || i == 9 || i == 14 || i == 19)
            printf("\n");
    }

    return 0;
}

static int get_number_of_bridges(char *filename) {
    int file = open(filename, O_RDONLY);
    char *line = mx_read_one_line(file);
    int res = mx_atoi(line);
    mx_strdel(&line);
    return res;
}


