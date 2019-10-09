#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEFAULT_ALOC_EXTRA (128)

struct STRMGR {
	char *str;
	int len;
	int aloc;
	int aloc_extra;
};

int strmgr_alloc(STRMGR *mgr, int aloc)
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

void strmgr_free(STRMGR *mgr)
{
	free(mgr->str);
}

int strmgr_append(STRMGR *mgr, const char *str)
{
	int tmplen = mgr->len + strlen(str);
	if ( tmplen > mgr->aloc ) {
		mgr->aloc = tmplen + mgr->aloc_extra;
		sb->str = (char *)realloc(mgr->str, mgr->aloc);
		if (sb->str == NULL)
			return 0;
	}
	strcpy(mgr->str + mgr->len, str);
	mgr->len = tmplen;

	printf("%s", str);
	return 1;
}

void strmgr_clr(STRMGR *mgr)
{
	mgr->len = 0;
	mgr->str[0] = '\0';
}
