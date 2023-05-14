/*
 * ADC_DRIVER.c
 *
 * Created: 05/02/2023 17:25:42
 * Author : naglaaa
 */ 
#include "util/delay.h"
#include "DIO.h"
#include "SevenSegment.h"
#include "ADC_cfg.h"
#include "ADC.h"
#include "GlobalInterrubt.h"


 u16 Reading=0;
 u16 Temp=0;
 u16 millivolt=0;
 u16 ChainResults [3] = {0};
	 
u8 ChainSize = 3;
u8 ChainChannels [3] = {ADC_enuChannel_Single_0, ADC_enuChannel_Single_1, ADC_enuChannel_Single_2};
	void ADC_Chaining (void);
int main(void)
{	DIO_enuInit();
    ADC_enuInit();
	GlobalInterupt_vidEnable();
  
   ADC_CHAIN_t chain1= {ChainSize, ChainChannels, ChainResults ,ADC_Chaining}; 
		 ADC_enuStartChainConverstion(&chain1);	
   while(1)
   {
 

   }
}


void ADC_Chaining (void)
{
	int i;
	for(i=0;i<ChainSize;i++)
	{
		millivolt = ((u32)ChainResults[i] *5000UL)/1024UL;
			Temp=millivolt/10;
			if(Temp>=99)
			{
				Temp=99;
			}
			
			SSEG_enuDisplay(Temp);
			_delay_ms(800);
	}
	
}
	
