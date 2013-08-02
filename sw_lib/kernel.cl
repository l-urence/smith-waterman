__kernel void test(__global int *number, __global int *result)
{
    printf("%i", get_local_id(0));
}
