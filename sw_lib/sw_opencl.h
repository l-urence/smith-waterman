//
//  sw_opencl.h
//  test_sw
//
//  Created by Laurence Bortfeld on 10.06.13.
//  Copyright (c) 2013 Hochschule fuer Technik und Wirtschaft. All rights reserved.
//

#ifndef dna_sw_opencl_h
#define dna_sw_opencl_h

#include "sw_serial.h"
#include "simpleCL.h"
#include <limits.h>

void compute();
void createSubMatrix(int *matrix, int i, int j, int sub, int dim);

#endif
