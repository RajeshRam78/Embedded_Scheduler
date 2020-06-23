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

void scheduler_main(void)
{
	static uint32_t last_tick;
	uint32_t tick_delta;
	uint8_t task_id;
	
	#ifdef DEBUG
	static uint8_t ovrld_task_id;
	#endif
	
	if(get_system_tick() != last_tick)
	{
		tick_delta = get_system_tick() - last_tick;
		last_tick = get_system_tick();
	
	
		if(1U < tick_delta)
		{
			/* IMPORTANT : 
			schedular over loaded for the current configuration*/
			/* Handle the load here OR reconfigure the task list*/
			#ifdef DEBUG
			ovrld_task_id = 0;
			#endif
		}
		
		/* Iterate through tasks */
		for(task_id = 0U; task_id < TOTAL_TASKS; task_id++)
		{
			#ifdef DEBUG
				ovrld_task_id = task_id;
			#endif
			task[task_id].task_tick += tick_delta;
			if(task[task_id].task_tick >= task[task_id].periodicity)
			{
				task[task_id].fptr();
				task[task_id].task_tick = 0U;
				
			}
		}
	}
}
