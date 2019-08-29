#include "libhsm.h"

struct HSM_DATA self = {HSM_TRUE, 0, HSM_NOTRANS, 0, 0};

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

			if (HSM_STATE_MAX > self.current_state) {
				if (hsm_func[self.current_state].exit != NULL)
					hsm_func[self.current_state].exit(NULL);
			}

			if (HSM_STATE_MAX > self.new_state) {
				if (hsm_func[self.new_state].entry != NULL)
					hsm_func[self.new_state].entry(NULL);
			}
		}

		self.current_state = self.new_state;
		tmp_new_state = hsm_func[self.current_state].func[self.event_id](tmp_event_data);
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
