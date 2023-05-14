#include "STD_Types.h"
#include "BIT_Math.h"
#include "LED.h"
#include "LED_prv.h"
LED_tenuErrorStatus LED_enuLedOn(DIO_tenuPins Cpy_enuPinNumber)
{
		DIO_tenuErrorStatus ReturnVal=0;
		LED_tenuErrorStatus Loc_enuLedErrorStatus = 0;
		ReturnVal=DIO_enuSetPin(Cpy_enuPinNumber);
		if(ReturnVal!=DIO_enuOk)
		{
			Loc_enuLedErrorStatus =LED_enuInvalidPinNum;
		}
		else 
		Loc_enuLedErrorStatus =LED_enuOk;
	return Loc_enuLedErrorStatus;
}


LED_tenuErrorStatus LED_enuLedOff(DIO_tenuPins Cpy_enuPinNumber)
{
		DIO_tenuErrorStatus ReturnVal=0;
		LED_tenuErrorStatus Loc_enuLedErrorStatus = 0;
		ReturnVal=DIO_enuClearPin(Cpy_enuPinNumber);
		if(ReturnVal!=DIO_enuOk)
		{
			Loc_enuLedErrorStatus =LED_enuInvalidPinNum;
		}
		else 
		Loc_enuLedErrorStatus =LED_enuOk;
	return Loc_enuLedErrorStatus;
}