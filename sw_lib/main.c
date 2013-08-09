#include "main.h"

int main(int argc, char * const argv[])
{
  int c;
  int option_index = 0, lineLength = 0;
  char *filename = NULL;

  // Parsing arguments
  while ((c = getopt_long(argc, argv, "f:l:d:s:", long_options, &option_index)) != -1)
  {
    switch (c)
    {
      case 'f':
        filename = optarg;
        break;
      case 'l':
        lineLength = strtoumax(optarg, NULL, 10);
        if (lineLength == UINTMAX_MAX)
          printError("-l --length must be an integer");
        break;
      case 'd':
        break;
      case 's':
        break;
      case 'h':
        printHelp();
        return EXIT_SUCCESS;
      default:
        printHelp();
        return EXIT_FAILURE;
    }
  }

  // Check arguments
  if (filename == NULL || lineLength == 0)
  {
    printError("Missing arguments");
    return EXIT_FAILURE;
  }

  char **strings = NULL;
  int numLines = 0;

  if ((strings = getStrings(filename, lineLength, &numLines)) == NULL)
    printError("Can not open file");

  int i = 0, j = 0;
  for (i=0; i<numLines; i++)
      printf("%s\n", strings[i]);


/*  int devices = 0;
  int sub = 4;
  char *s1 = "ACACACTA";
  char *s2 = "AGCACACA";

  sclHard device = sclGetCPUHardware(0, &devices);
  sclSoft kernel = sclGetCLSoftware("kernel.cl", "sw", device);

  sw(s1, s2, sub);
  parallel_sw(s1, s2, sub, device, kernel);

  sclReleaseClSoft(kernel);
  sclReleaseClHard(device);*/

  free(strings);
  return EXIT_SUCCESS;
}

//
void printHelp()
{
  printf("usage: sw -f file [-d device] [-s size]\n");
  printf("  -f --file   \t Set the file to read in the strings.\n");
  printf("  -l --length \t Set the string length.\n");
  printf("  -d --device \t Set the openCL device [gpu/cpu]. Default: cpu.\n");
  printf("  -s --size   \t Set the size of the submatrix for parallel computation.\n");
}

//
void printError(char *message)
{
  printf("%s\n", message);
  exit(EXIT_FAILURE);
}

