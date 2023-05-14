#ifndef KPAD_CFG_H
#define KPAD_CFG_H
#include "DIO_prv.h"
#include "KPAD_prv.h"
#define KPAD_4x3 1
#define KPAD_4x4 0
#define KPAD_SIZE KPAD_4x4
#define NumberOfRows 4
#if KPAD_SIZE==KPAD_4x4
#define NumberOfColomns 4
#else
#define NumberOfColomns 3
#endif

#define KPAD_PORT DIO_PORTA
#define Not_Pressed 100
extern u8 KpadArray[NumberOfRows][NumberOfColomns];
typedef struct
{
	u8 ColPin;
	u8 ColDirection;
}KPAD_strColomnsConfig_t;

typedef struct
{
	u8 RowPin;
	u8 RowDirection;
	
}KPAD_strRowsConfig_t;

extern const KPAD_strColomnsConfig_t KPAD_strColomnsConfig[NumberOfColomns];
extern const KPAD_strRowsConfig_t KPAD_strRowsConfig[NumberOfRows];


#endif