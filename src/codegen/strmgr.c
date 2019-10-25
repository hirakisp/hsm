#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "strmgr.h"

#define DEFAULT_ALOC_EXTRA (128)

int strmgr_alloc(struct STRMGR *mgr, int aloc)
{
	mgr->len = 0;
	mgr->aloc = (aloc > 0) ? aloc : DEFAULT_ALOC_EXTRA;
	mgr->aloc_extra = mgr->aloc;
	mgr->str = (char *)malloc(mgr->aloc);
	if (mgr->str != NULL) {
		mgr->str[0] = '\0';
		return 0;
	}
	return 1;
}

void strmgr_free(struct STRMGR *mgr)
{
	free(mgr->str);
}

int strmgr_append(struct STRMGR *mgr, const char *str)
{
	int tmplen = mgr->len + strlen(str);
	if ( tmplen > mgr->aloc ) {
		mgr->aloc = tmplen + mgr->aloc_extra;
		mgr->str = (char *)realloc(mgr->str, mgr->aloc);
		if (mgr->str == NULL)
			return 0;
	}
	strcpy(mgr->str + mgr->len, str);
	mgr->len = tmplen;

	printf("%s", str);
	return 1;
}

void strmgr_clr(struct STRMGR *mgr)
{
	mgr->len = 0;
	mgr->str[0] = '\0';
}
