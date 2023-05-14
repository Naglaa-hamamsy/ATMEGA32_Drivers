/*
 * SPI_SLAVE.c
 *
 * Created: 06/04/2023 06:04:03
 * Author : naglaaa
 */ 


#include "STD_Types.h"
#include "BIT_Math.h"
#include "DIO_cfg.h"
#include "DIO.h"
#include "GlobalInterrubt.h"
#include "GlobalInterrupt_cfg.h"
#include "SevenSegment.h"
#include "SevenSegment_cfg.h"
#include "SPI_Cfg.h"
#include "SPI.h"
#include "avr/delay.h"
u8 receive[5] = {9};
void func(void)
{
	for(int i = 0 ;i < 5 ;i++)
	{
			SSEG_enuDisplay(receive[i]);
			_delay_ms(500);
	}
}

int main(void)
{// static u8 data[5] = {6,7,8,9,15};
	u8 data = 0;
	DIO_enuInit();
	SPI_vidSlaveInit();
	GlobalInterupt_vidEnable();
	
		//	SPI_enuTransceiveBufferZeroCpyASynch(data, receive ,5 , func);
	while (1)
	{
		
	SPI_enuTransceiveByteSynch(10,&data);
	SSEG_enuDisplay(data);

		

	}
}
