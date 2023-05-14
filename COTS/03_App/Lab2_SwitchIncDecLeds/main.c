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
{ s8 LoopCounter=DIO_enuPin0;
  DIO_tenuPinValue SwitchOneValue=1;
  DIO_tenuPinValue SwitchTwoValue=1;
   
   DIO_enuInit();
/*
   1. PortA pins are output high for leds
   2. PortBPin0: high input(Pull up)to the first switch
   3. PortBPin1: high input(Pull up) to the second switch
   */
   
    while (1) 
    { 	_delay_ms(100);
		if(SWITCH_enuGetSwitchVal(DIO_enuPin8,&SwitchOneValue)==SWITCH_enuOk)
		{ /*Pull up Switch*/
			if(SwitchOneValue==0)
			{ if(LoopCounter>=0 && LoopCounter<8)
				{		
				if(DIO_enuSetPin(LoopCounter)==DIO_enuOk);
			
				 }
			
				LoopCounter++;
			}
		
				//_delay_ms(300);
		}
			_delay_ms(100);
		if(SWITCH_enuGetSwitchVal(DIO_enuPin9,&SwitchTwoValue)==SWITCH_enuOk)
		{ /*Pull up Switch*/ 
			
			if(SwitchTwoValue==0)
			   { LoopCounter--;
			    if(LoopCounter>=0 && LoopCounter<8)
				{
				if(DIO_enuClearPin(LoopCounter)==DIO_enuOk)
				  { 
				//	_delay_ms(300);
				
				  }
				}
				
			}
			
		}
				//LoopCounter++;
			//	_delay_ms(300);
		  
		
	}
	return 0;

    }
 
		
