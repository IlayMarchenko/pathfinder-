#include "../inc/pathfinder.h"

static void algorithm(long **array, int number_of_points);
static void transfer_data(bridges **big_array, long **array, int number_of_points, int c);
static void add_to_main_struct0(long **array, t_main *stct, int number_of_points);
static void add_to_main_struct1(long **array, t_main *stct, int number_of_points);

void mx_floydWarshall(bridges **big_array, int number_of_points, t_main *stct) {
    long **array = (long **)malloc(sizeof(long *) * (int)mx_pow(number_of_points, 2));
    for (int k = 0; k < number_of_points; ++k) {
        array[k] = (long *)malloc(sizeof(long) * number_of_points);
    }
    transfer_data(big_array, array, number_of_points, 0);
    add_to_main_struct0(array, stct, number_of_points);
    algorithm(array, number_of_points);
    transfer_data(big_array, array, number_of_points, 1);
    add_to_main_struct1(array, stct, number_of_points);
    for (int l = 0; l < number_of_points; ++l) {
        free(array[l]);
    }
    free(array);
}

static void algorithm(long **array, int number_of_points) {
    // floyd-warshall algorithm
    for (int k = 0; k < number_of_points; k++) {
        for (int i = 0; i < number_of_points; i++) {
            for (int j = 0; j < number_of_points; j++) {
                if (array[i][k] + array[k][j] < array[i][j])
                    array[i][j] = array[i][k] + array[k][j];
            }
        }
    }
}

static void transfer_data(bridges **big_array, long **array, int number_of_points, int c) {
    int n = 0;
    if (c == 0) {
        for (int i = 0; i < number_of_points; i++) {
            for (int j = 0; j < number_of_points; j++) {
                array[i][j] = big_array[n]->distance;
                n++;
            }
        }
    }
    else {
        for (int i = 0; i < number_of_points; i++) {
            for (int j = 0; j < number_of_points; j++) {
                big_array[n]->distance = array[i][j];
                n++;
            }
        }
    }
}

static void add_to_main_struct0(long **array, t_main *stct, int number_of_points) {
    stct->m_floyd = (long **)malloc(sizeof(long *) * (int)mx_pow(number_of_points, 2));
    for (int k = 0; k < number_of_points; ++k) {
        stct->m_floyd[k] = (long *)malloc(sizeof(long) * number_of_points);
    }
    for (int i = 0; i < number_of_points; i++) {
        for (int j = 0; j < number_of_points; j++) {
            stct->m_floyd[i][j] = array[i][j];
        }
    }
}

static void add_to_main_struct1(long **array, t_main *stct, int number_of_points) {
    stct->m_dist = (long **)malloc(sizeof(long *) * (int)mx_pow(number_of_points, 2));
    for (int k = 0; k < number_of_points; ++k) {
        stct->m_dist[k] = (long *)malloc(sizeof(long) * number_of_points);
    }
    for (int i = 0; i < number_of_points; i++) {
        for (int j = 0; j < number_of_points; j++) {
            stct->m_dist[i][j] = array[i][j];
        }
    }
}
