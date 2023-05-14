#include "STD_Types.h"
#include "BIT_Math.h"
#include <util/delay.h>
#include "DIO.h"
#include "LCD.h"
#include "LCD_cfg.h"
#include "LCD_prv.h"

void LCD_voidInit(void)
{
		/*Wait for more than 30 ms*/
		_delay_ms(40);
	/* Send Function Set Command : 2 lines , 5*8 Font size*/
		LCD_enuSendCommand(FUNCTION_SET_COMMAND);
		/*Display On/OFF Control: Display enable, Disable Cursor,
		 No Blink Cursor*/
		LCD_enuSendCommand(DISPLAY_CONTOL_COMMAND);
		/*Display Clear*/
		LCD_enuSendCommand(DISPLAY_CLEAR);
		/*Delay 5 ms*/
		_delay_ms(5);
		
		
}
LCD_enuErrorStatus LCD_enuSendCommand(u8 Cpy_u8Command)
{	
	LCD_enuErrorStatus Local_enuErrorStatus = LCD_enuOK;
	
	/* Set RS pin to Low for command*/
	DIO_enuClearPin(LCD_RS_PIN);
	/*Set R/W pin to low to Write*/
	DIO_enuClearPin(LCD_RW_PIN);
	/* Sending Command to LCD*/
	DIO_enuSetPortVal(LCD_DATA_PORT,Cpy_u8Command);
	
			/*Set Enable Pin */
			DIO_enuSetPin(LCD_E_PIN);
			_delay_ms(2);
			/*Clear Enable Pin */
			DIO_enuClearPin(LCD_E_PIN);
	//		LCD_enuSendCommand(ENTRY_MODE_SET);

	return Local_enuErrorStatus;
	
}
		
LCD_enuErrorStatus LCD_enuSendChar(u8 Cpy_u8Data)
{
		LCD_enuErrorStatus Local_enuErrorStatus = LCD_enuOK;
		
		/* Set RS pin to Low for Data*/
		DIO_enuSetPin(LCD_RS_PIN);
		/*Set R/W pin to low to Write*/
		DIO_enuClearPin(LCD_RW_PIN);
		/* Sending Command to LCD*/
		DIO_enuSetPortVal(LCD_DATA_PORT,Cpy_u8Data);
		
		/*Set Enable Pin */
		DIO_enuSetPin(LCD_E_PIN);
		_delay_ms(2);
		/*Clear Enable Pin */
		DIO_enuClearPin(LCD_E_PIN);

		return Local_enuErrorStatus;
		
}
LCD_enuErrorStatus LCD_enuSendString(char Add_pcString[])
{
	u8 Local_u8Counter=0;
	while( Add_pcString[Local_u8Counter]!='\0')
	{
		LCD_enuSendChar(Add_pcString[Local_u8Counter]);
		Local_u8Counter++;
	}
	return LCD_enuOK;
}
LCD_enuErrorStatus LCD_enuGoToXY(u8 Cpy_u8XPos, u8 Cpy_u8YPos)
{ 
	u8 Local_u8Address;
LCD_enuErrorStatus	Local_enuErrorStatus = LCD_enuOK ;
	if((Cpy_u8XPos >1) || (Cpy_u8YPos >15))
	{
		Local_enuErrorStatus = LCD_enuNOK;
	}
	else
	{
		switch(Cpy_u8XPos)
		{
			case 0: LCD_enuSendCommand(0x80 + Cpy_u8YPos);break;
			case 1: LCD_enuSendCommand(0xC0 + Cpy_u8YPos);break;
		}
		
	}
	return Local_enuErrorStatus;
}
LCD_enuErrorStatus LCD_enuSendInteger(u16 Cpy_u32Integer)
{ 
	LCD_enuErrorStatus Local_u8ErrorStatus = LCD_enuOK;
	
	u8 Remainder=1;
	u8 arr[5];
	s8 i=0;
	u8 ArrCounter=0;
	if(Cpy_u32Integer > 65535)
	{
		Local_u8ErrorStatus = LCD_enuNOK;
	}
	else
	{
		
		while(Cpy_u32Integer %10 !=0)
		{
		
			Remainder = Cpy_u32Integer % 10;
			arr[ArrCounter] =Remainder;
			Cpy_u32Integer /=10;
			ArrCounter++;
		}
		for(i=ArrCounter-1 ; i>=0 ; i--)
		{
			LCD_enuSendChar(arr[i] + '0');
		}
	}
	return Local_u8ErrorStatus;
	
}
LCD_enuErrorStatus LCD_enuWriteSpecialChar(u8 Add_pu8Pattern[], u8 Cpy_u8BlockNum , u8 Cpy_u8XPos, u8 Cpy_u8YPos)
{ LCD_enuErrorStatus	Local_u8ErrorStatus = LCD_enuOK;
	u8 CGRAMAddress=0;
	u8 Counter=0;
	if((Cpy_u8XPos > 1) || (Cpy_u8YPos >15))
	{
		Local_u8ErrorStatus = LCD_enuNOK;
	}
	else
	{
		
		/*Calculate CGRAM Address*/
		CGRAMAddress=Cpy_u8BlockNum*8;
		/*Send CGRAM Address to LCD with setting bit 6*/
		LCD_enuSendCommand( CGRAMAddress+ 64); /*In Order To Write In CGRAM */
		/*Write the pattern into CGRAM*/
		
		for(Counter=0;Counter<8;Counter++)
		{
			/*Save in CGRAM*/
			LCD_enuSendChar(Add_pu8Pattern[Counter]);
		}
		/* Display on DDRAM*/
		LCD_enuGoToXY(Cpy_u8XPos,Cpy_u8YPos);
		LCD_enuSendChar(Cpy_u8BlockNum);
	}
	return Local_u8ErrorStatus;
}