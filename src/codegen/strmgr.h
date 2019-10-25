#ifndef _STRMGR_H_
#define _STRMGR_H_

struct STRMGR {
	char *str;
	int len;
	int aloc;
	int aloc_extra;
};

extern int strmgr_alloc(struct STRMGR *mgr, int aloc);
extern void strmgr_free(struct STRMGR *mgr);
extern int strmgr_append(struct STRMGR *mgr, const char *str);
extern void strmgr_clr(struct STRMGR *mgr);

#endif
