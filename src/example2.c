#include <stdio.h>
#include "libhsm.h"
#include "sm.h"

void example2_init(void)
{

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
