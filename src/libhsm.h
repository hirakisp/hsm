#ifndef _LIBHSM_H_
#define _LIBHSM_H_

#define HSM_RET_OK (0)
#define HSM_RET_NG (-1)

#define HSM_TRUE (1)
#define HSM_FALSE (0)

typedef char HSM_BOOL;

//typedef int (*HSM_ENTRY)(void);
//typedef int (*HSM_EXIT)(void);
typedef int (*HSM_FUNC)(void *);

struct HSM_STATE {
	HSM_FUNC entry;
	HSM_FUNC exit;
	HSM_FUNC *func;
};

struct HSM_DATA {
	HSM_BOOL event_created;
	int new_state;
	int current_state;
	int state_max;
	int event_max;
	int event_id;
	void* event_data;
	struct HSM_STATE *hsm_funcs;
};

/*
 * External SystemCall
 */
#define HSM_NOTRANS  (0xFFFF)

extern void hsm_init(struct HSM_STATE *, int, int);
extern void hsm_run(void);
extern void hsm_set_ev( int event_id, void *event_data );


#endif
