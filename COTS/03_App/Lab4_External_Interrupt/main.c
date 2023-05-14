/*
 * External_Interrupt_Driver.c
 *
 * Created: 27/01/2023 10:25:08
 * Author : naglaaa
 */
#define F_CPU 8000000U
#include "util/delay.h" 
#include "DIO.h"
#include "DIO_prv.h"
#include "External_Interrupt.h"

//#include <avr/interrupt.h>
void ISR_INT0_APP (void);
void ISR_INT1_APP (void);
u8 counter=-1;
int main(void)
{	
	DIO_enuInit();
	GlobalInterupt_vidEnable();
    EXTI_vidInit();
	EXTI_SetCallBackFunc(ISR_INT0_APP);
	EXTI_SetCallBackFunc(ISR_INT1_APP);
    while (1) 
    {
    }
}
void ISR_INT0_APP(void)
{ counter++;
	SSEG_enuDisplay(counter);


	
}
	

void ISR_INT1_APP(void)
{ counter--;
SSEG_enuDisplay(counter);

	
}
