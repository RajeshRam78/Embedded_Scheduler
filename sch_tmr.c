/*
 * File:   VTMR.c
 * Author: Rajesh R
 *
 * Created on October 5, 2019, 11:58 PM
 */


#include "sch_tmr.h"

Tmr_dta_t Tmr_dta[TOTAL_TIMERS];

void TMR_set_status(TMR_id_t tmr_id, TMR_status_t status)
{
    Tmr_dta[tmr_id].status = status;
}

TMR_status_t TMR_get_status(TMR_id_t tmr_id)
{
    return Tmr_dta[tmr_id].status;
}

void TMR_start(TMR_id_t tmr_id, uint32_t mS_counter)
{
    Tmr_dta[tmr_id].mS_counter = mS_counter;
    Tmr_dta[tmr_id].status = TMR_ACTIVE;
}

void TMR_reset(TMR_id_t tmr_id)
{
    Tmr_dta[tmr_id].mS_counter = 0;
    Tmr_dta[tmr_id].status = TMR_IDLE;
}

void VTMR_Periodic(void)
{
    uint16_t tmr_id;
    for(tmr_id = 0; tmr_id < TOTAL_TIMERS; tmr_id++)
    {
        if(Tmr_dta[tmr_id].status == TMR_ACTIVE)
        {
            if(Tmr_dta[tmr_id].mS_counter > 0)
            {
                Tmr_dta[tmr_id].mS_counter--;
            }
            else
            {
                Tmr_dta[tmr_id].status = TMR_EXPIRED;
            }
        }
    }
    
}


