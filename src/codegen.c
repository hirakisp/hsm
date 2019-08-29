#include "codegen.h"

int main(void)
{
	struct CODEGEN_INDATA_ST in_state;
	struct CODEGEN_INDATA_EV in_event;

#if 1
	/* TestCode */
	in_state.name[0] = "idle";
	in_state.next = 0;

	in_event.name[0] = "test";
#endif

	return 0;
}


void codegen_event_table(void)
{

}
