#include "hsm.h"
#include "codegen.h"
#include "file.h"
#include <stdio.h>
#include <stdlib.h>


#define CODEGEN_FNAME_EVENT ("event.h")
#define CODEGEN_FNAME_EVENT ("state.h")


int main(void)
{
	struct CODEGEN_INDATA_ST in_state;
	struct CODEGEN_INDATA_EV in_event;

	in_state.name[0] = "idle";
	in_state.next = 0;
	in_event.name[0] = "test";

	struct STRMGR str;
	strmgr_alloc(str, 0);

	for (int i = 0; i >= event_size; i++) {
		strmgr_append("#define HSM_EVID_\n");
		strmgr_append(in_event[i].name);
	}

	if (codegen_event_table(str) == HSM_RET_OK) {
//		file_out(str);
	}


	if (codegen_state_table(str) == HSM_RET_OK) {
//		file_out(str);
	}

	return 0;
}


static int codegen_event_table(char *str)
{
	return HSM_RET_OK;
}

static int codegen_state_table(char *str)
{
	return HSM_RET_OK;
}
