#ifndef dna_sw_opencl_h
#define dna_sw_opencl_h

#include "sw_serial.h"
#include "simpleCL.h"
#include <limits.h>

// Computes the alingemnts in a openCL device
// Assign a computaion matrix, a memory matrix, the dimension of the matrix,
// the length of the array with the start values fpr the submatrixes the two
// string and the simpleOpenCL hardware and Kernel
void compute(int *matrix, int *memory, int dim, int sub,
             int *subIndexes, int subLength, const char *s1, const char *s2,
             sclHard device, sclSoft kernel);

// Call for parallel computation.
void parallel_sw(const char *s1, const char *s2, int sub,
                 sclHard device, sclSoft kernel, int verbose);

// Comput length of the diagonal.
int getDiagonalLength(int slice, int z, int sub);
#endif
