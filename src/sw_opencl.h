#ifndef dna_sw_opencl_h
#define dna_sw_opencl_h

#include "sw_serial.h"
#include "simpleCL.h"
#include <limits.h>

//
void compute(int *matrix, int *memory, int dim, int sub,
             int *subIndexes, int subLength, const char *s1, const char *s2,
             sclHard device, sclSoft kernel);

//
void parallel_sw(const char *s1, const char *s2, int sub,
                 sclHard device, sclSoft kernel);


#endif
