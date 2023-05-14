/*
 * TIMER_DRV.c
 *
 * Created: 27/02/2023 13:29:29
 * Author : naglaaa
 */ 

#include "STD_Types.h"
#include "BIT_Math.h"
#include "DIO.h"
#include "GlobalInterrubt.h"
#include "TIMER_prv.h"
#include "TIMER_Cfg.h"
#include "TIMER.h"
#include "util/delay.h"

void ICU_HW (void);

	u8 Preload = 224;
int main(void)
{ u8 i=0;
	DIO_enuInit();
	GlobalInterupt_vidEnable();
   TMR0Config_t cfg;
  cfg.TMR0_Prescaler =TMR0_PRESCALER_DIV_8;
   cfg.TMR0_Mode_Output = TMR0_MODE_NORMAL;

	TMR0_vidInitPostCompile( &cfg);
	   TMR0_enuSetTimerValue(Preload);
	TMR0_enuRegisterCallback(ICU_HW , TMR0_OVF_INTERRUPT);
	
	//TMR0_vidInitPreCompile();

	

    while (1) 
    {	
		
		
		
		
    }


}
void ICU_HW (void)
{
	static counter = 0;
	static led_state = 0;
	counter++;
	if(counter == 1954)
	{
		led_state ^=1;
		if(led_state == 1)
		{
		LED_enuLedOn(DIO_enuPin0);

		}
		else
		{
			LED_enuLedOff(DIO_enuPin0);
		}
		counter = 0;
		Preload = 224;
	}
	
			
}