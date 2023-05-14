/* **************************************** */

/*DIO Interface File*/
/* **************************************** */
#ifndef DIO_H
#define DIO_H
#include "STD_types.h"
#define DIO_PORT_HIGH 0xff
#define DIO_PORT_LOW 0x00

typedef enum
{
	DIO_enuOk=0,
	DIO_enuNOK,
	DIO_enuNullPtr,
	DIO_enuInvalidPortNum,
	DIO_enuInvalidPinNum,
	DIO_enuInvalidPortVal
}DIO_tenuErrorStatus;

typedef enum
{
	DIO_enuPin0=0,
	DIO_enuPin1,
	DIO_enuPin2,
	DIO_enuPin3,
	DIO_enuPin4,
	DIO_enuPin5,
	DIO_enuPin6,
	DIO_enuPin7,
	DIO_enuPin8,
	DIO_enuPin9,
	DIO_enuPin10,
	DIO_enuPin11,
	DIO_enuPin12,
	DIO_enuPin13,
	DIO_enuPin14,
	DIO_enuPin15,
	DIO_enuPin16,
	DIO_enuPin17,
	DIO_enuPin18,
	DIO_enuPin19,
	DIO_enuPin20,
	DIO_enuPin21,
	DIO_enuPin22,
	DIO_enuPin23,
	DIO_enuPin24,
	DIO_enuPin25,
	DIO_enuPin26,
	DIO_enuPin27,
	DIO_enuPin28,
	DIO_enuPin29,
	DIO_enuPin30,
	DIO_enuPin31,
	DIO_enuNumberOfPins /*Will be 32*/
	
}DIO_tenuPins;

typedef enum
{
	DIO_enuLow=0,
	DIO_enuHigh
}DIO_tenuPinValue;

/* **************************************** */
/* DIO Initialization Function
 Input:Void
 Output: DIO_tenuErrorStatus to report error*/
 /* ***************************************** */
 
DIO_tenuErrorStatus DIO_enuInit(void);

/* **************************************** */
/* DIO SetPin Function
 Input:Pin number (Range from 0 to 31)  Make sure that user enters pin number from 0 to 31
 Output: DIO_tenuErrorStatus to report error */
 /* ***************************************** */
 
DIO_tenuErrorStatus DIO_enuSetPin(DIO_tenuPins Cpy_enuPinNumber);


/* **************************************** */
/* DIO Clear Pin Function
 Input:Pin number (Range from 0 to 31)  Make sure that user enters pin number from 0 to 31
 Output: DIO_tenuErrorStatus to report error*/
 /* ***************************************** */
 
DIO_tenuErrorStatus DIO_enuClearPin(DIO_tenuPins Cpy_enuPinNumber);

/* **************************************** */
/* DIO Get Pin Function
 Input:Pin number (Range from 0 to 31) Make sure that user enters pin number from 0 to 31
 Output: DIO_tenuErrorStatus to report error*/
/* there's a pointer as input , to return the value of pin needed*/
 /* ***************************************** */
 DIO_tenuErrorStatus DIO_enuClearPort(DIO_tenuPins Cpy_enuPinNumber);
 /* **************************************** */
/* DIO Clear Port value Function
 Input:Pin number (0 or 8 or 16 or 24 )  Make sure that user enters pin number from 0 to 31
 Output: DIO_tenuErrorStatus to report error*/
 /* ***************************************** */
 DIO_tenuErrorStatus DIO_enuSetPortVal(DIO_tenuPins Cpy_enuPinNumber, u8 Cpy_u8PortValue);
 /* **************************************** */
/* DIO Set Port value Function
 Input:Pin number (0 or 8 or 16 or 24 )  Make sure that user enters pin number from 0 to 31
 Output: DIO_tenuErrorStatus to report error*/
 /* ***************************************** */
 

 
DIO_tenuErrorStatus DIO_enuGetPin(DIO_tenuPins Cpy_enuPinNumber,DIO_tenuPinValue* Add_penuPinValue);





#endif /*DIO_H*/