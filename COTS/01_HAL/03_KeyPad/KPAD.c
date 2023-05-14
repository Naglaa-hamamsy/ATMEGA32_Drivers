#include "util/delay.h"
#include "STD_Types.h"
#include "DIO.h"
#include "KPAD.h"
#include "KPAD_cfg.h"
#include "KPAD_prv.h"

KPAD_enuErrorStatus KPAD_u8GetThePressedKey(u8 * Add_pu8PressedKey)
{   /* Make Sure you did the configuration of kpd (direction) in DIO */
	DIO_enuSetPortVal(KPAD_PORT,KPAD_PORT_VALUE);

	u8 Local_u8Row=0,Local_u8Col=0,Local_u8Pressed_Key=Not_Pressed,Local_u8Address=0;
  for(Local_u8Col=COLOMN_INIT;Local_u8Col<NumberOfColomns;Local_u8Col++)
  {
	  DIO_enuClearPin(KPAD_strColomnsConfig[Local_u8Col].ColPin);
	  
	  for(Local_u8Row=ROW_INIT;Local_u8Row<NumberOfRows;Local_u8Row++)
	  {
		  if(DIO_enuGetPin(KPAD_strRowsConfig[Local_u8Row].RowPin,&Local_u8Address)==DIO_enuOk)
		  	{			  if(!Local_u8Address)
				  {    // _delay_ms(50);
					   *Add_pu8PressedKey=KpadArray[Local_u8Row][Local_u8Col];
					  
				  }
			  }
	  }
	  
	DIO_enuSetPin(KPAD_strColomnsConfig[Local_u8Col].ColPin);
	  
  }
   return KPAD_enuOK;
}
	 

	  
	  
	  
  
