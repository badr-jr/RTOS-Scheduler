/**********************************************************************/
/* Author			: Badr Mohamed									  */
/* Date				: 6 June 2022									  */
/* Version 			: V01											  */
/**********************************************************************/

#ifndef RTOS_INTERFACE_H
#define RTOS_INTERFACE_H

/* Start RTOS based on Periodic time determined in RTOS_config.h file */
void SRTOS_voidStart(void);
/* Create Task by giving ID (From 0 to SRTOS_PRIODIC_TICKS determined in RTOS_config.h), periodicity
 * First delay and function to be executed for this task
 */
void SRTOS_voidCreateTask(u16 Copy_u16ID ,u16 Copy_u16Priodicity , u16 Copy_u16FirstDelay , void(*Fptr)(void));
/* turn task into Suspension state */
void SRTOS_voidSuspendTask(u16 Copy_u16ID);
/* turn task into ready state */
void SRTOS_voidResumeTask(u16 Copy_u16ID);
/* delete task */
void SRTOS_voidDeleteTask(u16 Copy_u16ID);
#endif
