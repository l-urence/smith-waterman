#include "matrix.h"

int *initMatrix(int dim) {
  int length = dim * dim;
  int *matrix = malloc(sizeof(int) * length);
  int *ptr;

  for (ptr = matrix; ptr < (matrix + length); ++ptr)
    *ptr = 0;

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
