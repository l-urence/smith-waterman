enum direction {
    CENTER, NORTH, NORTH_WEST, WEST
};

// Find the maximum value for the current cell looking to the north, west and
// north-west cells of the current cell.
void findMaximum(int *matrix, int *memory, int i, int j, char a, char b, int dim);

// Check if a character a is equal to a character b.
int match(char ai, char bj);

// Print out matrix
void printMatrix(int *matrix, int dim);

// Smith Waterman openCL kernel funktion.
__kernel void sw (
    __global int *matrix,
    __global int *memory,
    __global int *dim,
    __global int *subIndexes,
    __global int *sub
)
{
  int x = get_global_id(0);
  int i = subIndexes[2*x+0];
  int j = subIndexes[2*x+1];

  int ii, jj;
  for (ii = i; ii < *sub + i; ++ii)
  {
    for (jj = j; jj < *sub + j; ++jj)
    {
      int i2 = ii + 1;
      int j2 = jj + 2;
      printf("%i ", matrix[j2+i2*(*dim)]);
      //printf("i");
      // findMaximum(matrix, memory, ii+1, jj+1, s1[jj], s2[ii], dim);
    }

    printf("\n");
  }
}


int match(char ai, char bj) {
    const int MATCH = 2;
    const int MISS_MATCH = -1;

    if (ai == bj) {
        return MATCH;
    } else {
        return MISS_MATCH;
    }
}


void findMaximum(int *matrix, int *memory, int i, int j, char a, char b, int dim) {
    const int GAP = -1;
    int max = 0;

    int mm = matrix[(j-1)+(i-1)*dim] + match(a, b);
    if (mm > max) {
        max = mm;
        memory[j+i*dim] = NORTH_WEST;
    }

    int md = matrix[j+(i-1)*dim] + GAP;
    if (md > max) {
        max = md;
        memory[j+i*dim] = NORTH;
    }

    int mi = matrix[(j-1)+i*dim] + GAP;
    if (mi > max) {
        max = mi;
        memory[j+i*dim] = WEST;
    }

    if (max == 0) {
        memory[j+i*dim] = CENTER;
    }

    matrix[j+i*dim] = max;
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

