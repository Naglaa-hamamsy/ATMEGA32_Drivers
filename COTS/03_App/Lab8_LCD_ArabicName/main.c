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
	u8 Return_Value=1;

  u8 FirstChar[] = {
	 0x00,
	 0x04,
	 0x01,
	 0x01,
	 0x1F,
	 0x00,
	 0x00,
	 0x00
 };
 u8 SecondChar[] = {
	 0x00,
	 0x00,
	 0x07,
	 0x01,
	 0x1F,
	 0x00,
	 0x02,
	 0x00
 };
 u8 ThirdChar[] = {
	 0x00,
	 0x11,
	 0x0A,
	 0x04,
	 0x0A,
	 0x1F,
	 0x00,
	 0x00
 };
 u8 ForthChar[] = {
	 0x00,
	 0x00,
	 0x07,
	 0x04,
	 0x07,
	 0x01,
	 0x0F,
	 0x00
 };

	/*LCD_enuWriteSpecialChar(customChar1,1,0,4);
	LCD_enuWriteSpecialChar(customChar2,2,0,3);
	LCD_enuGoToXY(0,2);
	LCD_enuSendChar('!');
	LCD_enuGoToXY(0,1);
	LCD_enuSendChar('!');
	LCD_enuGoToXY(0,0);
	LCD_enuSendChar('!');*/
	u8 Ret1=1;
	u8 Ret2=1;
	u8 Ret3=1;
	u8 Ret4=1;
	LCD_enuSendCommand(DISPLAY_CLEAR);
	LCD_enuWriteSpecialChar(FirstChar,0,x,y+3);
	LCD_enuWriteSpecialChar(SecondChar,1,x,y+2);
	LCD_enuWriteSpecialChar(ThirdChar,2,x,y+1);
	LCD_enuWriteSpecialChar(ForthChar,3,x,y);
	_delay_ms(700);
	
    while (1) 
    {
		/*right operation*/
			_delay_ms(50);
		SWITCH_enuGetSwitchVal(DIO_enuPin16,&Ret1); 
			if(Ret1 == 0)
			{
				
				if(y<12)
				{
					y+=2;
					LCD_enuSendCommand(DISPLAY_CLEAR);
					LCD_enuWriteSpecialChar(FirstChar,0,x,y+3);
					LCD_enuWriteSpecialChar(SecondChar,1,x,y+2);
					LCD_enuWriteSpecialChar(ThirdChar,2,x,y+1);
					LCD_enuWriteSpecialChar(ForthChar,3,x,y);
						_delay_ms(200);
					
				}
				else
				{
					//	Return_Value=1;
				}
			}
			else
			{
				/*Do Nothing*/
			}
		
		/*LEFT SHIFT*/
			_delay_ms(50);
		SWITCH_enuGetSwitchVal(DIO_enuPin17,&Ret2);
		if(Ret2 == 0)
		{
			 if(y-3>2)
			 {	  y=y-2;;
				 LCD_enuSendCommand(DISPLAY_CLEAR);
				LCD_enuWriteSpecialChar(FirstChar,0,x,y);
				LCD_enuWriteSpecialChar(SecondChar,1,x,y-1);
				LCD_enuWriteSpecialChar(ThirdChar,2,x,y-2);
				LCD_enuWriteSpecialChar(ForthChar,3,x,y-3);
				_delay_ms(200);
				
			 }
			 else
			 {
				// Return_Value=1;
			 }
		}
		else
		{
			/*Do Nothing*/
		}
		
		
		
		/*Upper shift tested*/
		_delay_ms(50);
		SWITCH_enuGetSwitchVal(DIO_enuPin18,&Ret3);
		if(Ret3 == 0)
		{
			if(x>0)
			{
				x--;
				LCD_enuSendCommand(DISPLAY_CLEAR);
				LCD_enuWriteSpecialChar(FirstChar,0,x,y+3);
				LCD_enuWriteSpecialChar(SecondChar,1,x,y+2);
				LCD_enuWriteSpecialChar(ThirdChar,2,x,y+1);
				LCD_enuWriteSpecialChar(ForthChar,3,x,y);
				_delay_ms(200);
				
			}
			
			else
			{
			//	Return_Value=1;
				
			}
			
		}
		else
		{
			/*Do Nothing*/
		}
		
		
		
		/* DOWN SHIFT*/
		_delay_ms(50);
			SWITCH_enuGetSwitchVal(DIO_enuPin19,&Ret4); 
		if(Ret4 == 0)
		{	
			if(x<1)
			{ 
				x++;
				LCD_enuSendCommand(DISPLAY_CLEAR);
				LCD_enuWriteSpecialChar(FirstChar,0,x,y+3);
				LCD_enuWriteSpecialChar(SecondChar,1,x,y+2);
				LCD_enuWriteSpecialChar(ThirdChar,2,x,y+1);
				LCD_enuWriteSpecialChar(ForthChar,3,x,y);
				_delay_ms(700);
				
			}
				
			else
			{
			//		Return_Value=1;
				
			}
		}
		else
		{
			/*Do Nothing*/
		}
		
		
		
	
		
		
	
		
    }
}

