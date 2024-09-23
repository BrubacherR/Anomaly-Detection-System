// Data_Array.h
// Header file for managing the main data array used in the Local Outlier Factor (LOF) algorithm.
// This file declares the external variables used to store the dataset and its size.
// 
// The LOF algorithm requires an array of data points and the size of that array.
// The data points are stored as 32-bit integers, and the array size is represented
// using the size_t type for compatibility with standard array size handling.
//
// The header ensures that the data array and its size can be accessed across
// multiple source files, making it easier to work with the dataset in various
// parts of the program.

#ifndef DATA_ARRAY_H
#define DATA_ARRAY_H

#include <stddef.h>   // For size_t
#include <stdint.h>   // For int32_t

// External array storing 32-bit integers for the LOF algorithm
extern int32_t data_array[];

// External variable representing the size of the data array
extern size_t data_size;

#endif // DATA_ARRAY_H



