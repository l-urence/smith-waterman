enum direction {
    CENTER, NORTH, NORTH_WEST, WEST
};

// Find the maximum value for the current cell looking to the north, west and
// north-west cells of the current cell.
void findMaximum(int *matrix, int *memory, int i, int j, char a, char b, int dim);

// Check if a character a is equal to a character b.
int match(char ai, char bj);

// Smith Waterman openCL kernel funktion.
__kernel void sw (
    //__global int *matrix,
    //__global int *memory,
    __global int *indexes
    //__global char *s1,
    //__global char *s2
    //__global int dim,
    //__global ind sub
)
{
    // int x = get_global_id(0);
    *indexes = 10;
    //int i = indexes[0+x*2];
    //int j = indexes[1+x*2];

    /*for (ii = i; ii < sub + i; ++ii) {
        for (jj = j; jj < sub + j; ++jj)
            findMaximum(matrix, memory, ii+1, jj+1, s1[jj], s2[ii], dim);
    }*/
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


