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

#ifdef __APPLE__
#include "OpenCL/opencl.h"
#include "kernel.cl.h"
#else
#include "CL/cl.h"
#endif

#define NUM_VALUES 3

void compute(int ***matrix, int ***mem, int length, int dim);


#endif