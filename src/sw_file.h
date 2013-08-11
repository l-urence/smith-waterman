#ifndef sw_file_h
#define sw_file_h

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Error constans
#define SW_READ_FILE_ERROR   -1
#define SW_READ_FILE_SUCCESS  0

//
char **getStrings(char *filename, int lineLength, int *numLines);

//
void removeNewLine(char *string);

#endif
