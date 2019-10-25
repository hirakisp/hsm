#include "libhsm.h"
#include "codegen.h"
#include "file.h"
#include "strmgr.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CODEGEN_FNAME_C ("sm.c")
#define CODEGEN_FNAME_H ("sm.h")


int main(void)
{
	char tmpstr[128];
	struct CODEGEN_INDATA_ST in_state[1];
	struct CODEGEN_INDATA_EV in_event[1];
	int i, j;
	int event_size = 1;
	int state_size = 1;
	struct STRMGR strmgr;

	strcpy(in_state[0].name, "idle");
	strcpy(in_event[0].name, "test");
	in_state[0].next = 0;

	strmgr_alloc(&strmgr, 0);

	/* _SM_H_ */
	strmgr_append(&strmgr, "#ifndef _SM_H_\n");
	strmgr_append(&strmgr, "#define _SM_H_\n");
	strmgr_append(&strmgr, "#include \"libhsm.h\"\n");
	strmgr_append(&strmgr, "#include \"state.h\"\n");

	/* Event enum */
	strmgr_append(&strmgr, "\n");
	strmgr_append(&strmgr, "enum {\n");
	for (i = 0; i < event_size; i++) {
		sprintf(tmpstr, "    HSM_EVENT_%s,\n", in_event[i].name);
		strmgr_append(&strmgr, tmpstr);
	}
	strmgr_append(&strmgr, "    HSM_EVENT_MAX\n");
	strmgr_append(&strmgr, "};\n");

	/* State enum */
	strmgr_append(&strmgr, "\n");
	strmgr_append(&strmgr, "enum {\n");
	for (i = 0; i < state_size; i++) {
		sprintf(tmpstr, "    HSM_STATE_%s,\n", in_state[i].name);
		strmgr_append(&strmgr, tmpstr);
	}
	strmgr_append(&strmgr, "    HSM_STATE_MAX\n");
	strmgr_append(&strmgr, "};\n");

	/* Footer */
	strmgr_append(&strmgr, "\n");
	for (i = 0; i < state_size; i++) {
		sprintf(tmpstr, "extern HSM_FUNC sm%d[ HSM_EVENT_MAX ];\n", i + 1);
		strmgr_append(&strmgr, tmpstr);
	}
	strmgr_append(&strmgr, "extern const struct HSM_STATE sm[ HSM_STATE_MAX ];\n");
	strmgr_append(&strmgr, "\n");
	strmgr_append(&strmgr, "#endif\n");

	file_out(CODEGEN_FNAME_H, strmgr.str);
	strmgr_clr(&strmgr);

	/* _SM_C_ */
	strmgr_append(&strmgr, "#include \"sm.h\"\n");
	strmgr_append(&strmgr, "\n");
	for (i = 0; i < state_size; i++) {
		sprintf(tmpstr, "HSM_FUNC sm%d[ HSM_EVENT_MAX] = {\n", i + 1);
		strmgr_append(&strmgr, tmpstr);

		for (j = 0; j < event_size; j++) {
			sprintf(tmpstr, "    %s_%s", in_state[i].name, in_event[j].name);
			strmgr_append(&strmgr, tmpstr);
			if (j + 1 >= event_size) {
				strmgr_append(&strmgr, "\n");
			} else
				strmgr_append(&strmgr, ",\n");
		}
	}
	strmgr_append(&strmgr, "};\n");

	strmgr_append(&strmgr, "\n");
	strmgr_append(&strmgr, "const struct HSM_STATE sm[ HSM_STATE_MAX ] = {\n");
	for (i = 0; i < state_size; i++) {
		sprintf(tmpstr, "    { %s_entry, %s_exit, sm%d }", in_state[i].name, in_state[i].name, i + 1);
		strmgr_append(&strmgr, tmpstr);
		if (i + 1 >= state_size)
			strmgr_append(&strmgr, "\n");
		else
			strmgr_append(&strmgr, ",\n");
	}
	strmgr_append(&strmgr, "};\n");

	file_out(CODEGEN_FNAME_C, strmgr.str);
	strmgr_free(&strmgr);
	return 0;
}
