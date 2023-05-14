/*
 * LCD_Driver.c
 *
 * Created: 10/02/2023 14:30:00
 * Author : naglaaa
 */
#include "STD_Types.h"
#include "BIT_Math.h" 
#include <util/delay.h>
#include "DIO.h"
#include "LCD.h"
#include "LCD_cfg.h"



int main(void)
{   DIO_enuInit();
	LCD_voidInit();
	u8 x=0,y=0;
//	u16 integr=45678;
  
u8 customChar1[]= {
	0x00,
	0x07,
	0x05,
	0x07,
	0x01,
	0x02,
	0x04,
	0x08
};
u8 customChar2[] = {
	0x00,
	0x06,
	0x00,
	0x0F,
	0x09,
	0x0F,
	0x00,
	0x00
};
	LCD_enuWriteSpecialChar(customChar1,1,0,4);
	LCD_enuWriteSpecialChar(customChar2,2,0,3);
	LCD_enuGoToXY(0,2);
	LCD_enuSendChar('!');
	LCD_enuGoToXY(0,1);
	LCD_enuSendChar('!');
	LCD_enuGoToXY(0,0);
	LCD_enuSendChar('!');
	
	//LCD_enuGoToXY(x,y);
	//LCD_enuSendInteger(integr);
	//LCD_enuSendString("nonaa");

    while (1) 
    {
		/*LCD_enuSendString("nonaa");
		_delay_ms(500);
		y+=3;
		if(y>=16)
		{
			y=0;
		}
		LCD_enuSendCommand(DISPLAY_CLEAR);	
		LCD_enuGoToXY(x,y);
		*/
		
		
	
		
    }
}

