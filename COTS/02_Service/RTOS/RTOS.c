#include "STD_Types.h"
#include "BIT_Math.h"
#include "TIMER.h"
#include "TIMER_Cfg.h"
#include "GlobalInterrubt.h"
#include "RTOS_Cfg.h"
#include "RTOS.h"


/*******************************************TYPES********************************************************/

static void voidScheduler(void);
/*********************************FUNCTIONS IMPLEMENTATION********************************************/
void Scheduler_vidStart(void)
{
		/*Set Call Back*/
	TMR0_enuRegisterCallback(voidScheduler,TMR0_COMP_MATCH_INTERRUPT);
		/*Initialize Timer 0 */
		TMR0_vidInitPreCompile();
		/*Set Compare Match Value According To Required Time*/
		TMR0_enuSetCompareValue(COMPARE_MATCH_VALUE);
		/*Enable Global Interrupt*/
		GlobalInterupt_vidEnable();
}
/*void Scheduler_vidCreateTask(u8 Cpy_u8Priority , u16 Cpy_u16Periodicity , TaskFunc_t Cpy_pvTaskFunc)
{
	Tasks[Cpy_u8Priority].Periodicity = Cpy_u16Periodicity;
	Tasks[Cpy_u8Priority].TaskFunc = Cpy_pvTaskFunc;
}
*/
static void voidScheduler(void)
{
	static u16 TickCounter = 0;
	u8 Counter =0;
	TickCounter += SYSTEM_TICK_TIME;
	for(Counter = 0 ; Counter < TASKS_NUM ; Counter++)
	{
		if(TickCounter % Tasks[Counter].Periodicity == 0)
		{
			if(Tasks[Counter].TaskFunc != NULL)
			{
			Tasks[Counter].TaskFunc();
			}
			else
			{
				/* Do Nothing */
			}
			
		}
		else
		{
			/* Do Nothing */
		}
	}
}