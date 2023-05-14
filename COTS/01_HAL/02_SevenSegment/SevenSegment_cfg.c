#include "DIO.h"
#include "SevenSegment_cfg.h"
const SSREG_strcfg_t SSREG_strcfg[SSEG_enuNumberOfSSEG]=
{
	/*{
		.SSEG_Port=DIO_PORTA,
		.SSEG_ActiveStatus=	SSEG_enuCommonCathode
		
	},*/
	
	{
		.SSEG_Port=DIO_PORTB,
		.SSEG_ActiveStatus=	SSEG_enuCommonCathode
	}
	
	
};