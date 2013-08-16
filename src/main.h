#ifndef dna_sw_main_h
#define dna_sw_main_h

#include <getopt.h>
#include <time.h>
#include "sw_opencl.h"
#include "sw_file.h"

enum devicee
{
  GPU, CPU
};

int verbose = 0;
int sub = 10;
int runs = 100;
int length = 20;
int deviceType = CPU;


const static struct option long_options[] =
{
  {"verbose", no_argument,       &verbose, 1},
  {"sub",     required_argument, 0, 's'},
  {"length",  required_argument, 0, 'l'},
  {"device",  required_argument, 0, 'd'},
  {"runs",    required_argument, 0, 'r'},
  {"help",    no_argument      , 0, 'h'},
  {0, 0, 0, 0}
};

//
void printHelp();

//
void printError(char *message);

//
void genRandom(char *s, const int len);

#endif

