#ifndef SCH_CONFIG
#define SCH_CONFIG

#include "sch_tdefs.h"


/** Include the compiler std typedef headers here */
#include <stdint.h>
/************************************************/

#define TOTAL_TASKS 3

extern task_t task[TOTAL_TASKS];

enum etask_ID
{
	TSKID_0,
	TSKID_1,
	TSKID_2
};


#endif