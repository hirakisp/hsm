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
	int ev_msg;
	printf("%s \n", __func__);
	ev_msg = 0xFF;

	hsm_set_ev(HSM_EVENT_1, &ev_msg);

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

	int * arg = (int *)(ev);

	printf(" argment is 0x%02x\n", *arg);

	return HSM_STATE_2;
}

int example1_event2(void *ev)
{
	printf("%s \n", __func__);
	return HSM_NOTRANS;
}
