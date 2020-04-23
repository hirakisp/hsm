#include <stdio.h>
#include "libhsm.h"
#include "sm.h"

void example1_init(void)
{
	/*
	 * Nothing to do.
	 */
	printf("%s\n", __func__);
}

int example1_entry(void *ev)
{
	char ev_msg;
	printf("%s \n", __func__);
	ev_msg = 0xFF;

	hsm_set_ev(HSM_EVENT_1, (char *)&ev_msg, 1);

	return HSM_NOTRANS;
}

int example1_exit(void *ev)
{
	printf("%s \n", __func__);
	return HSM_NOTRANS;
}

int example1_event1(void *ev)
{
	printf("%s \n", __func__);

	char * arg = (char *)(ev);

	printf(" argment is 0x%02x\n", *arg);

	return HSM_STATE_2;
}

int example1_event2(void *ev)
{
	printf("%s \n", __func__);
	return HSM_NOTRANS;
}
