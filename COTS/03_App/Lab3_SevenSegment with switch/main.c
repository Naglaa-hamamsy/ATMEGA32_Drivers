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
#include "switch.h"
#include "SevenSegment.h"
#include "util/delay.h"

	
	
int main(void)
{ u8 LocalCounter=0,Value;
	DIO_enuInit();
	while(1)
	
	{
		SWITCH_enuGetSwitchVal(DIO_enuPin16,&Value);
		if(Value==0)
		{
			SSEG_enuDisplay(LocalCounter);
			_delay_ms(500);
			LocalCounter++;
		}
	}
		
	
	return 0;
}
