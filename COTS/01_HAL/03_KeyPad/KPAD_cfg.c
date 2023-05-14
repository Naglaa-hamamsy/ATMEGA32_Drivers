#include "DIO.h"
#include "DIO_cfg.h"
#include "KPAD_cfg.h"
 u8 KpadArray[NumberOfRows][NumberOfColomns]={
	{1,2,3,15},
	{4,5,6,16},
	{7,8,9,17},
	{10,11,12,14}
};
const KPAD_strRowsConfig_t KPAD_strRowsConfig[NumberOfRows]=
{
		{
			.RowPin=DIO_enuPin4,
			.RowDirection=DIO_DIR_INPUT
		},
		
		{
			.RowPin=DIO_enuPin5,
			.RowDirection=DIO_DIR_INPUT

		},
		
		{
			.RowPin=DIO_enuPin6,
			.RowDirection=DIO_DIR_INPUT
		},
		
		{
			.RowPin=DIO_enuPin7,
			.RowDirection=DIO_DIR_INPUT
		}
		
	
		//{DIO_enuPin4,DIO_DIR_INPUT},{DIO_enuPin5,DIO_DIR_INPUT},{DIO_enuPin6,DIO_DIR_INPUT},{DIO_enuPin7,DIO_DIR_INPUT}
	
	
};

const KPAD_strColomnsConfig_t KPAD_strColomnsConfig[NumberOfColomns]=
{
	
		
			{
				.ColPin=DIO_enuPin3,
				.ColDirection=DIO_DIR_OUTPUT
			},		
						 
			{					 
				.ColPin=DIO_enuPin2, 
				.ColDirection=DIO_DIR_OUTPUT
							 
			},	
						 
			{				 
				.ColPin=DIO_enuPin1,  
				.ColDirection=DIO_DIR_OUTPUT
			},		
					 
			{				 
				.ColPin=DIO_enuPin0, 
				.ColDirection=DIO_DIR_OUTPUT
			}						  
			
};