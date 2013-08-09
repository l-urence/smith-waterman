#ifndef dna_sw_matrix_h
#define dna_sw_matrix_h

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

//
typedef struct position
{
    int i;
    int j;
} position;

//
int *initMatrix(int dim);

//
position maximumValue(int *matrix, int dim);

//
void printMatrix(int *matrix, int dim);


#endif
