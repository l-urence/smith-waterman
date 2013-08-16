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

// Available arguments
const static struct option long_options[] =
{
  {"verbose", no_argument,       &verbose, 1},  // Print out alignments.
  {"sub",     required_argument, 0, 's'}, // Set the size of submatrox.
  {"length",  required_argument, 0, 'l'}, // Set the length of the strings.
  {"device",  required_argument, 0, 'd'}, // Set the openCL device.
  {"runs",    required_argument, 0, 'r'}, // Set the number of iterations.
  {"help",    no_argument      , 0, 'h'}, // Print out help.
  {0, 0, 0, 0}
};

// Prints out the help text.
void printHelp();

// Prints out an error message.
void printError(char *message);

// Gennerates a random string
// Assign pointer to free meomry for sth string and a length.
void genRandom(char *s, const int len);

#endif

