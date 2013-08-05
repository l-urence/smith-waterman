//
//  sw_single.c
//  test_sw
//
//  Created by Laurence Bortfeld on 10.06.13.
//  Copyright (c) 2013 Hochschule fuer Technik und Wirtschaft. All rights reserved.
//

#include "sw_serial.h"

int match(char ai, char bj) {
    if (ai == bj) {
        return MATCH;
    } else {
        return MISS_MATCH;
    }
}

// Find the maximum value for the current cell looking to the north, west and
// north-west cells of the current cell.
void findMaximum(int *matrix, int *memory, int i, int j, char a, char b, int dim) {
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


void validateSubMatrix(int *matrix, int *memory, int i, int j, const char *s1,
                       const char *s2, int sub, int dim) {
    int ii, jj;
    for (ii = i; ii < sub + i; ++ii) {
        for (jj = j; jj < sub + j; ++jj)
            findMaximum(matrix, memory, ii+1, jj+1, s1[jj], s2[ii], dim);
    }
}


void sw(const char *s1, const char *s2, const int sub) {
    const int m = ((int) strlen(s2));
    const int n = ((int) strlen(s1));
    int *matrix = initMatrix(m);
    int *memory = initMatrix(m);
    int dim = m + 1;

    if (m % sub != 0 && n % sub != 0) return;

    int max = n / sub;

    int slice, j;
    for (slice = 0; slice < 2 * max - 1; ++slice) {
    	int z = slice < max ? 0 : slice - max + 1;
        for (j = z; j <= slice - z; ++j) {
            validateSubMatrix(matrix, memory, j*sub, (slice - j)*sub, s1, s2, sub, dim);
            //createSubMatrix(matrix, j*sub, (slice - j)*sub, sub, dim);
        }
    }

    swResult *result = traceback(s1, s2, memory, matrix);

    int i;
    for (i=result->length-1; i>=0; i--) {
        printf("%c", result->resultB[i]);
    }

    printf("\n");

    for (i=result->length-1; i>=0; i--) {
        printf("%c", result->resultA[i]);
    }

    printf("\n");

    free(result->resultA);
    free(result->resultB);
    free(result);
    freeMatrix(memory);
    freeMatrix(matrix);
}

int getDiagonalLength(int slice, int z, int dim) {
    int i = z;
    int j = slice - z;

    if (slice <= dim-1) {
        return  j + 1;
    }

    return  j - i + 1;
}

swResult *traceback(const char *s1, const char *s2, int *memory, int *matrix) {
    const int dim = ((int) strlen(s2)) + 1;
    char stringA[(dim-1)*2], stringB[(dim-1)*2];
    position currentPos = maximumValue(matrix, dim);
    position nextPos = getNextPosition(currentPos.i, currentPos.j, dim, memory);
    int length = 0;

    while ((currentPos.i != nextPos.i || currentPos.j != nextPos.j) &&
           nextPos.i >= 0 && nextPos.j >= 0) {

        if (nextPos.i == currentPos.i) {
            stringA[length] = '-';
        } else {
            stringA[length] = s2[currentPos.i - 1];
        }

        if (nextPos.j == currentPos.j) {
            stringB[length] = '-';
        } else {
            stringB[length] = s1[currentPos.j  - 1];
        }

        currentPos = nextPos;

        if (currentPos.i > 0 && currentPos.j > 0) {
            nextPos = getNextPosition(currentPos.i, currentPos.j, dim, memory);
        }

        length++;
    }

    // copy results and return them.
    swResult *result = malloc(sizeof(swResult));
    result->resultA = malloc(sizeof(char) * length);
    result->resultB = malloc(sizeof(char) * length);
    strcpy(result->resultA, stringA);
    strcpy(result->resultB, stringB);
    result->length = length;

    return result;
}

position getNextPosition(int i, int j, int dim, int *memory) {
    const int direction = memory[j+i*dim];

    if (direction == NORTH_WEST) {
        return (position) {i-1, j-1};
    }

    if (direction == NORTH) {
        return (position) {i-1, j};
    }

    if (direction == WEST) {
        return (position) {i, j-1};
    }

    if (direction == CENTER) {
        return (position) {i, j};
    }

    return (position) {-1, -1};
}
