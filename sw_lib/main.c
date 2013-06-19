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
    //char *s1 = "ACACACTAAA";
    //char *s2 = "AGCACACAG";
    char *s1 = "ACACACTAAAGG";
    char *s2 = "AAAAAAAAAAAAGG";
    //char *s1 = "ATGCAGT";
    //char *s2 = "ATAAGT";
    //char *s1 = "AAAAA";
    //char *s2 = "AAA";
    
    int m = (int) strlen(s2);
    int n = (int) strlen(s1);


    int **matrix = initMatrix(m, n);
    
    sw(s1, s2, matrix);
    
    printMatrix(matrix, m, n);
    
    freeMatrix(matrix, m);
    
    return 0;
}