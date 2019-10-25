#include <stdio.h>
#include "libhsm.h"
#include "file.h"

int file_out(char * fn, char * str)
{
	FILE *fp;

	fp = fopen(fn, "w");
	if (fp == NULL) {
		printf("can't open\n");
		return -(ENOENT);
	}

	fprintf(fp, str);	/* print your string */
	fclose(fp);

	return 0;
}
