/*
 * main.c
 *
 *  Created on: Jun 13, 2022
 *      Author: badrm
 */


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "SYSTICK_interface.h"
#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "RTOS_interface.h"


void Task1();
void Task2();
void Task3();

int main(){

	RCC_voidInitSysClock();
	/* enable clock on GPIOA */
	RCC_voidEnableClock(RCC_APB2, 2);
	/* set direction for pin0, pin1 and pin2 to output PP*/
	MGPIO_voidSetPinDirection(GPIOA,PIN0, OUTPUT_FREQ_2MHZ_PP);
	MGPIO_voidSetPinDirection(GPIOA,PIN1, OUTPUT_FREQ_2MHZ_PP);
	MGPIO_voidSetPinDirection(GPIOA,PIN2, OUTPUT_FREQ_2MHZ_PP);

	/* Create task1 that toggle GPIOA pin0 */
	SRTOS_voidCreateTask(0, 1000, 0, Task1);
	/* Create task2 that toggle GPIOA pin1 */
	SRTOS_voidCreateTask(1, 2000, 0, Task2);
	/* Create task3 that toggle GPIOA pin2 */
	SRTOS_voidCreateTask(2, 3000, 0, Task3);
	SRTOS_voidStart();
	while(1);
}


void Task1(){
	static u8 Local_u8State = 0;
	TOG_BIT(Local_u8State,0);
	MGPIO_voidSetPinValue(GPIOA,PIN0, Local_u8State);
}
void Task2(){
	static u8 Local_u8State = 0;
	TOG_BIT(Local_u8State,0);
	MGPIO_voidSetPinValue(GPIOA,PIN1, Local_u8State);
}
void Task3(){
	static u8 Local_u8State = 0;
	TOG_BIT(Local_u8State,0);
	MGPIO_voidSetPinValue(GPIOA,PIN2, Local_u8State);
}
