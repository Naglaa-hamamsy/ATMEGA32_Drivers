#ifndef LCD_H
#define LCD_H
/*****************DEFINES*****************/

typedef enum
{
	LCD_enuOK,
	LCD_enuNOK
}LCD_enuErrorStatus;

void LCD_voidInit(void);
LCD_enuErrorStatus LCD_enuSendCommand(u8 Cpy_u8Command);
LCD_enuErrorStatus LCD_enuSendChar(u8 Cpy_u8Data);
LCD_enuErrorStatus LCD_enuSendString(char Add_pcString[]);
LCD_enuErrorStatus LCD_enuGoToXY(u8 Cpy_u8XPos, u8 Cpy_u8YPos);
LCD_enuErrorStatus LCD_enuSendInteger(u16 Cpy_u32Integer);
LCD_enuErrorStatus LCD_enuWriteSpecialChar(u8 Add_pu8Pattern[], u8 Cpy_u8BlockNum,u8 Cpy_u8XPos, u8 Cpy_u8YPos);



#endif