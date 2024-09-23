#include <stddef.h>   // For size_t
#include <stdint.h>   // For int32_t
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

#include "LOF_Algorithm.h"

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        // Move elements of arr[0..i-1] that are greater than key
        // to one position ahead of their current position
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

static int32_t max_reach_distance(int32_t data[], size_t size, size_t k, int32_t point1, int32_t point2_index){
    int distance = abs(point1 - data[point2_index]);

    int k_neighbours_distance[k];
    int max = INT_MAX;

    for (int i = 0; i < k; i++){
        k_neighbours_distance[i] = 0;
    }

    for (int i = 0; i < size; i++){
        if(i == point2_index){
            continue;
        }
        if (abs(data[i] - data[point2_index]) < max){
            k_neighbours_distance[k-1] = abs(data[i] - data[point2_index]);
            insertionSort(k_neighbours_distance, k);
            max = k_neighbours_distance[k-1];
        } 
    }
    return (distance > max) ? distance : max;
}

int32_t calculate_LOF(int data[], size_t size, size_t k){
    
}