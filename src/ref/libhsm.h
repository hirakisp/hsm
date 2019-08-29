#include "libhsm_param.h"

/*
 * External SystemCall
 */
#define HSM_NOTRANS  (0xFFFF)

extern void hsm_run(void);
extern void hsm_set_ev( int event_id, void *event_data );
