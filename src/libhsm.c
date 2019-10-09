#include "libhsm.h"
#include <stdio.h>

struct HSM_DATA self;

void hsm_init(struct HSM_STATE *funcs, int event_max, int state_max)
{
	self.event_created = HSM_TRUE;
	self.new_state = 0;
	self.current_state = HSM_NOTRANS;
	self.event_id = 0;
	self.event_data = 0;
	self.state_max = state_max;
	self.event_max = event_max;
	self.hsm_funcs = funcs;
}

/*
 *
*/
void hsm_run()
{
	void *tmp_event_data;
	int tmp_new_state;

	if (self.event_created) {

		tmp_event_data = self.event_data;

		if (self.current_state != self.new_state) {

			if (self.state_max > self.current_state) {
				if (self.hsm_funcs[self.current_state].exit != NULL)
					self.hsm_funcs[self.current_state].exit(NULL);
			}

			if (self.state_max > self.new_state) {
				if (self.hsm_funcs[self.new_state].entry != NULL)
					self.hsm_funcs[self.new_state].entry(NULL);
			}
		}

		self.current_state = self.new_state;
		tmp_new_state = self.hsm_funcs[self.current_state].func[self.event_id](tmp_event_data);
		if (tmp_new_state != HSM_NOTRANS)
			self.new_state = tmp_new_state;

		self.event_data = NULL;
		self.event_created = HSM_FALSE;
	}
}

void hsm_set_ev( int event_id, void *event_data )
{
	self.event_id = event_id;
	self.event_data = event_data;
	self.event_created = HSM_TRUE;
}
