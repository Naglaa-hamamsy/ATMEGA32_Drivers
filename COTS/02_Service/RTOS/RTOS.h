#ifndef RTOS_H
#define RTOS_H
/*******************************
 **Description: 1- Timer Initialization
				2- Global Interrupt Enable
				3- Set Compare Value According To Required Time
				4- Set Call Back Function
				
 **Inputs : None
 **Outputs: None
 
*******************************/


typedef void(*TaskFunc_t)(void);
void Scheduler_vidStart(void);
//void Scheduler_vidCreateTask(u8 Cpy_u8Priority , u16 Cpy_u16Periodicity , TaskFunc_t Cpy_pvTaskFunc);


#endif