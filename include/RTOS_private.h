/**********************************************************************/
/* Author			: Badr Mohamed									  */
/* Date				: 6 June 2022									  */
/* Version 			: V01											  */
/**********************************************************************/

#ifndef RTOS_PRIVATE_H
#define RTOS_PRIVATE_H

#define NULL        ((void*)0)

/* Task States */
enum
{
   SUSPENSION = 0, 
   READY = 1,
};

/* Task members */
typedef struct
{
    u16 u16Priodicity;
    u8  u8State;
    u16 u16FirstDelay;
    void (*FunctionPtr)(void);
} Task;

/* Array of tasks based on num of tasks in config */
static Task SRTOS_Task[NUMBER_OF_TASKS]={NULL};

/* Scheduler to determine which task to be executed based on priodicity and delay time */
void Scheduler(void)
{
    u8 i;
    /* Loop on each task every OS Periodic ticks */
    for(i=0 ; i<NUMBER_OF_TASKS ; i++)
    {
        /* check if task state is ready and assigned a function to be executed */
        if( (SRTOS_Task[i].u8State == READY) && (SRTOS_Task[i].FunctionPtr != NULL) )
        {
            /* check if delay time is 0 so it can be executed every periodic ticks */
            if(SRTOS_Task[i].u16FirstDelay == 0)
            {
                /* in case first delay is 0 for the first time we can use this variable as copy of periodicity so we can
                    know if the task gets its turn in execution */
                SRTOS_Task[i].u16FirstDelay = SRTOS_Task[i].u16Priodicity-1;
                /* execute task function */
                SRTOS_Task[i].FunctionPtr();
            }
            else
            {
                /* decrease delay by 1 till it reaches 0 so it can be executed */
                SRTOS_Task[i].u16FirstDelay--;
            }
        }
        else
        {
            /* No function recognized or state is suspended */
        }
    }

}

#endif
