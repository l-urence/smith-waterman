//
//  sw_opencl.c
//  test_sw
//
//  Created by Laurence Bortfeld on 10.06.13.
//  Copyright (c) 2013 Hochschule fuer Technik und Wirtschaft. All rights reserved.
//
#include "sw_opencl.h"

void compute()
{
    int devices = 0;
    int dataLength = 1024;
    sclHard gpu = sclGetGPUHardware(0, &devices);
    sclSoft kernel = sclGetCLSoftware("kernel.cl", "sw", gpu);

    size_t global_size[2];
    size_t local_size[2];

    global_size[0] = dataLength; global_size[1] = 1;
    local_size[0] = 1; local_size[1] = 1;

    int vector[dataLength];

    sclManageArgsLaunchKernel(gpu, kernel, global_size, local_size,
                               "%R",
                               (sizeof(int)*dataLength), (void *) vector);

    int i = 0;
    for (i=0; i<dataLength; i++)
        printf("%i, ", vector[i]);

    printf("\n");
}


void createSubMatrix(int *matrix, int i, int j, int sub, int dim)
{
    int ii, jj;
    for (ii = i; ii <= sub + i; ++ii) {
        for (jj = j; jj <= sub + j; ++jj)
            printf("(%i, %i) ", ii, jj);

        printf("\n");
    }

    printf("\n");
}

