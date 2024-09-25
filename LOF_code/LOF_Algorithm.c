#include <stddef.h>   // For size_t
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>

#include "LOF_Algorithm.h"


// Function to perform insertion sort on 'distances' array while also sorting the 'indices' array accordingly.
// Insertion sort is used because array in findKNeighbours will be mostly sorted
static int insertionSortWithIndex(int *distances, int k, int *indices) {
    for (int i = 1; i < k; i++) {
        int key_distance = distances[i];
        int key_index = indices[i];
        int j = i - 1;

        while (j >= 0 && distances[j] > key_distance) {
            distances[j + 1] = distances[j];
            indices[j + 1] = indices[j];
            j--;
        }

        distances[j + 1] = key_distance;
        indices[j + 1] = key_index;
    }

    return 0;
}

// Finds closest k neighbours to point in dataset
// index is passed as an argument so that function works on values inside dataset and new values
static int* findKNeighbours(int data[], size_t size, size_t k, int point, int index) {
    int *k_neighbours_distance = (int *)malloc(k * sizeof(int));
    int *k_neighbours_index = (int *)malloc(k * sizeof(int));

    for (size_t i = 0; i < k; i++) {
        k_neighbours_distance[i] = INT_MAX; // INT_MAX is used so that any value of distance will be lower
    }

    memset(k_neighbours_index, 0, k * sizeof(int));

    for (int i = 0; i < size; i++) {
        if (index == i) {
            continue;
        }

        int current_distance = abs(data[i] - point);

        if (current_distance < k_neighbours_distance[k - 1]) {
            k_neighbours_distance[k - 1] = current_distance;
            k_neighbours_index[k - 1] = i;
            insertionSortWithIndex(k_neighbours_distance, k, k_neighbours_index);
        }
    }

    free(k_neighbours_distance);
    return k_neighbours_index;
}

// Calculates reach distance between two points
static int reach_distance(int data[], size_t size, size_t k, int point1, int point2_index) {
    int distance = abs(point1 - data[point2_index]);
    int max = 0;
    int *k_neighbours_index = findKNeighbours(data, size, k, data[point2_index], point2_index);

    for (int i = 0; i < k; i++) {
        int neighbor_distance = abs(data[k_neighbours_index[i]] - data[point2_index]);
        if (neighbor_distance > max) {
            max = neighbor_distance;
        }
    }

    return (distance > max) ? distance : max;
}


// Calculates local reachability density of a point
// index is passed as an argument so that function can be used on values inside dataset
static float localReachabilityDensity(int data[], size_t size, size_t k, int point, int index) {
    int sum = 0;
    int *k_neighbours_index = findKNeighbours(data, size, k, point, index);

    for (int i = 0; i < k; i++) {
        int distance = reach_distance(data, size, k, point, k_neighbours_index[i]);
        sum += distance;
    }

    free(k_neighbours_index);

    if (sum == 0) {
        return -1;
    }

    return (float)k / sum;
}

// Combines previous functions to calculate the local outlier factor
float calculate_LOF(int data[], size_t size, size_t k, int point) {
    if (k > size) {
        k = size;
    }

    float sum = 0;
    int *k_neighbours_index = findKNeighbours(data, size, k, point, size + 1);

    for (int i = 0; i < k; i++) {
        float local_density = localReachabilityDensity(data, size, k, data[k_neighbours_index[i]], k_neighbours_index[i]);
        sum += local_density;
    }

    free(k_neighbours_index);

    float local_density = localReachabilityDensity(data, size, k, point, size + 1);

    if (local_density == 0) {
        return -1; 
    }

    return sum / (k * local_density);
}
