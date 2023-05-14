#include "STD_Types.h"
#include "BIT_Math.h"
#include "DIO.h"
#include "DIO_Cfg.h"
#include "DIO_Prv.h"

/* Implementation of Initialization function*/

DIO_tenuErrorStatus DIO_enuInit(void)
{   u8 i;
	u8 Loc_u8PortNumber=0;
	u8 Loc_u8PinNumber=0;
	for(i=0;i<DIO_enuNumberOfPins;i++)
	{
		Loc_u8PortNumber=i/PORT_PIN_CHECK;
		Loc_u8PinNumber=i%PORT_PIN_CHECK;
		switch(Loc_u8PortNumber)
		{
			case(DIO_PORTA): 
				if(DIO_strPinCfg[i].DIO_PinDirection== DIO_DIR_OUTPUT)
					{
						SET_BIT(DDRA_REG,Loc_u8PinNumber);
					}
				else
					{
					CLR_BIT(DDRA_REG,Loc_u8PinNumber);
					if(DIO_strPinCfg[i].DIO_InputStatus==DIO_INPUT_PULLUP)
						{
							SET_BIT(PORTA_REG,Loc_u8PinNumber);
						}
					 }
				break;
			case(DIO_PORTB): 
				if(DIO_strPinCfg[i].DIO_PinDirection== DIO_DIR_OUTPUT)
					{
						SET_BIT(DDRB_REG,Loc_u8PinNumber); 
					}
				else
					{
						CLR_BIT(DDRB_REG,Loc_u8PinNumber);
						if(DIO_strPinCfg[i].DIO_InputStatus==DIO_INPUT_PULLUP)
							{	
								SET_BIT(PORTB_REG,Loc_u8PinNumber);
							}
					}
					//DDRA=PORT_CONCATENATION(PORTA_PIN7,PORTA_PIN6,PORTA_PIN5...PIN0); F satr wahed mnn
				break;
			case(DIO_PORTC):
				if(DIO_strPinCfg[i].DIO_PinDirection== DIO_DIR_OUTPUT)
					{
						SET_BIT(DDRC_REG,Loc_u8PinNumber);
					}
				else
					{
						CLR_BIT(DDRC_REG,Loc_u8PinNumber);
						if(DIO_strPinCfg[i].DIO_InputStatus==DIO_INPUT_PULLUP)
							{
								SET_BIT(PORTC_REG,Loc_u8PinNumber);
							}		
					}		
				break;
			case(DIO_PORTD):
				if(DIO_strPinCfg[i].DIO_PinDirection== DIO_DIR_OUTPUT)
					{
						SET_BIT(DDRD_REG,Loc_u8PinNumber); 
					}
				else
					{
						CLR_BIT(DDRD_REG,Loc_u8PinNumber);
						if(DIO_strPinCfg[i].DIO_InputStatus==DIO_INPUT_PULLUP)
							{
								SET_BIT(PORTD_REG,Loc_u8PinNumber);
							}
					}
				break;
					}
		}
	return DIO_enuOk;
}
/*Implementation of Set Pin Value*/
DIO_tenuErrorStatus DIO_enuSetPin(DIO_tenuPins Cpy_enuPinNumber)
{	u8 Loc_u8PortNumber=0;
	DIO_tenuErrorStatus Local_enuDIOErrorStatus=0;
	if((Cpy_enuPinNumber>DIO_enuPin31) | (Cpy_enuPinNumber<DIO_enuPin0))
		{
		Local_enuDIOErrorStatus=DIO_enuInvalidPinNum;
		}
	else
	 {
	 Loc_u8PortNumber=Cpy_enuPinNumber/PORT_PIN_CHECK;
	 Cpy_enuPinNumber%=PORT_PIN_CHECK;
	 
	 switch(Loc_u8PortNumber)
	  {
		case(DIO_PORTA):
			{
			SET_BIT(PORTA_REG,Cpy_enuPinNumber);
			break;
			}
		case(DIO_PORTB):
			{
			SET_BIT(PORTB_REG,Cpy_enuPinNumber);
			break;
			}
		case(DIO_PORTC):
			{
			SET_BIT(PORTC_REG,Cpy_enuPinNumber);
			break;
			}
		case(DIO_PORTD):
			{
			SET_BIT(PORTD_REG,Cpy_enuPinNumber);
			break;
			}
	  }
	  Local_enuDIOErrorStatus=DIO_enuOk;
    }
	return Local_enuDIOErrorStatus;
}
	
	/*Implementation of Clear Pin Value*/
 
 DIO_tenuErrorStatus DIO_enuClearPin(DIO_tenuPins Cpy_enuPinNumber)
{ 
	 u8 Loc_u8PortNumber=0;
	DIO_tenuErrorStatus Local_enuDIOErrorStatus=0;
	 if((Cpy_enuPinNumber>DIO_enuPin31) | (Cpy_enuPinNumber<DIO_enuPin0))
		 {
			Local_enuDIOErrorStatus=DIO_enuInvalidPinNum;
	   	 }
	 else
		 {
		Loc_u8PortNumber=Cpy_enuPinNumber/PORT_PIN_CHECK;
		Cpy_enuPinNumber%=PORT_PIN_CHECK;
		switch(Loc_u8PortNumber)
		  {											
			case(DIO_PORTA):
			 {
				CLR_BIT(PORTA_REG,Cpy_enuPinNumber);
				break;
			 }
			case(DIO_PORTB):
			 {
				CLR_BIT(PORTB_REG,Cpy_enuPinNumber);
				break;
			 }
			case(DIO_PORTC):
			 {
				CLR_BIT(PORTC_REG,Cpy_enuPinNumber);
				break;
			 }
			case(DIO_PORTD):
			 {
				CLR_BIT(PORTD_REG,Cpy_enuPinNumber);
				break;
			 }
		 }
		Local_enuDIOErrorStatus=DIO_enuOk;
	  }
		return Local_enuDIOErrorStatus;
}
/* Implementation of Get Pin function*/	 
DIO_tenuErrorStatus DIO_enuGetPin(DIO_tenuPins Cpy_enuPinNumber,DIO_tenuPinValue * Add_penuPinValue)
{
	u8 Loc_u8PortNumber=0;
	DIO_tenuErrorStatus Local_enuDIOErrorStatus=0;
	if(Add_penuPinValue==NULL)
		{
		 Local_enuDIOErrorStatus=DIO_enuNullPtr;
		}
	else if((Cpy_enuPinNumber>DIO_enuPin31) | (Cpy_enuPinNumber<DIO_enuPin0))
		{
		Local_enuDIOErrorStatus=DIO_enuInvalidPinNum;
		}
		else
		{
	 Loc_u8PortNumber=Cpy_enuPinNumber/PORT_PIN_CHECK;
	 Cpy_enuPinNumber%=PORT_PIN_CHECK;
	 switch(Loc_u8PortNumber)
	{
		case(DIO_PORTA):
	 	 {
			*Add_penuPinValue=GET_BIT(PINA_REG,Cpy_enuPinNumber);
			break;
		 }
		case(DIO_PORTB):
		 {
			*Add_penuPinValue=GET_BIT(PINB_REG,Cpy_enuPinNumber);
			break;
		 }
		case(DIO_PORTC):
		 {
			*Add_penuPinValue=GET_BIT(PINC_REG,Cpy_enuPinNumber);
			break;
		 }
		case(DIO_PORTD):
		 {
			*Add_penuPinValue=GET_BIT(PIND_REG,Cpy_enuPinNumber);
			break;
		 }
    }
	Local_enuDIOErrorStatus=DIO_enuOk;
		}
	return Local_enuDIOErrorStatus;
}
 /*DIO_tenuErrorStatus DIO_enuSetPortVal(DIO_tenuPins Cpy_enuPinNumber, u8 Cpy_u8PortValue)
 { u8 Loc_u8PortNumber=0;
 DIO_tenuErrorStatus Local_enuDIOErrorStatus=0;
   
    if((Cpy_enuPinNumber!=0) &&(Cpy_enuPinNumber!=8) && (Cpy_enuPinNumber!=16) && (Cpy_enuPinNumber!=24))
	  {
	Local_enuDIOErrorStatus=DIO_enuInvalidPinNum;
	  }
	else if((Cpy_u8PortValue>DIO_PORT_HIGH) | (Cpy_u8PortValue<DIO_PORT_LOW))
	  {
	Local_enuDIOErrorStatus= DIO_enuInvalidPortVal;
	  }
	else
	{
		 Loc_u8PortNumber=Cpy_enuPinNumber/PORT_PIN_CHECK;
		 switch(Loc_u8PortNumber)
		 {
			 case(DIO_PORTA):
			 {
				PORTA_REG=Cpy_u8PortValue;
				 break;
			 }
			 case(DIO_PORTB):
			 {
				PORTB_REG=Cpy_u8PortValue;
				break;
			 }
			 case(DIO_PORTC):
			 {
				PORTC_REG=Cpy_u8PortValue;
				break;
			 }
			 case(DIO_PORTD):
			 {
				PORTD_REG=Cpy_u8PortValue;
				break;
			 }
		 }
		 Local_enuDIOErrorStatus=DIO_enuOk;
	 }
	return Local_enuDIOErrorStatus;
   }*/
	
  DIO_tenuErrorStatus DIO_enuSetPortVal(u8 Cpy_u8PortNumber, u8 Cpy_u8PortValue)
 { 
 DIO_tenuErrorStatus Local_enuDIOErrorStatus=0;
   
   if(Cpy_u8PortNumber>DIO_PORTD)
		{
	Local_enuDIOErrorStatus=DIO_enuInvalidPortNum;
	  }
	else if((Cpy_u8PortValue>DIO_PORT_HIGH) | (Cpy_u8PortValue<DIO_PORT_LOW))
	  {
	Local_enuDIOErrorStatus= DIO_enuInvalidPortVal;
	  }
	else
	{
		
		 switch(Cpy_u8PortNumber)
		 {
			 case(DIO_PORTA):
			 {
				PORTA_REG=Cpy_u8PortValue;
				 break;
			 }
			 case(DIO_PORTB):
			 {
				PORTB_REG=Cpy_u8PortValue;
				break;
			 }
			 case(DIO_PORTC):
			 {
				PORTC_REG=Cpy_u8PortValue;
				break;
			 }
			 case(DIO_PORTD):
			 {
				PORTD_REG=Cpy_u8PortValue;
				break;
			 }
		 }
		 Local_enuDIOErrorStatus=DIO_enuOk;
	 }
	return Local_enuDIOErrorStatus;
   }
	