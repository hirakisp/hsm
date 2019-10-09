#include "libhsm.h"
#include "sm.h"
#include <unistd.h>
#include <stdio.h>

int main (void)
{
	printf("running!\n");

	hsm_init(sm, HSM_EVENT_MAX, HSM_STATE_MAX);

	while (1) {
		hsm_run();
	}

	return 0;
}
