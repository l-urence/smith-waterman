//
//  matrix.h
//  test_sw
//
//  Created by Laurence Bortfeld on 10.06.13.
//  Copyright (c) 2013 Hochschule fuer Technik und Wirtschaft. All rights reserved.
//

#ifndef test_sw_matrix_h
#define test_sw_matrix_h

#include <string.h>
#include <stdlib.h>

typedef struct position
{
    int i;
    int j;
} position;


int **initMatrix(int m, int n);
void freeMatrix(int **matrix, int n);
void freeMemory(position **memory, int n);
position* maximumValue(int **matrix, int m, int n);


#endif
