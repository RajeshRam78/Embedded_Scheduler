#ifndef SCH_MAIN
#define SCH_MAIN

#include "sch_config.h"
#include "sch_tdefs.h"
 

extern void increment_tick(void);
extern void scheduler_main(void);
extern uint32_t get_system_tick(void);

#endif