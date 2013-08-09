#include "sw_file.h"

char **getStrings(char *filename, int lineLength, int *numLines)
{
  // Add 2 to the line length for newline characters.
  lineLength = lineLength + 2;

  FILE *f;
  char **lines = NULL;
  char line[lineLength];
  f = fopen(filename, "r");

  if (f == NULL)
    return NULL;

  while(fgets(line, lineLength, f))
  {
    *numLines = *numLines + 1;
    lines = (char**)realloc(lines, sizeof(char*)*(*numLines));
    removeNewLine(line);
    lines[(*numLines)-1] = strdup(line);
  }

  fclose(f);

  return lines;
}


void removeNewLine(char *string)
{
  char *c = strchr(string, '\n');
  if (c)
    *c = '\0';

  c = strchr(string, '\r');
  if (c)
    *c = '\0';
}

