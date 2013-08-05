//
//  matrix.c
//  test_sw
//
//  Created by Laurence Bortfeld on 10.06.13.
//  Copyright (c) 2013 Hochschule fuer Technik und Wirtschaft. All rights reserved.
//

#include "matrix.h"

void freeMatrix(int *matrix) {
  free(matrix);
}

int *initMatrix(int dim) {
  dim = dim + 1;

  int *matrix = malloc(sizeof(int) * dim * dim);

  int i, j;
  for (i=0; i <= dim; i++)
    for (j=0; j <= dim; j++)
      matrix[j+i*dim] = 0;

  return matrix;
}

position maximumValue(int *matrix, int dim) {
  int maxValue = 0;
  position max;

  int i, j;
  for (i=0; i<dim; i++) {
    for (j=0; j<dim; j++) {
      if (matrix[j+i*dim] > maxValue) {
        maxValue = matrix[j+i*dim];
        max.i = i;
        max.j = j;
      }
    }
  }

  return max;
}

void printMatrix(int *matrix, int dim) {
  int i, j;
  for (i=0; i<dim; i++) {
    for (j=0; j<dim; j++) {
      printf("%i ", matrix[j+i*dim]);
    }

    printf("\n");
  }

  printf("\n");
}
