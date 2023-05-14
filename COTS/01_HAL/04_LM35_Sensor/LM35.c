#include "STD_Types.h"
#include "BIT_Math.h"
#include "ADC.h"
#include "ADC_cfg.h"
#include "LM35.h"

LM35_tenuErrorStatus LM35_enuGetSensorReading(u8 Cpy_enuChannel,u16 *Add_pu16Reading)
{ 
	LM35_tenuErrorStatus Local_enuErrorStatus= LM35_enuOK;
	u16 MilliVolt=0;
	u16 Temp=0;
	
	if(Add_pu16Reading == NULL)
	{
		Local_enuErrorStatus = LM35_enuNullPtr;
	}
	else
	{
		
		ADC_enuStartConversion_Synch(Cpy_enuChannel , Add_pu16Reading);
	
		if( LEFT_ADJUST == ENABLE)
		{		
			MilliVolt = ((u32)*Add_pu16Reading * 5000UL)/256UL;
		}
		else if ( RIGHT_ADJUST == ENABLE)
		{
			MilliVolt = ((u32)*Add_pu16Reading * 5000UL)/1024UL;
		}
	}
	*Add_pu16Reading = MilliVolt/10;
	return Local_enuErrorStatus;
}