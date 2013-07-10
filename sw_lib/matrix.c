//
//  matrix.c
//  test_sw
//
//  Created by Laurence Bortfeld on 10.06.13.
//  Copyright (c) 2013 Hochschule fuer Technik und Wirtschaft. All rights reserved.
//

#include "matrix.h"

void freeMatrix(int **matrix, int m) {
    for (int i=0; i <=m; i++)
        free(matrix[i]);

    free(matrix);
}

int **initMatrix(int m, int n) {
    m = m + 1;
    n = n + 1;
    
    int **matrix = malloc(sizeof(int*) * m);

    for (int i = 0; i < m; i++) {
        matrix[i] = malloc((n * sizeof(int)));
    }
    
    for (int i=0; i < m; i++)
        for (int j=0; j<n; j++)
            matrix[i][j] = 0;
    
    return matrix;
}

position maximumValue(int **matrix, int m, int n) {
    
    int maxValue = 0;
    position max;
    
    for (int i=0; i<m; i++) {
        for (int j=0; j<n; j++) {
            if (matrix[i][j] > maxValue) {
                maxValue = matrix[i][j];
                max.i = i;
                max.j = j;
            }
        }
    }
    
    return max;
}

void printMatrix(int **matrix, int m, int n) {
    for (int i=0; i<=m; i++) {
        for (int j=0; j<=n; j++) {
            printf("%i ", matrix[i][j]);
        }
        
        printf("\n");
    }
    
    printf("\n");
}
