#ifndef dna_sw_matrix_h
#define dna_sw_matrix_h

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

// Structure ti store the position in a matrix
typedef struct position
{
    int i;
    int j;
} position;

// Inits a matrix with memory and zeros.
int *initMatrix(int dim);

// Finds the maximum value in a matrix.
position maximumValue(int *matrix, int dim);

// Prints out a matrix.
void printMatrix(int *matrix, int dim);


#endif
