#include "idle.h"

struct HSM_STATE hsm_func[ HSM_STATE_MAX ] = {
	{ idle_entry, idle_exit, {idle_timeout, idle_adc}},
	{ idle_entry, idle_exit, {idle_timeout, idle_adc}}
};
