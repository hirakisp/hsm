#include "file.h"

int file_out(char * fn, char * str)
{
	FILE *fp;

	fp = fopen(fn, "w");
	if (fp == NULL) {
		printf("can't open\n");
		return HSM_RET_NG;
	}

	fprintf(fp, str);	/* print your string */
	fclose(fp);

	return HSM_RET_OK;
}
