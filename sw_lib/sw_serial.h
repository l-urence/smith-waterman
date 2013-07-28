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
#include <math.h>
#include "sw_opencl.h"

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


void sw(const char *s1, const char *s2, int sub);
int match(char ai, char bj);
void findMaximum(int *matrix, int *memory, int i, int j, char a, char b, int dim);
swResult *traceback(const char *s1, const char *s2, int *memory, int *matrix);
int getDiagonalLength(int slice, int z, int dim);
position getNextPosition(int i, int j, int dim, int *memory);

#endif
