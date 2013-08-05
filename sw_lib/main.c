//
//  main.c
//  test_sw
//
//  Created by Laurence Bortfeld on 06.06.13.
//  Copyright (c) 2013 Hochschule fuer Technik und Wirtschaft. All rights reserved.
//

// #include <stdio.h>
#include "sw_serial.h"
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
  char *s1 = "ACACACTAACACACTA";
  char *s2 = "AGCACACAAGCACACA";
  //char *s1 = "ANANAS";
  //char *s2 = "BANANE";

  /*int i = 0;
  for (i = 0; i < 10; i++)
  {
    sw(s1, s2, 4);
    printf("\n");
  }*/

  sclHard device = sclGetCPUHardware(0, &devices);
  sclSoft kernel = sclGetCLSoftware("kernel.cl", "sw", device);

  int i = 0;
  for (i = 0; i < 1; i++) {
    parallel_sw(s1, s2, 4, device, kernel);
  }

  sclReleaseClSoft(kernel);
  sclReleaseClHard(device);

  return 0;
}
