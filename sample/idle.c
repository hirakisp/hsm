#include "hsm_lib.h"
#include "idle.h"

int idle_entry(void *ev_data)
{
	return HSM_NOTRANS;
}

int idle_exit(void *ev_data)
{
	return HSM_NOTRANS;
}

int idle_timeout(void *ev_data)
{
	return HSM_NOTRANS;
}

int idle_adc(void *ev_data)
{
	return HSM_NOTRANS;
}
