#ifndef _SM_H_
#define _SM_H_
#include "libhsm.h"
#include "state.h"

enum {
    HSM_EVENT_test,
    HSM_EVENT_MAX
};

enum {
    HSM_STATE_idle,
    HSM_STATE_MAX
};

extern HSM_FUNC sm1[ HSM_EVENT_MAX ];
extern const struct HSM_STATE sm[ HSM_STATE_MAX ];

#endif
