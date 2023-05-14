#include "STD_Types.h"
#include "BIT_Math.h"
#include "SevenSegment_cfg.h"
#include "SevenSegment_cfg.h"
#include "SevenSegment.h"
u8 SevenSegment_LookUp[10] = {
	[0] = 0b0111111,
	[1] = 0b0000110,
	[2] = 0b1011011,
	[3] = 0b1001111,
	[4] = 0b1100110,
	[5] = 0b1101101,
	[6] = 0b1111101,
	[7] = 0b0000111,
	[8] = 0b1111111,
	[9] = 0b1101111
	
};
		
SSEG_tenuErrorStatus SSEG_enuDisplay(u8 Cpy_u8SSEGValue)

{
	 SSEG_tenuErrorStatus Local_enuErrorStatus=SSEG_enuOk;
	 u8 LocalCounter=0;
	 u8 reminder=1;
	 
	if(Cpy_u8SSEGValue<0 || Cpy_u8SSEGValue >SSEG_Max_NumOfSSEG)
	{
		Local_enuErrorStatus=SSEG_enuInvalidValue;
	} 
	else
	{
		
	
		for(LocalCounter=0;LocalCounter<SSEG_enuNumberOfSSEG;LocalCounter++)
		{
			if(SSREG_strcfg[LocalCounter].SSEG_ActiveStatus==SSEG_enuCommonCathode)
			{
				
				    reminder=Cpy_u8SSEGValue%10;
					DIO_enuSetPortVal(SSREG_strcfg[LocalCounter].SSEG_Port,SevenSegment_LookUp[reminder]);
					Cpy_u8SSEGValue/=10;
					
			}
			else if(SSREG_strcfg[LocalCounter].SSEG_ActiveStatus==SSEG_enuCommonAnode)
			{
				
				reminder=Cpy_u8SSEGValue%10;
				DIO_enuSetPortVal(SSREG_strcfg[LocalCounter].SSEG_Port,~SevenSegment_LookUp[reminder]);
				Cpy_u8SSEGValue/=10;
				
			}
			
		}
			
	Local_enuErrorStatus=SSEG_enuOk;
	}
	return Local_enuErrorStatus;
}