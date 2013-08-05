//
//  sw_opencl.c
//  test_sw
//
//  Created by Laurence Bortfeld on 10.06.13.
//  Copyright (c) 2013 Hochschule fuer Technik und Wirtschaft. All rights reserved.
//
#include "sw_opencl.h"

void compute(int *matrix, int *memory, int dim, int sub,
             int *subIndexes, int subLength,
             sclHard device, sclSoft kernel)
{
  size_t global_size[2];
  size_t local_size[2];

  global_size[0] = subLength; global_size[1] = 1;
  local_size[0] = 1; local_size[1] = 1;

  sclManageArgsLaunchKernel(device, kernel, global_size, local_size,
      "%R, %R, %r, %r, %r",
      dim * dim * sizeof(int), (void *) matrix,
      dim * dim * sizeof(int), (void *) memory,
      sizeof(int), (void *) &dim,
      sizeof(int) * subLength * 2, (void *) subIndexes,
      sizeof(int), (void *) &sub
  );
}


void parallel_sw(const char *s1, const char *s2, int sub,
                 sclHard device, sclSoft kernel)
{
  const int m = ((int) strlen(s2));
  const int n = ((int) strlen(s1));
  int dim = m + 1;
  int *matrix = initMatrix(dim);
  int *memory = initMatrix(dim);

  if (m % sub != 0 && n % sub != 0) return;

  int max = n / sub;
  int slice, j;
  for (slice = 0; slice < 2 * max - 1; ++slice) {
    int z = slice < max ? 0 : slice - max + 1;
    int subLength = getDiagonalLength(slice, z, sub);
    int *subIndexes = malloc(sizeof(int) * 2 * subLength);
    int i = 0;

    for (j = z; j <= slice - z; ++j) {
      // printf("(i: %i, j: %i, l: %i), ", j*sub, (slice - j)*sub,
      //       getDiagonalLength(slice, z, sub));
      subIndexes[2*i+0] = j * sub;
      subIndexes[2*i+1] = (slice  - j) *sub;
      i++;
    }

    compute(matrix, memory, dim, sub, subIndexes, subLength, device, kernel);
    printf("\n");

    free(subIndexes);
  }

  freeMatrix(matrix);
  freeMatrix(memory);
}


int getDiagonalLength(int slice, int z, int sub) {
  int i = z;
  int j = slice - z;

  if (z <= 0)
    return  j + 1;

  return  j - i + 1;
}

