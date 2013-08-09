#ifndef dna_sw_main_h
#define dna_sw_main_h

#include <getopt.h>
#include "sw_opencl.h"
#include "sw_file.h"

const static struct option long_options[] =
{
  {"file",    required_argument, 0, 'f'},
  {"length",  required_argument, 0, 'l'},
  {"device",  required_argument, 0, 'd'},
  {"size",    required_argument, 0, 's'},
  {"help",    no_argument      , 0, 'h'},
  {0, 0, 0, 0}
};

void printHelp();
void printError(char *message);

#endif

