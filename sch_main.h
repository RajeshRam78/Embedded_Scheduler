#ifndef SCH_MAIN
#define SCH_MAIN

#include "sch_config.h"
#include "sch_tdefs.h"
 

extern void increment_tick(void);
extern void scheduler_main(void);
extern uint32_t get_system_tick(void);
extern void wait_ms(uint32_t ms_count);
extern void sch_tsk_qck_call(enum etask_ID tsk_ID);
#endif