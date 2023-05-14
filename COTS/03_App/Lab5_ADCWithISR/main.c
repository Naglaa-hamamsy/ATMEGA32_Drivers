/*
 * ADC_DRIVER.c
 *
 * Created: 05/02/2023 17:25:42
 * Author : naglaaa
 */ 
#include "util/delay.h"
#include "DIO.h"
#include "SevenSegment.h"
#include "ADC.h"
#include "ADC_cfg.h"
#include "GlobalInterrubt.h"
#include "External_Interrupt.h"

void Display(void);
void Display_EXTI0(void);
 u16 Reading=0;
int main(void)
{	DIO_enuInit();
    ADC_enuInit();
	GlobalInterupt_vidEnable();
  EXTI_vidInit();
	EXTI_SetCallBackFunc(Display_EXTI0,0);
    /* Replace with your application code */
	//ADC_enuAutoTriggerConversion(ADC_enuChannel_Single_1,EXTI_REQ0_TRIGGER,&Reading,Display);

	

	
   while(1)
   {
		 
	  //  ADC_enuSelectChannel(ADC_enuChannel_Single_1);
		//ADC_enuStartConversion();
	//ADC_enuStartConversion_Synch (ADC_enuChannel_Single_1 ,&Reading);
	
		/*ADC_enuGetChannelReading(&Reading);
			
			Reading/=10;
			if(Reading>=99)
			{
				Reading=67;
			}
			SSEG_enuDisplay(Reading);*/

			
		//ADC_enuStartConversion_ASynch(ADC_enuChannel_Single_2,&Reading,Display);
				//ADC_enuStartConversion_ASynch(ADC_enuChannel_Single_1,&Reading,Display);
					ADC_enuAutoTriggerConversion(ADC_enuChannel_Single_1,EXTI_REQ0_TRIGGER,&Reading,Display);

   }
}
void Display(void)
{
	
	Reading/=10;
	if(Reading>=99)
	{
		Reading=99;
	}
	SSEG_enuDisplay(Reading);

}
void Display_EXTI0(void)
{
	LED_enuLedOn(0);
	_delay_ms(50);
	LED_enuLedOff(0);
}
