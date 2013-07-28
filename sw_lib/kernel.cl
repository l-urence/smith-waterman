////////////////////////////////////////////////////////////////////////////////
// Simple OpenCL kernel that squares an input array.
// This code is stored in a file called mykernel.cl.

int match(char ai, char bj) {
    if (ai == bj) {
        return 2;
    } else {
        return -1;
    }
}

kernel void sw(global int *matrix, global int *memory, global int *subMatrix, global int *sub, global char* s1, global char *s2, global int *dim)
{
    size_t index = get_global_id(0);
    
    int i = subMatrix[0+index*2];
    int j = subMatrix[1+index*2];
    
    int ii, jj;
    
    for (i = i; ii < *sub + i; ++ii) {
        for (int jj = j; jj < *sub + j; ++jj) {
            
            int max = 0;
            
            int mm = matrix[(jj-1)+(ii-1)*(*dim)] + match(s1[jj], s2[ii]);
            if (mm > max) {
                max = mm;
                memory[jj+ii*(*dim)] = 2;
            }
            
            int md = matrix[jj+(ii-1)*(*dim)];
            if (md > max) {
                max = md;
                memory[jj+ii*(*dim)] = 1;
            }
            
            int mi = matrix[(jj-1)+ii*(*dim)];
            if (mi > max) {
                max = mi;
                memory[jj+ii*(*dim)] = 3;
            }
            
            if (max == 0) {
                memory[jj+ii*(*dim)] = 0;
            }
            
            matrix[jj+ii* (*dim)] = max;
        }
    }
}