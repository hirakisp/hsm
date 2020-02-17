#include "sm.h"

HSM_FUNC sm1[ HSM_EVENT_MAX] = {
    idle_test
};

const struct HSM_STATE sm[ HSM_STATE_MAX ] = {
    { idle_entry, idle_exit, sm1 }
};
