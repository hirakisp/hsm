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
