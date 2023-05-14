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
	u8 xBall=0, yBall=3;
	u8 xStickLeft=0, yStickLeft=0;
	u8 xStickRight=0 ,yStickRight=15;
	u8 RightCounter=0,LeftCounter=0;
	u8 x=0,y=0;
	u8 RetLeft=1, RetRight=1;

	u8 Stick[] = {
		0x01,
		0x01,
		0x01,
		0x01,
		0x01,
		0x01,
		0x01,
		0x01
	};
	u8 Ball[] = {
	 0x00,
	 0x0E,
	 0x11,
	 0x11,
	 0x11,
	 0x0E,
	 0x00,
	 0x00
	};
	u8 flag=0;
	u8 Score1=0,Score2=0;
	u8 MaxScore=3;
    while (1) 
    {
		while((LeftCounter < MaxScore) && (RightCounter<MaxScore))
		{
			
		/*Display left stick on LCD*/
		LCD_enuWriteSpecialChar(Stick,0,xStickLeft,yStickLeft);
		/*Display right stick on LCD*/
		LCD_enuWriteSpecialChar(Stick,1,xStickRight,yStickRight);
		/*Display Left counter */
		LCD_enuGoToXY(0,2);
		LCD_enuSendInteger(LeftCounter);
		/*Display right counter */
		LCD_enuGoToXY(0,13);
		LCD_enuSendInteger(RightCounter);
		/*Display Ball on LCD*/
		LCD_enuWriteSpecialChar(Ball,2,xBall,yBall);
		_delay_ms(150);
		/*Movement of the ball randomly*/
		
		if((yBall<=yStickRight) && (yBall>=yStickLeft) && (flag==0))
		{
			if(yBall == yStickRight)
			{
				flag=1;
			}				
			if(xBall == 0)
			{
				xBall=1;
				yBall++;
				LCD_enuSendCommand(DISPLAY_CLEAR);		
			}
			else
			{
				xBall=0;
				yBall++;
				LCD_enuSendCommand(DISPLAY_CLEAR);
			}
			/*Case One*/
			if((yBall == yStickRight) && (xBall !=xStickRight))
			{
				
				LeftCounter ++;
			
			}
			else
			{
				/*Do Nothing*/
			}
			
		}
		//yBall<=yStickRight && yBall >= yStickLeft &&
		else if( flag==1)
		{
			if(yBall==yStickLeft)
			{
				flag=0;
			}
			
			else if(xBall == 0)
			{	
				yBall--;
				xBall=1;
				LCD_enuSendCommand(DISPLAY_CLEAR);
				
			}
			else
			{
				yBall--;
				xBall=0;
				LCD_enuSendCommand(DISPLAY_CLEAR);				
			}
			if((yBall == yStickLeft) && (xBall !=xStickLeft) &&(flag==0))
			{
				RightCounter++;
		
			}
			else
			{
				
			}
				
		
		
		}
		
			
		
		
		/*Get the reading of right stick switch*/
		SWITCH_enuGetSwitchVal(DIO_enuPin16, &RetRight);
		if(RetRight == 0)
		{
			if(xStickRight == 0)
			{
				xStickRight = 1;
				LCD_enuSendCommand(DISPLAY_CLEAR);
			}
			else
			{
				xStickRight = 0;
				LCD_enuSendCommand(DISPLAY_CLEAR);
			}
		}

		
		/*Get the reading of left stick switch*/
		SWITCH_enuGetSwitchVal(DIO_enuPin17, &RetLeft);
		if(RetLeft == 0)
		{
			if(xStickLeft == 0)
			{
				xStickLeft = 1;
				LCD_enuSendCommand(DISPLAY_CLEAR);
			}
			else
			{
				xStickLeft = 0;
				LCD_enuSendCommand(DISPLAY_CLEAR);
			}
			
		}
		
		
		
		}
		
		if(RightCounter > LeftCounter)
		{
			LCD_enuSendCommand(DISPLAY_CLEAR);
			LCD_enuGoToXY(0,0);
			LCD_enuSendString(" Player Two Wins ");
		
				_delay_ms(1000);
		}
		else if (RightCounter < LeftCounter)
		{
			LCD_enuSendCommand(DISPLAY_CLEAR);
			LCD_enuGoToXY(0,0);
				LCD_enuSendString("Player One Wins ");
			_delay_ms(1000);
		}
		else
		{
			LCD_enuSendCommand(DISPLAY_CLEAR);
			LCD_enuGoToXY(0,0);
			LCD_enuSendString("Equal Score!! ");
				_delay_ms(1000);
			
		}
	
    
		}

		}