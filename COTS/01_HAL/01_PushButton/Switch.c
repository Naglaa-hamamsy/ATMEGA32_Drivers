/* Implementation of Get Switch Value Function*/
#include "Switch.h"
SWITCH_tenuErrorStatus SWITCH_enuGetSwitchVal(DIO_tenuPins Cpy_enuPinNumber, DIO_tenuPinValue *Add_penuPinValue)
{	DIO_tenuErrorStatus ReturnVal=0;
	SWITCH_tenuErrorStatus Local_enuSwitchErrorStatus=0;
	
		ReturnVal=DIO_enuGetPin(Cpy_enuPinNumber,Add_penuPinValue);
		if(ReturnVal==DIO_enuInvalidPinNum)
		{
			Local_enuSwitchErrorStatus=SWITCH_enuInvalidPin;
		}
		else if(ReturnVal==DIO_enuNullPtr)
		{
			Local_enuSwitchErrorStatus=SWITCH_enuNullPtr;
		}
		else
		{
		Local_enuSwitchErrorStatus=SWITCH_enuOk;
		}
	return Local_enuSwitchErrorStatus;
}