/*
 * SPI.c
 *
 * Created: 06/04/2023 00:14:34
 * Author : naglaaa
 */ 

#include "STD_Types.h"
#include "BIT_Math.h"
#include "DIO_cfg.h"
#include "DIO.h"
#include "GlobalInterrubt.h"
#include "GlobalInterrupt_cfg.h"
#include "KPAD_cfg.h"
#include "KPAD.h"
#include "SPI_Cfg.h"
#include "SPI.h"
#include "avr/delay.h"


int main(void)
{ //static u8 data[5] = {1,2,3,4,5};
 //static u8 receive[5] = {0};
	 u8 data = 0;
	 u8 receive =0;
	DIO_enuInit();
	
  SPI_vidMasterInit();
  	GlobalInterupt_vidEnable();
  		//SPI_enuTransceiveBufferZeroCpyASynch(data, receive ,5 , NULL);
    while (1) 
    {
		KPAD_u8GetThePressedKey(&data);
		_delay_ms(50);
		SPI_enuTransceiveByteSynch(data,&receive);



    }
}

