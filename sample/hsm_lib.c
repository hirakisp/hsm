#include "hsm_lib.h"
#include "idle.h"

/* system parameter define */
#define HSM_EVENT_MAX (2)
#define HSM_STATE_MAX (2)

/* template codes */
#define HSM_TRUE (1)
#define HSM_FALSE (0)
#define NULL (0)

typedef char HSM_BOOL;

struct HSM_DATA {
	HSM_BOOL event_created;
	int new_state;
	int current_state;
	int event_id;
	void* event_data;
};

//typedef int (*HSM_ENTRY)(void);
//typedef int (*HSM_EXIT)(void);
typedef int (*HSM_FUNC)(void *);

struct HSM_STATE {
	HSM_FUNC entry;
	HSM_FUNC exit;
	HSM_FUNC func[ HSM_EVENT_MAX ];
};

struct HSM_STATE hsm_func[ HSM_STATE_MAX ] = {
	{ idle_entry, idle_exit, {idle_timeout, idle_adc}},
	{ idle_entry, idle_exit, {idle_timeout, idle_adc}}
};

struct HSM_DATA self;

/*
 *
*/
void hsm_run()
{
	void *tmp_event_data;

	if (self.event_created) {

		tmp_event_data = self.event_data;

		if (self.current_state != self.new_state) {
			if (hsm_func[self.current_state].exit != NULL)
				hsm_func[self.current_state].exit(NULL);

			if (hsm_func[self.new_state].entry != NULL)
				hsm_func[self.new_state].entry(NULL);
		}
		self.current_state = self.new_state;
		self.new_state = hsm_func[self.current_state].func[self.event_id](tmp_event_data);

		self.event_data = NULL;
		self.event_created = HSM_FALSE;
	}
}

void hsm_create_event( int event_id, void *event_data )
{
	self.event_id = event_id;
	self.event_data = event_data;
	self.event_created = HSM_TRUE;
}

