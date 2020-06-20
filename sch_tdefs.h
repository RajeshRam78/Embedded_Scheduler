#ifndef SCH_TDEFS
#define SCH_TDEFS

#include "sch_config.h" 
#include <stdint.h> /* instead call compiler specific type def header */

typedef struct 
{
    void (*fptr)(void);
    uint32_t periodicity;
    uint32_t task_tick;
}task_t;


#endif