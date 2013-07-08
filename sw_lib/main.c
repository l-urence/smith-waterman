//
//  main.c
//  test_sw
//
//  Created by Laurence Bortfeld on 06.06.13.
//  Copyright (c) 2013 Hochschule fuer Technik und Wirtschaft. All rights reserved.
//

// #include <stdio.h>
#include "sw_serial.h"
#include "sw_file.h"



int main(int argc, const char *argv[])
{
    //char *s1 = "ACACACTAAA";
    //char *s2 = "AGCACACAG";
    //char *s1 = "ACACACTAAAGG";
    //char *s2 = "AAAAAAAAAAAAGG";
    //char *s1 = "ATGCAGT";
    //char *s2 = "ATAAGT";
    //char *s1 = "AAA";
    //char *s2 = "AAABA";
    //char *s1 = "ANANASDDDEEEEEEEEEEEEEE";
    //char *s2 = "BANANEXXXEEEEEEEEEEEEEE";
    //char *s1 = "ACACACTA";
    //char *s2 = "AGCACACA";
    char *s1 = "ANANASS";
    char *s2 = "BANANESS";

    sw(s1, s2);
    
    return 0;
}
