/*
 * UltraSonic_DRVR.c
 *
 * Created: 10/03/2023 14:49:52
 * Author : naglaaa
 */ 
#include "STD_Types.h"
#include "BIT_Math.h"
#include "DIO_cfg.h"
#include "DIO.h"
#include "DIO_prv.h"
#include "GlobalInterrubt.h"
#include "LCD.h"
#include "LCD_cfg.h"
#include "util/delay.h"
int main(void)
{ 
	u16 Distance = 0;
	DIO_enuInit();
	LCD_voidInit();
	GlobalInterupt_vidEnable();
    while (1) 
    {	
			Distance = ULTRASONIC_GetDistance();
			LCD_enuGoToXY(0,0);
			LCD_enuSendString("Distance= ");
			
			LCD_enuGoToXY(1,0);
			LCD_enuSendInteger(Distance);
			_delay_ms(300);
			LCD_enuSendCommand(DISPLAY_CLEAR);
    }
}

