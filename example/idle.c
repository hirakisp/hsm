#include "hsm_lib.h"
#include "idle.h"
#include <stdio.h>

int idle_entry(void *ev)
{
	printf("enter the idle state \n");
	return HSM_NOTRANS;
}

int idle_exit(void *ev)
{
	printf("exit \n");
	return HSM_NOTRANS;
}

int idle_timeout(void *ev)
{
	static int counter;

	printf("t.o \n");
	counter += (int)(ev);
	if (counter > 10)
		return 1;
	
	return HSM_NOTRANS;
}

int idle_adc(void *ev)
{
	return HSM_NOTRANS;
}
