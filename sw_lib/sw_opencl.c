//
//  sw_opencl.c
//  test_sw
//
//  Created by Laurence Bortfeld on 10.06.13.
//  Copyright (c) 2013 Hochschule fuer Technik und Wirtschaft. All rights reserved.
//
#include "sw_opencl.h"

static int validate(cl_float* input, cl_float* output) {
    int i;
    for (i = 0; i < NUM_VALUES; i++) {
        
        // The kernel was supposed to square each value.
        if ( output[i] != (input[i] * input[i]) ) {
            fprintf(stdout, "Error: Element %d did not match expected output.\n", i);
            fprintf(stdout, "       Saw %1.4f, expected %1.4f\n", output[i],
                    input[i] * input[i]);
            fflush(stdout);
            return 0;
        }
    }
    return 1;
}

void compute(int ***matrix, int ***mem, int length, int dim) {
    dispatch_queue_t queue = gcl_create_dispatch_queue(CL_DEVICE_TYPE_GPU, NULL);
    
    if (queue == NULL) {
        queue = gcl_create_dispatch_queue(CL_DEVICE_TYPE_CPU, NULL);
    }
    
    char name[128];
    cl_device_id gpu = gcl_get_device_id_with_dispatch_queue(queue);
    clGetDeviceInfo(gpu, CL_DEVICE_NAME, 128, name, NULL);
    fprintf(stdout, "Created a dispatch queue using the %s\n", name);
    
    int i;
    float* test_in = (float*)malloc(sizeof(cl_float) * NUM_VALUES);
    for (i = 0; i < NUM_VALUES; i++) {
        test_in[i] = (cl_float)i;
    }
    
    float* test_out = (float*)malloc(sizeof(cl_float) * NUM_VALUES);
    
    void* mem_in  = gcl_malloc(sizeof(cl_float) * NUM_VALUES, test_in,
                               CL_MEM_READ_ONLY | CL_MEM_COPY_HOST_PTR);
    
    void* mem_out = gcl_malloc(sizeof(cl_float) * NUM_VALUES, NULL,
                               CL_MEM_WRITE_ONLY);
    
    dispatch_sync(queue, ^{
        
        // Though we COULD pass NULL as the workgroup size, which would tell
        // OpenCL to pick the one it thinks is best, we can also ask
        // OpenCL for the suggested size, and pass it ourselves.              [6]
        size_t wgs;
        gcl_get_kernel_block_workgroup_info(square_kernel,
                                            CL_KERNEL_WORK_GROUP_SIZE,
                                            sizeof(wgs), &wgs, NULL);
        
        // The N-Dimensional Range over which we'd like to execute our
        // kernel.  In our example case, we're operating on a 1D buffer, so
        // it makes sense that our range is 1D.
        cl_ndrange range = {
            1,                     // The number of dimensions to use.
            
            {0, 0, 0},             // The offset in each dimension.  We want to
            // process ALL of our data, so this is 0 for
            // our test case.                          [7]
            
            {3, 0, 0},    // The global range -- this is how many items
            // IN TOTAL in each dimension you want to
            // process.
            
            {2, 0, 0} // The local size of each workgroup.  This
            // determines the number of workitems per
            // workgroup.  It indirectly affects the
            // number of workgroups, since the global
            // size / local size yields the number of
            // workgroups.  So in our test case, we will
            // have NUM_VALUE / wgs workgroups.
        };
        // Calling the kernel is easy; you simply call it like a function,
        // passing the ndrange as the first parameter, followed by the expected
        // kernel parameters.  Note that we case the 'void*' here to the
        // expected OpenCL types.  Remember -- if you use 'float' in your
        // kernel, that's a 'cl_float' from the application's perspective.   [8]
        
        square_kernel(&range,(cl_float*)mem_in, (cl_float*)mem_out);
        
        // Getting data out of the device's memory space is also easy; we
        // use gcl_memcpy.  In this case, we take the output computed by the
        // kernel and copy it over to our application's memory space.        [9]
        
        gcl_memcpy(test_out, mem_out, sizeof(cl_float) * NUM_VALUES);
    });
    
    // Now we can check to make sure our kernel really did what we asked
    // it to:
    
    if ( validate(test_in, test_out)) {
        fprintf(stdout, "All values were properly squared.\n");
    }
    
    // Don't forget to free up the CL device's memory when you're done.      [10]
    gcl_free(mem_in);
    gcl_free(mem_out);
    
    // And the same goes for system memory, as usual.
    free(test_in);
    free(test_out);
    
    // Finally, release your queue just as you would any GCD queue.          [11]
    dispatch_release(queue);
}