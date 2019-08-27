#include "hsm_lib.h"
#include <unistd.h>
#include <stdio.h>

int main (void)
{
	printf("running!\n");

	while (1) {
		hsm_run();

		printf("wait 3sec...\n");
		sleep(3);

		hsm_set_ev(HSM_EVID_TIMEOUT, (void *)3);
	}

	return 0;
}


