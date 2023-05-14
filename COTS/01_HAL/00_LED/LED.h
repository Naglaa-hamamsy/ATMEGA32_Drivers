#ifndef LED_H
#define LED_H
/* LED Error Status Enum*/
#include "DIO.h"
typedef enum
{
	LED_enuOk=0,
    LED_enuInvalidPinNum
}LED_tenuErrorStatus;

LED_tenuErrorStatus LED_enuLedOn(DIO_tenuPins Cpy_enuPinNumber);
LED_tenuErrorStatus LED_enuLedOff(DIO_tenuPins Cpy_enuPinNumber);




#endif 