//
//  main.c
//  test_sw
//
//  Created by Laurence Bortfeld on 06.06.13.
//  Copyright (c) 2013 Hochschule fuer Technik und Wirtschaft. All rights reserved.
//

#include <stdio.h>
#include "sw_single.h"

int main(int argc, const char *argv[])
{
    // char *s1 = "ACACACTA";
    // char *s2 = "AGCACACA";
    
    char *s1 = "AAUGCCAUUGACGG";
    char *s2 = "CAGCCUCGCUUAG";


    int j = (int) strlen(s1);
    int i = (int) strlen(s2);


    int **matrix = initMatrix(i, j);
    sw(s1, s2, matrix);
    freeMatrix(matrix, i);
    
    return 0;
}