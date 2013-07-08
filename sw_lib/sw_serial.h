//
//  sw_single.h
//  test_sw
//
//  Created by Laurence Bortfeld on 10.06.13.
//  Copyright (c) 2013 Hochschule fuer Technik und Wirtschaft. All rights reserved.
//

#ifndef dna_sw_serial_h
#define dna_sw_serial_h

#include <stdio.h>
#include "matrix.h"

#define MATCH 2
#define MISS_MATCH -1
#define GAP -1

typedef struct swResult {
    char *resultA;
    char *resultB;
    int length;
} swResult;

enum direction {
    CENTER = 0,
    NORTH = 1,
    NORTH_WEST = 2,
    WEST = 3
};


void sw(char *s1, char *s2);
int match(char ai, char bj);
void findMaximum(int **matrix, int **memory, int i, int j, char a, char b);
swResult *traceback(char *s1, char *s2, int **memory, int **matrix);
void evaluateDiagonal(char *s1, char *s2, int z, int slice, int m, int n, int **matrix, int **memory);
position getNextPosition(int i, int j, int **memory);

#endif
