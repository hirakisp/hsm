#include "libhsm.h"
#include <stdio.h>

struct HSM_DATA self;

static void hsm_ev_enqueue(struct HSM_EVENT event)
{
	self.event[self.event_pos] = event;
	self.event_num++;

	if (self.event_pos + 1 >= HSM_EV_BUFSIZE)
		self.event_pos = 0;
	else
		self.event_pos++;

}

static struct HSM_EVENT hsm_ev_dequeue()
{
	struct HSM_EVENT event = {0};

	if (self.event_num > 0) {
		if (self.event_pos > 0)
			event = self.event[self.event_pos - 1];
		else
			event = self.event[HSM_EV_BUFSIZE - 1];

		self.event_num--;
	}
	return event;
}

void hsm_init(const struct HSM_STATE *funcs, int event_max, int state_max)
{
	self.new_state = 0;
	self.current_state = HSM_NOTRANS;
	self.event_pos = 0;

	/* set input parameter */
	self.state_max = state_max;
	self.event_max = event_max;
	self.hsm_funcs = funcs;

	/* raise first entry event */
	self.event_created = HSM_TRUE;
	self.event_num = 1;
}

void hsm_run()
{
	struct HSM_EVENT tmp_event;
	int tmp_new_state;

	if (self.current_state != self.new_state) {

		/* Run exit event */
		if (self.state_max > self.current_state) {
			if (self.hsm_funcs[self.current_state].exit != NULL)
				self.hsm_funcs[self.current_state].exit(NULL);
		}

		/* Run entry event */
		if (self.state_max > self.new_state) {
			if (self.hsm_funcs[self.new_state].entry != NULL)
				self.hsm_funcs[self.new_state].entry(NULL);
		}

		self.current_state = self.new_state;
	}

	if (self.event_created) {
		tmp_event = hsm_ev_dequeue();
		tmp_new_state = self.hsm_funcs[self.current_state].func[tmp_event.id](tmp_event.data);
		if (tmp_new_state != HSM_NOTRANS)
			self.new_state = tmp_new_state;

		if (self.event_num == 0)
			self.event_created = HSM_FALSE;

	}
}

void hsm_set_ev( int event_id, void *event_data )
{
	struct HSM_EVENT event;
	event.id = event_id;
	event.data = event_data;
	hsm_ev_enqueue(event);

	self.event_created = HSM_TRUE;
}
