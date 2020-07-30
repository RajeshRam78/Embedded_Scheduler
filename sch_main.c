#include "sch_main.h"
#include <stdint.h> /* include the compiler type def header here instead */

#define DEBUG

static volatile uint32_t system_tick;

/* call this function in periodic timer interrupt isr */
void increment_tick(void)
{
	system_tick++;
}

uint32_t get_system_tick(void)
{
	return system_tick;
}


void wait_ms(uint32_t ms_count)
{
	uint32_t tick_now = get_system_tick();
	while((get_system_tick() - tick_now) < ms_count)
	{
	}
}

void sch_tsk_qck_call(enum etask_ID tsk_ID)
{
	task[tsk_ID].task_tick = task[tsk_ID].periodicity;
}

void scheduler_main(void)
{
	static uint32_t last_tick;
	uint32_t tick_delta;
	uint8_t task_id;
	
	#ifdef DEBUG
	static uint8_t ovrld_task_id = TOTAL_TASKS;
	#endif
	
	if(get_system_tick() != last_tick)
	{
		tick_delta = get_system_tick() - last_tick;
		last_tick = get_system_tick();
	
		/* Iterate through tasks */
		for(task_id = 0U; task_id < TOTAL_TASKS; task_id++)
		{
			task[task_id].task_tick += tick_delta;
			if(task[task_id].task_tick >= task[task_id].periodicity)
			{
				#ifdef DEBUG
				if(task[task_id].task_tick != task[task_id].periodicity)
				{
					/* task of task_id delayed in execution by time = task_tick - periodicity mS */
					/* At this point the ovrld_task_id holds the id of the task which may have caused delay in execution */
					/* put a break point at the start of this condition to check the overloaded task id */
					/* reloading the variable to enable the check in next loop */
					ovrld_task_id = TOTAL_TASKS;
				}
				#endif
				if(task[task_id].fptr != 0)
				{
				    task[task_id].fptr();
				}
				task[task_id].task_tick = 0U;
				
				#ifdef DEBUG
				if((get_system_tick() != last_tick) && (ovrld_task_id == TOTAL_TASKS))
				{
				    ovrld_task_id = task_id;
				}
				#endif
				
			}
		}
	}
}
