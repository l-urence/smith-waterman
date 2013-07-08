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
void findMaximum(int **matrix, int **memory, int i, int j, char a, char b) {
    int max = 0;
    
    int mm = matrix[i-1][j-1] + match(a, b);
    if (mm > max) {
        max = mm;
        memory[i][j] = NORTH_WEST;
        // memory[i][j] = (position) {i - 1, j - 1};
    }
    
    int md = matrix[i-1][j] + GAP;
    if (md > max) {
        max = md;
        memory[i][j] = NORTH;
        // memory[i][j] = (position) {i - 1, j};
    }
    
    int mi = matrix[i][j-1] + GAP;
    if (mi > max) {
        max = mi;
        memory[i][j] = WEST;
        // memory[i][j] = (position) {i, j - 1};
    }
    
    if (max == 0) {
        memory[i][j] = CENTER;
        // memory[i][j] = (position) {i, j};
    }
    
    matrix[i][j] = max;
}

void sw(char *s1, char *s2) {
    int m = ((int) strlen(s2));
    int n = ((int) strlen(s1));
    int max = m > n ? n : m;
    int **matrix = initMatrix(m, n);
    int **memory = initMatrix(m, n);
    
    for (int slice = 0; slice < 2 * max; ++slice) {
    	int z = slice <= max? 0 : slice - max + 1;
    	evaluateDiagonal(s1, s2, z, slice, m, n, matrix, memory);
    }
    printMatrix(matrix, m, n);
    
    // Traceback
    swResult *result = traceback(s1, s2, memory, matrix);
    
    for (int i=result->length-1; i>=0; i--) {
        printf("%c", result->resultB[i]);
    }
    
    printf("\n");
    
    for (int i=result->length-1; i>=0; i--) {
        printf("%c", result->resultA[i]);
    }
    
    printf("\n");
    
    free(result->resultA);
    free(result->resultB);
    free(result);
    freeMatrix(memory, m);
    freeMatrix(matrix, n);
}

void evaluateDiagonal(char *s1, char *s2, int z, int slice, int m, int n, int **matrix, int **memory) {
    for (int j = z; j <= slice - z; ++j) {
        int ii = j + 1;
        int jj = slice - j + 1;
        if (ii <= m && jj <= n) {
            findMaximum(matrix, memory, ii, jj, s2[ii - 1], s1[jj - 1]);
        }
    }
}

swResult *traceback(char *s1, char *s2, int **memory, int **matrix) {
    const int m = ((int) strlen(s2)) + 1;
    const int n = ((int) strlen(s1)) + 1;
    char stringA[m + n + 2], stringB[m + n + 2];
    position currentPos = maximumValue(matrix, m, n);
    position nextPos = getNextPosition(currentPos.i, currentPos.j, memory);
    
    /*int length = 0;
    
    while ((currentPos->i != nextPos.i || currentPos->j != nextPos.j) &&
           nextPos.i >= 0 && nextPos.j >= 0) {
        
        if (nextPos.i == currentPos->i) {
            stringA[length] = '-';
        } else {
            stringA[length] = s2[currentPos->i - 1];
        }
        
        if (nextPos.j == currentPos->j) {
            stringB[length] = '-';
        } else {
            stringB[length] = s1[currentPos->j  - 1];
        }
        
        *currentPos = nextPos;
        
        if (currentPos->i > 0 && currentPos > 0)
            nextPos = memory[currentPos->i][currentPos->j];
        
        length++;
    }
    
    free(currentPos);

    // copy results and return them.
    swResult *result = malloc(sizeof(swResult));
    result->resultA = malloc(sizeof(char) * length);
    result->resultB = malloc(sizeof(char) * length);
    strcpy(result->resultA, stringA);
    strcpy(result->resultB, stringB);
    result->length = length;*/
    
    return NULL;//result;
}

position getNextPosition(int i, int j, int **memory) {
    const int direction = memory[i][j];

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
