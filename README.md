# RTOS Scheduler (STM32 Microcontroller Based)
- Real-Time Operating System (RTOS) Based On STM32 Microcontroller.
- Toggling 3 LEDs as a simple test for the scheduler.
# Table Of Contents
- [General Info](#general-info)
- [Technologies and Hardware](#Technologies-and-Hardware)
- [Configurations](#configurations)
# General Info
- This project implements RTOS scheduler that can be used for scheduling multiple tasks allowing deterministic execution pattern so we can build real-time operating system.
- Each task is assigned a periodicity that can be used to make periodic execution of this task.
- Each task is assigned First Delay parameter too, this parameter can be used to organize our operating system so that we can control CPU Load.
# Technologies and Hardware
- C language.
- STM32 Microcontroller is used.
- 3 Different LEDs (For basic test).
# Configurations
###### RTOS_config.h file is used to configure the system.
- NUMBER_OF_TASKS Determine how many tasks in system.
- SRTOS_PRIODIC_TICKS Set periodic time for OS in Microseconds.
- Note that: System is configured as 1 tick = 1 microsecond.