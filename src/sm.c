/**
 * You would better automatically make this file from diagram.
 * For example, state-machine diagram of UML.
 */

#include "sm.h"
#include "example1.h"
#include "example2.h"

HSM_FUNC sm1[ HSM_EVENT_MAX ] = {
	example1_event1, example1_event2
};

HSM_FUNC sm2[ HSM_EVENT_MAX ] = {
	example2_event1, example2_event2
};

const struct HSM_STATE sm[ HSM_STATE_MAX ] = {
	{ example1_init, example1_entry, example1_exit, sm1},
	{ example2_init, example2_entry, example2_exit, sm2}
};
