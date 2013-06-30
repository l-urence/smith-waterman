//
//  file.c
//  test_sw
//
//  Created by Laurence Bortfeld on 30.06.13.
//  Copyright (c) 2013 Hochschule fuer Technik und Wirtschaft. All rights reserved.
//

#include "file.h"

static char *read_file_contents(const char *filename)
{
	long size;
	char *ret = NULL;
	char *contents = NULL;
	FILE *fh;
    
	if (!(fh = fopen(filename,"r")))
		return NULL;
    
	fseek(fh,0,SEEK_END);
	size = ftell(fh);
	if (size < 1)
		goto out;
	fseek(fh,0,SEEK_SET);
    
	if (!(contents = malloc(size+1)))
		goto out;
	if ((fread(contents, 1, size, fh) != size))
		goto out;
    
	contents[size] = 0;
    
	ret = contents;
	contents = NULL;
out:
	fclose(fh);
	free(contents);
	return ret;
}