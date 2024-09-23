// LOF_Algorithm.h
// Header file for the Local Outlier Factor (LOF) algorithm implementation.
// This file declares the function used to calculate the Local Outlier Factor
// for a given dataset.
//
// The LOF algorithm is used to detect anomalies in datasets by calculating the 
// density of a data point compared to its neighbors. The function below 
// computes the LOF score for the input data.
//
// The header includes necessary types such as int32_t for 32-bit integers 
// and size_t for size specifications.

#ifdef LOF_ALGORITHM_H
#define LOF_ALGORITHM_H

#include <stdint.h>   // For int32_t
#include <stddef.h>   // For size_t

// Function to calculate the Local Outlier Factor (LOF)
// Parameters:
// - data[]: Array of data points
// - size: Number of data points in the array
// - k: Number of neighbors to consider for LOF calculation
// Returns the calculated LOF score as an int32_t
int32_t calculate_LOF(int data[], size_t size, size_t k);

#endif // LOF_ALGORITHM_H