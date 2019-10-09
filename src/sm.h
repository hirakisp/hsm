#ifndef _SM_H_
#define _SM_H_
/* system parameter define */
/*
 * Event
 */

#include "state.h"

enum {
	HSM_EVENT_1 = 0,
	HSM_EVENT_2,
	HSM_EVENT_MAX
};

/*
 * State
 */
enum {
	HSM_STATE_1 = 0,
	HSM_STATE_2,
	HSM_STATE_MAX
};

HSM_FUNC sm1[ HSM_EVENT_MAX ];

HSM_FUNC sm2[ HSM_EVENT_MAX ];

struct HSM_STATE sm[ HSM_STATE_MAX ];
#endif
