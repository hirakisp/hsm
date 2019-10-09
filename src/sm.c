#include "sm.h"

HSM_FUNC sm1[ HSM_EVENT_MAX ] = {
	example1_event1, example1_event2
};

HSM_FUNC sm2[ HSM_EVENT_MAX ] = {
	example2_event1, example2_event2
};

struct HSM_STATE sm[ HSM_STATE_MAX ] = {
	{ example1_entry, example1_exit, sm1},
	{ example2_entry, example2_exit, sm2}
};
