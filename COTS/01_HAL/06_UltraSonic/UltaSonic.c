#include "STD_Types.h"
#include "BIT_Math.h"
#include "DIO_cfg.h"
#include "DIO.h"
#include "TIMER1_Cfg.h"
#include "TIMER1.h"
#include "TIMER1_prv.h"
#include "UltraSonic_Cfg.h"
#include "UltraSonic.h"
#include "util/delay.h"

static void ULTRASONIC_Trigger(void);
static void ULTRASONIC_init(void);
static void ULTRASONIC_Processing(void);
static u16 TIMER_Reading = 0;
extern Num_Of_OverFlows;
void ULTRASONIC_Trigger(void)
{
		DIO_enuSetPin(ULTRASONIC_TRIGGER_PIN);
		_delay_ms(15);
		DIO_enuClearPin(ULTRASONIC_TRIGGER_PIN);

}
 void ULTRASONIC_init(void)
{
		/*Timer 1 Initialization */
		/* Set Prescaler with 1*/
		TMR1_init();
		/*Set ICU Trigger At Rising Edge*/
		TMR1_ICU_INIT();
		/*Set NotifyFunc to TIMER1_ICU*/
		TMR1_ICU_SetCallBack(ULTRASONIC_Processing); 
	
}
 void ULTRASONIC_Processing(void)
{
	static u8 counter = 0;
	static u16 Num_Of_OVF =0;
	//	TIMER_Reading = 0;
	counter ++;
	/*Detect Rising Edge*/
	if(counter == 1)
	{
		
		/*Clear Timer To Start Counting*/
		TMR1_enuSetTimerValue(TMR1_CLEAR_TCTN1);
		TMR1_ICU_SetEdge(ICU_EDGE_FALLING);
	}
	else if(counter == 2)
	{
		TIMER_Reading = TMR1_ICU_u16GetICR() + (Num_Of_OverFlows * Num_Of_OVF);
			TMR1_ICU_SetEdge(ICU_EDGE_RISING);
			counter = 0;
		
		

	}
}
u16 ULTRASONIC_GetDistance(void)
{
	ULTRASONIC_init();
	ULTRASONIC_Trigger();
	while(TIMER_Reading == 0);
	return TIMER_Reading/466.47;
}