/*
 * TIMER_DRV.c
 *
 * Created: 27/02/2023 13:29:29
 * Author : naglaaa
 */ 

#include "STD_Types.h"
#include "BIT_Math.h"
#include "DIO.h"
#include "TIMER_prv.h"
#include "TIMER_Cfg.h"
#include "TIMER.h"
#include "util/delay.h"
int main(void)
{ u8 i=0;
	DIO_enuInit();
   TMR0Config_t cfg;
  cfg.TMR0_Prescaler =TMR0_PRESCALER_DIV_8;
   cfg.TMR0_Mode_Output = TMR0_MODE_OUTPUT_FPWM_CCST;
	TMR0_vidInitPostCompile( &cfg);
	
	//TMR0_vidInitPreCompile();
 int counter =5;
 int val=0 ,val2=0;
 TMR0_enuSetCompareValue(0);
    while (1) 
    {	
		
			SWITCH_enuGetSwitchVal(DIO_enuPin0,&val);
			_delay_ms(120);
			if(val == 0)
			{
				counter += 2;
					if(counter >= 255)
					{
						counter = 255;
					}
				TMR0_enuSetCompareValue(counter);
			}
			
			SWITCH_enuGetSwitchVal(DIO_enuPin1, &val2);
				_delay_ms(120);
			if(val2==0)
			{
				counter -= 2;
					if(counter <= 0)
					{
						counter = 0;
					}
				TMR0_enuSetCompareValue(counter);
			}
		}

		
		
		
    }


