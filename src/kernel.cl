enum direction {
  CENTER, NORTH, NORTH_WEST, WEST
};

// Check if a character a is equal to a character b.
int match(char ai, char bj);

// Smith Waterman openCL kernel funktion.
__kernel void sw (
  __global int *matrix,
  __global int *memory,
  __global int *tmpdim,
  __global int *subIndexes,
  __global int *sub,
  __global char *s1,
  __global char *s2)
{
  int x = get_global_id(0);
  int dim = *tmpdim;
  int startI = subIndexes[2*x+0];
  int startJ = subIndexes[2*x+1];

  int ii, jj;
  const int GAP = -1;
  for (ii = startI; ii < *sub + startI; ++ii)
  {
    int i = ii + 1;
    for (jj = startJ; jj < *sub + startJ; ++jj)
    {
      int j = jj + 1;
      int max = 0;
      int index = j+i*dim;

      int nw = matrix[(j-1)+(i-1)*dim] + match(s1[jj], s2[ii]);
      if (nw > max)
      {
        max = nw;
        memory[index] = NORTH_WEST;
      }

      int n = matrix[j+(i-1)*dim] + GAP;
      if (n > max)
      {
        max = n;
        memory[index] = NORTH;
      }

      int w = matrix[(j-1)+i*dim] + GAP;
      if (w > max)
      {
        max = w;
        memory[index] = WEST;
      }

      if (max == 0)
        memory[index] = CENTER;

      matrix[index] = max;
    }
  }
}


int match(char ai, char bj) {
  const int MATCH = 2;
  const int MISS_MATCH = -1;
  if (ai == bj)
    return MATCH;
  else
    return MISS_MATCH;
}

