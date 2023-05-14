#ifndef SEVENSEGMENT_CFG_H
#define SEVENSEGMENT_CFG_H
#include "STD_Types.h"
#include "BIT_Math.h"
#include "DIO.h"
#include"DIO_prv.h"
/*This Value is configurable according to Number of Seven Segments*/
#define SSEG_Max_NumOfSSEG 9


typedef enum
{
	SSEG_enuSSEG0=0,
	//SSEG_enuSSEG1,
	SSEG_enuNumberOfSSEG
	
}SSEG_tenuSSEG;


typedef enum
{
	
	SSEG_enuCommonCathode,
	SSEG_enuCommonAnode
	
}SSEG_tenuSSEGMode;


typedef struct{
     u8  SSEG_Port;
	SSEG_tenuSSEGMode SSEG_ActiveStatus;
	
	}SSREG_strcfg_t;
	
const SSREG_strcfg_t SSREG_strcfg[SSEG_enuNumberOfSSEG];
#endif