#include "../inc/pathfinder.h"

void mx_floydWarshall(bridges **big_array, int number_of_points) {
    int n = 0;
    long array[number_of_points][number_of_points];
    char parents[number_of_points][200];
    // transfer data from struct to 2d array
    for (int i = 0; i < number_of_points; i++) {
        for (int j = 0; j < number_of_points; j++) {
            array[i][j] = big_array[n]->distance;
            n++;
        }
    }
    // floyd-warshall algorithm
    for (int k = 0; k < number_of_points; k++) {
        for (int i = 0; i < number_of_points; i++) {
            for (int j = 0; j < number_of_points; j++) {
                if (array[i][k] + array[k][j] < array[i][j])
                    array[i][j] = array[i][k] + array[k][j];
            }
        }
    }
    // transfer data from 2d array to struct
    n = 0;
    for (int i = 0; i < number_of_points; i++) {
        for (int j = 0; j < number_of_points; j++) {
            big_array[n]->distance = array[i][j];
            n++;
        }
    }
}
