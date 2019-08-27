
/* system call */
#define HSM_NOTRANS  (0xFFFF)
extern void hsm_run(void);
extern void hsm_set_ev( int event_id, void *event_data );

/* generate code */
#define HSM_EVID_TIMEOUT (0)
#define HSM_EVID_ADC (1)

