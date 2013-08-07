//
//  main.c
//  test_sw
//
//  Created by Laurence Bortfeld on 06.06.13.
//  Copyright (c) 2013 Hochschule fuer Technik und Wirtschaft. All rights reserved.
//

// #include <stdio.h>
#include "sw_opencl.h"


int main(int argc, const char *argv[])
{
  int devices = 0;
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
  char *s1 = "ACACACTA";
  char *s2 = "AGCACACA";
  //char *s1 = "ANANAS";
  //char *s2 = "BANANE";

  int i = 0;
  int sub = 4;
  for (i = 0; i < 100; i++)
  {
    sw(s1, s2, sub);
    printf("\n");
  }

  sclHard device = sclGetGPUHardware(0, &devices);
  sclSoft kernel = sclGetCLSoftware("kernel.cl", "sw", device);

  for (i = 0; i < 100; i++) {
    parallel_sw(s1, s2, sub, device, kernel);
  }

  sclReleaseClSoft(kernel);
  sclReleaseClHard(device);

  return 0;
}
