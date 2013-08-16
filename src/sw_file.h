#ifndef sw_file_h
#define sw_file_h

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Error constans
#define SW_READ_FILE_ERROR   -1
#define SW_READ_FILE_SUCCESS  0

// Reads out an file and returns every line in an array
char **getStrings(char *filename, int lineLength, int *numLines);

// Removes newline characters from a string.
void removeNewLine(char *string);

#endif
