/*
 * KeyPad_Driver.c
 *
 * Created: 29/01/2023 01:32:01
 * Author : naglaaa
 */ 
#define F_CPU 8000000U
#include "STD_Types.h"
#include "util/delay.h"
#include "SevenSegment.h"


int main(void)
{ u8 pressed;
	DIO_enuInit();
	
    
    while (1) 
    { 
	pressed=KPAD_u8GetThePressedKey();
		if(SSEG_enuDisplay(pressed)==SSEG_enuOk);
		
    }
}

