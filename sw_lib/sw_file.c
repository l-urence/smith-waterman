#include "sw_file.h"

char *read_file_contents(const char *filename)
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
