#include "STD_Types.h"
#include "RTOS_Cfg.h"
#include "RTOS.h"

extern void LED1 (void);
extern void LED2(void);

	/*Note That Index Of Task Is It's PRIORITY*/
const Task_t Tasks[TASKS_NUM] =
	{
		[LEDTASK1] =
		{ 
			.Periodicity = 1000,
			.TaskFunc = LED1
		
		},
		
		[LEDTASK2] =
		{
			.Periodicity = 2000,
			.TaskFunc = LED2
			
		}
		
		
  };