//
//  matrix.h
//  test_sw
//
//  Created by Laurence Bortfeld on 10.06.13.
//  Copyright (c) 2013 Hochschule fuer Technik und Wirtschaft. All rights reserved.
//

#ifndef dna_sw_matrix_h
#define dna_sw_matrix_h

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct position
{
    int i;
    int j;
} position;


int **initMatrix(int m, int n);
void freeMatrix(int **matrix, int n);
position maximumValue(int **matrix, int m, int n);
void copyMatrix(int **source, int **target, int i, int j, int max);
void mergeMatrix(int **source, int **target, int i, int j, int max);
void printMatrix(int **matrix, int m, int n);


#endif
