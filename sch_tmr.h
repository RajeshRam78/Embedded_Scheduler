/* 
 * File:   
 * Author: Rajesh R
 * Comments:
 * Revision history: 
 */

 
#ifndef VTMR_H
#define	VTMR_H

#include <stdint.h> /* call compiler specific type def header instead */ 

typedef enum status
{
    TMR_IDLE,
    TMR_ACTIVE,
    TMR_EXPIRED
}TMR_status_t;

typedef enum id
{
    TMRID_tch_windw,
    TOTAL_TIMERS /* Do not modify this , add your timers above always*/
}TMR_id_t;

typedef struct tmr
{
    uint32_t mS_counter;
    TMR_status_t status;
}Tmr_dta_t;

extern Tmr_dta_t Tmr_dta[TOTAL_TIMERS];
extern TMR_status_t TMR_get_status(TMR_id_t tmr_id);
extern void TMR_set_status(TMR_id_t tmr_id, TMR_status_t status);
extern void TMR_start(TMR_id_t tmr_id, uint32_t mS_counter);
extern void TMR_reset(TMR_id_t tmr_id);
extern void VTMR_Periodic(void);
#endif	

