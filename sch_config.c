#include "sch_config.h" 
#include <stdint.h> /* include the compiler standard define type header */



/* task list each element with
*  {function_pointer, 
		periodicity in mS, 
		first call time in mS} */
task_t task[TOTAL_TASKS] =
{
	{function0, 50, 0},      
	{function1,10, 10},
	{function2, 3000, 0}
};