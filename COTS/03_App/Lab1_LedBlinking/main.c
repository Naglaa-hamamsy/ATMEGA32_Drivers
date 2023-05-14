/*
 * FirstDIO.c
 *
 * Created: 13/01/2023 16:19:18
 * Author : naglaaa
 */ 
#define F_CPU 8000000U
#include <util/delay.h>
#include "DIO.h"
#include "LED.h"
#include "Switch.h"



int main(void)
{ u8 LoopCounter=DIO_enuPin0;
  u8 SwitchOneValue=1;
  u8 SwitchTwoValue=1;
 DIO_enuInit();
/*
   1. PortA pins are output high for leds
   2. PortBPin0: high input(Pull up)to the first switch
   3. PortBPin1: high input(Pull up) to the second switch
   */
    while (1) 
    {
		if(SWITCH_enuGetSwitchVal(DIO_enuPin6,&SwitchOneValue)==SWITCH_enuOk)
		{ /*Pull up Switch*/
			if(SwitchOneValue==0)
			{ if(LoopCounter<8)
				{		
				if(DIO_enuSetPin(LoopCounter++)==DIO_enuOk);
				}
				
			}
		}
		if(SWITCH_enuGetSwitchVal(DIO_enuPin7,&SwitchOneValue)==SWITCH_enuOk)
		{ /*Pull up Switch*/
			if(SwitchOneValue==0)
			{ if(LoopCounter<8)
				{
				if(DIO_enuClearPin(LoopCounter--)==DIO_enuOk);
				}
				
			}
		}
		
		
	}
	return 0;

    }
 
		



