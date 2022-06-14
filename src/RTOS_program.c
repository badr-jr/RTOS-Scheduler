/**********************************************************************/
/* Author			: Badr Mohamed									  */
/* Date				: 6 June 2022									  */
/* Version 			: V01											  */
/**********************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "RTOS_interface.h"
#include "RTOS_config.h"
#include "RTOS_private.h"


#include "SYSTICK_interface.h"

/* Start RTOS based on Periodic time determined in RTOS_config.h file */
void SRTOS_voidStart(void)
{
    MSTK_voidInit();
    /* Execute scheduler function ever periodic interval based on RTOS_config.h file */
    MSTK_voidSetIntervalPeriodic(SRTOS_PRIODIC_TICKS, Scheduler);
}
/* Create Task by giving ID (From 0 to SRTOS_PRIODIC_TICKS determined in RTOS_config.h), periodicity
 * First delay and function to be executed for this task
 */
void SRTOS_voidCreateTask(u16 Copy_u16ID ,u16 Copy_u16Priodicity , u16 Copy_u16FirstDelay , void(*Fptr)(void))
{
    SRTOS_Task[Copy_u16ID].u16Priodicity = Copy_u16Priodicity;
    SRTOS_Task[Copy_u16ID].FunctionPtr = Fptr;
    SRTOS_Task[Copy_u16ID].u16FirstDelay = Copy_u16FirstDelay;
    SRTOS_Task[Copy_u16ID].u8State = READY;
}
/* turn task into Suspension state */
void SRTOS_voidSuspendTask(u16 Copy_u16ID)
{
    SRTOS_Task[Copy_u16ID].u8State = SUSPENSION;
}
/* turn task into ready state */
void SRTOS_voidResumeTask(u16 Copy_u16ID)
{
    SRTOS_Task[Copy_u16ID].u8State = READY;
}
/* delete task */
void SRTOS_voidDeleteTask(u16 Copy_u16ID)
{
    SRTOS_Task[Copy_u16ID].FunctionPtr = NULL;
}
