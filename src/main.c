#include "main.h"

int main(int argc, char * const argv[])
{
  int c;
  int option_index = 0;
  time_t time_start, time_end;
  int sub = 1;
  int runs = 1000;
  int length = 20;
  int deviceType = CPU;


  // Parsing arguments
  while ((c = getopt_long(argc, argv, "s:l:d:s:r:h", long_options, &option_index)) != -1)
  {
    switch (c)
    {
      case 's':
        sub = strtoumax(optarg, NULL, 10);
         if (sub == UINTMAX_MAX)
          printError("-s --sub must be an integer");
        break;
      case 'l':
        length = strtoumax(optarg, NULL, 10);
        if (length == UINTMAX_MAX)
          printError("-l --length must be an integer");
        break;
      case 'd':
        if (strcmp(optarg, "gpu") == 0)
          deviceType = GPU;
        break;
      case 'r':
        runs = strtoumax(optarg, NULL, 10);
         if (runs == UINTMAX_MAX)
          printError("-r --runds must be an integer");
        break;
      case 'h':
        printHelp();
        return EXIT_SUCCESS;
      default:
        printHelp();
        return EXIT_FAILURE;
    }
  }

  if (length % sub != 0)
    printError("stringLengh mod sub != 0 - Aboard");

  char *s1 = malloc(sizeof(char) * length); // = "AAUGCCAUUGACGGAAUGCCAUUGACCGAASDASDASDAASASASASASA";
  char *s2 = malloc(sizeof(char) * length); // = "CAGCCUCGCUUAGXCAGCCUCGCUUAGXAASDASDASASASASASASASA";

  genRandom(s1, length);
  genRandom(s2, length);

  printf("A: %s (%i)\nB: %s (%i)\n", s1, (int)strlen(s1), s2, (int)strlen(s2));
  printf("Submatrix size is set to: %i\n", sub);
  // Serial execution
  time(&time_start);

  int i, j;
  for (i=0; i<runs; i++)
  {
      sw(s1, s2, sub, verbose);
  }

  time(&time_end);
  printf("Serial version @ %i runs : %4.2f secounds\n",
      runs, (difftime(time_end, time_start)));



  // Parallel execution
  int devices = 0;
  sclHard device;
  if (deviceType == GPU)
    device = sclGetGPUHardware(0, &devices);
  else
    device = sclGetCPUHardware(0, &devices);

  sclSoft kernel = sclGetCLSoftware("kernel.cl", "sw", device);

  time(&time_start);
  for (i=0; i<runs; i++)
  {
      parallel_sw(s1, s2, sub, device, kernel, verbose);
  }
  time(&time_end);

  if (deviceType == GPU)
    printf("GPU ");
  else
    printf("CPU ");

  printf("Parallel version @ %i runs : %4.2f secounds\n",
      runs, (difftime(time_end, time_start)));

  sclReleaseClSoft(kernel);
  sclReleaseClHard(device);

  free(s1);
  free(s2);
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
void genRandom(char *s, const int len)
{
    static const char alphanum[] =
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";

    int i;
    for (i = 0; i < len; ++i)
    {
        s[i] = alphanum[rand() % (sizeof(alphanum) - 1)];
    }

    s[len] = 0;
}

//
void printError(char *message)
{
  printf("%s\n", message);
  exit(EXIT_FAILURE);
}

