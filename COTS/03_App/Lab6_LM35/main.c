/*
 * LM35_Sensor.c
 *
 * Created: 09/02/2023 14:05:26
 * Author : naglaaa
 */ 

#include "BIT_Math.h"
#include "STD_Types.h"
#include "DIO.h"
#include "SevenSegment.h"
#include "ADC.h"
#include "LM35.h"


int main(void)
{ u16 temp=0;
	DIO_enuInit();
	ADC_enuInit();
    /* Replace with your application code */
    while (1) 
    {
		LM35_enuGetSensorReading(ADC_enuChannel_Single_2, &temp);
		
		SSEG_enuDisplay(temp);
		
    }
}

