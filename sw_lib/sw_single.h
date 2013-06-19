//
//  sw_single.h
//  test_sw
//
//  Created by Laurence Bortfeld on 10.06.13.
//  Copyright (c) 2013 Hochschule fuer Technik und Wirtschaft. All rights reserved.
//

#ifndef test_sw_sw_single_h
#define test_sw_sw_single_h

#include <stdio.h>
#include "matrix.h"

#define MATCH 2
#define MISS_MATCH -1
#define GAP -1

void sw(char *s1, char *s2, int **matrix);
int match(char ai, char bj);
void findMaximum(int **matrix, position **memory, int i, int j, char a, char b);

#endif
