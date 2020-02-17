#ifndef _LIBHSM_H_
#define _LIBHSM_H_

#define ENOOK  (0)
#define ENOENT (2)

#define HSM_TRUE (1)
#define HSM_FALSE (0)

#define HSM_EV_BUFSIZE    (32)

typedef char HSM_BOOL;

//typedef int (*HSM_ENTRY)(void);
//typedef int (*HSM_EXIT)(void);
typedef void (*HSM_INIT)(void);
typedef int (*HSM_FUNC)(void *);


struct HSM_STATE {
	HSM_INIT init;
	HSM_FUNC entry;
	HSM_FUNC exit;
	HSM_FUNC *func;
};

struct HSM_EVENT {
	int id;
	void * data;
};

struct HSM_DATA {
	int new_state;
	int current_state;
	int event_num;
	int event_wpos;
	int event_rpos;
	int state_max;
	int event_max;
	const struct HSM_STATE *hsm_funcs;
	struct HSM_EVENT event[HSM_EV_BUFSIZE];
};

/*
 * External SystemCall
 */
#define HSM_NOTRANS  (0xFFFF)

extern void hsm_init(const struct HSM_STATE *, int, int);
extern void hsm_run(void);
extern void hsm_set_ev( int event_id, void *event_data );


#endif
