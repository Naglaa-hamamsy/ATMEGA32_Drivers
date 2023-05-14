/*
 * main.c
 *
 * Created: 21/01/2023 13:06:42
 *  Author: naglaaa
 */ 
#define F_CPU 8000000U
#include "STD_Types.h"
#include "BIT_Math.h"
#include "DIO.h"
#include "SevenSegment.h"
#include "util/delay.h"

	
	
int main(void)
{ 
	DIO_enuInit();
	while(1)
	
	{
		for(u8 loopCounter=95;loopCounter<101;loopCounter++)
		
		{
			if(SSEG_enuDisplay(loopCounter)!=SSEG_enuOk)
			{
				LED_enuLedOn(DIO_enuPin16);
				_delay_ms(1000);
				LED_enuLedOff(DIO_enuPin16);
				
			}
			else
			
			_delay_ms(1000);
		}
		
	}
	return 0;
}
