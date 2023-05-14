#ifndef SWITCH_H
#define SWITCH_H

#include "DIO.h"
/* Error status of switch*/
typedef enum
{
	SWITCH_enuOk=0,
	SWITCH_enuInvalidPin,
	SWITCH_enuNullPtr
}SWITCH_tenuErrorStatus;

/* ********************** */
/* Get Switch Value Function 
Input: Pin Number , Pointer to put the wanted value in
Output: SWITCH_enuErrorStatus */
/* ********************** */
SWITCH_tenuErrorStatus SWITCH_enuGetSwitchVal(DIO_tenuPins Cpy_enuPinNumber, DIO_tenuPinValue *Add_penuPinValue);

#endif