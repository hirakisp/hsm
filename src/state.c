#include <stdio.h>
#include "libhsm.h"
#include "sm.h"

int example1_entry(void *ev)
{
	printf("%s \n", __func__);
	int arg = 0xFF;

	hsm_set_ev(HSM_EVENT_1, (void *)&arg);

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

	printf(" argment is 0x%02x", *arg);

	return HSM_STATE_2;
}

int example1_event2(void *ev)
{
	printf("%s \n", __func__);
	return HSM_NOTRANS;
}

int example2_entry(void *ev)
{
	printf("%s \n", __func__);
	return HSM_NOTRANS;
}

int example2_exit(void *ev)
{
	printf("%s \n", __func__);
	return HSM_NOTRANS;
}

int example2_event1(void *ev)
{
	printf("%s \n", __func__);
	return HSM_NOTRANS;
}

int example2_event2(void *ev)
{
	printf("%s \n", __func__);
	return HSM_NOTRANS;
}
