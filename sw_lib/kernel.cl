////////////////////////////////////////////////////////////////////////////////
// Simple OpenCL kernel that squares an input array.
// This code is stored in a file called mykernel.cl.

kernel void square(global float* input, global float* output)
{
    size_t i = get_global_id(0);

    
    output[i] = input[i] * input[i] ;
}