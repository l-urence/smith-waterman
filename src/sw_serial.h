//
//  sw_single.h
//  test_sw
//
//  Created by Laurence Bortfeld on 10.06.13.
//  Copyright (c) 2013 Hochschule fuer Technik und Wirtschaft. All rights reserved.
//

#ifndef dna_sw_serial_h
#define dna_sw_serial_h

#include "matrix.h"

#define MATCH 2
#define MISS_MATCH -1
#define GAP -1

// Structure to keep the smith walterman results
typedef struct swResult {
  char *resultA;
  char *resultB;
  int length;
} swResult;

// Computation direction in the matrix
enum direction {
  CENTER, NORTH, NORTH_WEST, WEST
};

// Compute the aligment
void sw(const char *s1, const char *s2, int sub, int verbose);

// Chach if a string is equal.
int match(char ai, char bj);

// Performe compare operations on the matrix.
void validateSubMatrix(int *matrix, int *memory, int i, int j, const char *s1,
    const char *s2, int sub, int dim);


void findMaximum(int *matrix, int *memory, int i, int j, char a, char b, int dim);

// Performs the traceback in a scored matrix
swResult *traceback(const char *s1, const char *s2, int *memory, int *matrix);

// Get the nex position in am matrix acording to the memory
position getNextPosition(int i, int j, int dim, int *memory);

// Prints out the alignments.
void printAlignments(swResult *result);

#endif
