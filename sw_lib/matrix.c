//
//  matrix.c
//  test_sw
//
//  Created by Laurence Bortfeld on 10.06.13.
//  Copyright (c) 2013 Hochschule fuer Technik und Wirtschaft. All rights reserved.
//

#include "matrix.h"

void freeMatrix(int **matrix, int n) {
    for (int i=0; i<n; i++) {
        free(matrix[i]);
    }
    
    free(matrix);
}


void freeMemory(position **memory, int n) {
    for(int i=0; i<n; i++) {
        free(memory[i]);
    }
    
    free(memory);
}

int **initMatrix(int m, int n) {
    int** matrix;
    
    matrix = (int**)malloc(m * sizeof(int*));
    for (int i = 0; i <=m; i++) {
        matrix[i] = (int*) malloc(n * sizeof(int));
    }
    
    for (int i=0; i <=m; i++) {
        for (int j=0; j < n; j++) {
            matrix[i][j] = 0;
        }
    }
    
    return matrix;
}

position* maximumValue(int **matrix, int m, int n) {
    
    int maxValue = 0;
    position *max = (position *) malloc(sizeof(position));
    
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            if (matrix[i][j] > maxValue) {
                maxValue = matrix[i][j];
                max->i = i;
                max->j = j;
            }
        }
    }
    
    return max;
}