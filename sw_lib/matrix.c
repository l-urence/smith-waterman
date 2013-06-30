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

void freeMemory(position **memory, int m) {
    for (int i=0; i<=m; i++)
        free(memory[i]);
    
    free(memory);
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

position **initMemory(int m, int n) {
    m = m + 1;
    n = n + 1;
    
    position **memory = malloc(sizeof(position*) * m);
    
    int i, j;
    for (i=0; i<m; i++)
        memory[i] = malloc(sizeof(position) * n);
        
    for (i=0; i<m; i++)
        for (j=0; j<m; j++)
            memory[i][j] = (position) {0, 0};
            
    return memory;

}

position* maximumValue(int **matrix, int m, int n) {
    
    int maxValue = 0;
    position *max = (position *) malloc(sizeof(position));
    
    for (int i=0; i<m; i++) {
        for (int j=0; j<n; j++) {
            if (matrix[i][j] > maxValue) {
                maxValue = matrix[i][j];
                max->i = i;
                max->j = j;
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
}
