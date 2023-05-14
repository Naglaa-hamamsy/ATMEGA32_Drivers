#include "STD_Types.h"
#include "BIT_Math.h"
#include "ADC_cfg.h"
#include "ADC.h"
#include "ADC_prv.h"
//#include "ADC_prv.h"
static u8 ADC_u8BusyState=IDLE;
static u8 ADC_u8ChainIndex = 0;
static u8 ADC_u8ChainLength = 0; 
static u8 ADC_u8ChainIndex;
static u16 * ADC_ChainResult = NULL;
static u8 *ADC_ChainChannels = NULL;
static u8 ADC_u8Flag=2;
static void (*ADC_ChainEOJ)(void) =NULL;
static u16 *ADC_pu16Reading=NULL;
static void (*ADC_pvCallBackNotificationFunc)(void)=NULL;

ADC_tenuErrorStatus ADC_enuInit(void)
{ u8 Local_u8Reg = ADMUX_REG;
	/* Select the voltage reference */
	/*Clear selection bits in temporary register then copy it into original one*/
	Local_u8Reg = ADMUX_REG;
	Local_u8Reg &= (~ADC_REF_SELECTION_CLEAR_MASK);
	/*Put the selected reference into ADMUX register*/
	Local_u8Reg |= ADC_REF_SELECTION;
	ADMUX_REG = Local_u8Reg;
	/*Select left or right adjust result*/
		
	#if LEFT_ADJUST == ENABLE
		ADMUX_REG |= (1<<ADMUX_ADLAR_PIN);
	#endif
	
	/*Select Polling | Interrupt ADC*/
	#if SELECT_POLLING_INTERRUPT == INTERRUPT_SELECTION
		ADCSRA_REG |= (1<<ADCSRA_ADIE_PIN);
	#endif
	
	/*Check if AUTO_TRIGGER is Enable or Not*/
	#if AUTO_TRIGGER == ENABLE
		ADCSRA_REG |= (1<<ADCSRA_ADATE_PIN);
	
	 #endif
	/*Select the Configured Prescaler*/
	Local_u8Reg = ADCSRA_REG;
	Local_u8Reg &= (~ADC_PRESCALER_CLEAR_MASK);
	Local_u8Reg |= ADC_PRESCALER;
	ADCSRA_REG = Local_u8Reg;
	
	/*Enable ADC Peripheral*/
	ADCSRA_REG |= (1<<ADCSRA_ADEN_PIN);
	
	return ADC_enuOK;
}

ADC_tenuErrorStatus ADC_enuSelectChannel(ADC_tenuChannel Cpy_enuChannel)
{	u8 Local_u8Reg = 0;
	ADC_tenuErrorStatus Local_enuErrorStatus=ADC_enuOK;
	if((Cpy_enuChannel < ADC_enuChannel_Single_0) || (Cpy_enuChannel > ADC_enuChannel_Diff_42_1xG))
	{
		Local_enuErrorStatus = ADC_enuNOK;
	}
	else
	{
		/*Select The Channel*/
		/*Clear Channel Bits*/
		Local_u8Reg=ADMUX_REG;
		Local_u8Reg &= (~ADC_Channel_Mask);
		/*Select The Channel Needed In ADMUX REG*/
		Local_u8Reg |= Cpy_enuChannel;
		ADMUX_REG = Local_u8Reg;
	}
	return Local_enuErrorStatus;
}

ADC_tenuErrorStatus ADC_enuStartConversion(void)
{
	ADC_tenuErrorStatus Local_enuErrorStatus = ADC_enuOK;
		/*Start Conversion*/
		ADCSRA_REG |= (1<<ADCSRA_ADSC_PIN);
		return Local_enuErrorStatus;
}

ADC_tenuErrorStatus ADC_enuGetChannelReading(u16 *Add_pu16Reading)
{	
		ADC_tenuErrorStatus Local_enuErrorStatus = ADC_enuOK;
		u16 Local_u16Counter = 0;
		/*if(Add_pu8Reading==NULL)
		{
			Local_enuErrorStatus=ADC_enuNOK;			
		}*/
		
		/*Check if Start conversion pin is set or not*/
		 if(!((ADCSRA_REG>>ADCSRA_ADSC_PIN) & 1))
		{
			Local_enuErrorStatus = ADC_enuNOK;
		}
		else
		{
			
			//if (SELECT_POLLING_INTERRUPT == POLLING_SELECTION) 
			//		{
				/*Wait Until The Flag Being Set*/
				while((((ADCSRA_REG>>ADCSRA_ADIF_PIN)&1)==0) && (Local_u16Counter<TIME_OUT))
				{
					Local_u16Counter++;
				}
					if(((ADCSRA_REG>>ADCSRA_ADIF_PIN)&1)) 
			
				{
						/*Clear Flag Pin*/
						ADCSRA_REG|=1<<ADCSRA_ADIF_PIN;
				}
					else 
					{
						Local_enuErrorStatus=ADC_enuNOK;
					}
			
					if(Local_enuErrorStatus==ADC_enuOK)
					{
				
							if (RIGHT_ADJUST==ENABLE)
								*Add_pu16Reading=ADCL_REG;
							else if (LEFT_ADJUST==ENABLE)
								*Add_pu16Reading=ADCH_REG;
				
					Local_enuErrorStatus=ADC_enuOK;	
					}
			
		}
	return Local_enuErrorStatus;
}
ADC_tenuErrorStatus ADC_enuStartConversion_Synch (ADC_tenuChannel Cpy_enuChannel , u16 *Add_pu16Reading)
{ ADC_tenuErrorStatus Local_enuErrorStatus=ADC_enuOK;
	if(ADC_u8BusyState==BUSY)
	{
		Local_enuErrorStatus = ADC_enuBusyFunc;
	}
	else
	{
		
		u8 Local_u8Reg = 0;
		u16 Local_u16Counter=0;
		
		if((Cpy_enuChannel < ADC_enuChannel_Single_0) || (Cpy_enuChannel > ADC_enuChannel_Diff_42_1xG))
		{
			Local_enuErrorStatus = ADC_enuNOK;
		}
		else if(Add_pu16Reading == NULL)
		{
			Local_enuErrorStatus = ADC_enuNullPtr; 
		}
		else
		{
			
		/*Make ADC BUSY Until Conversion Completed And State Being IDLE */
			ADC_u8BusyState=BUSY;
			/*Select The Channel*/
			/*Clear Channel Bits*/
			Local_u8Reg=ADMUX_REG;
			Local_u8Reg &= (~ADC_Channel_Mask);
			/*Select The Channel Needed In ADMUX REG*/
			Local_u8Reg |= Cpy_enuChannel;
			ADMUX_REG = Local_u8Reg;
			/*Start Conversion*/
			ADCSRA_REG |= (1<<ADCSRA_ADSC_PIN);
			/******POLLING**********/
			/*Wait Until The Flag Being Set*/
			while((((ADCSRA_REG>>ADCSRA_ADIF_PIN)&1)==0) && (Local_u16Counter<TIME_OUT))
				{
					Local_u16Counter++;
				}
			if(((ADCSRA_REG>>ADCSRA_ADIF_PIN)&1))
		
				{
					/*Clear Flag Pin*/
					ADCSRA_REG|=1<<ADCSRA_ADIF_PIN;
				}
			else
				{
					Local_enuErrorStatus=ADC_enuNOK;
				}
		
			if(Local_enuErrorStatus==ADC_enuOK)
			   {
			
				if (RIGHT_ADJUST==ENABLE)
					{
						*Add_pu16Reading=ADCL_REG;
					}
				else if (LEFT_ADJUST==ENABLE)
					{
						*Add_pu16Reading=ADCH_REG;
					}
			/*ADC is finished ,return the state to IDLE*/
				ADC_u8BusyState=IDLE;
				Local_enuErrorStatus=ADC_enuOK;
			  }
		
			}
	}
	return Local_enuErrorStatus;
}
ADC_tenuErrorStatus ADC_enuStartConversion_ASynch (ADC_tenuChannel Cpy_enuChannel , u16 *Add_pu16Reading, void (*Add_pvNotificationFunc)(void))
{	
	ADC_tenuErrorStatus Local_enuErrorStatus=ADC_enuOK;
	if(ADC_u8BusyState==BUSY)
	{
		Local_enuErrorStatus = ADC_enuBusyFunc;
	}
	else
	{
		u8 Local_u8Reg = 0;
	
		if((Cpy_enuChannel < ADC_enuChannel_Single_0) || (Cpy_enuChannel > ADC_enuChannel_Diff_42_1xG))
		{
			Local_enuErrorStatus = ADC_enuNOK;
		}
		else if((Add_pu16Reading == NULL) || (Add_pvNotificationFunc == NULL))
		{
			Local_enuErrorStatus = ADC_enuNullPtr;
		}
		else
		{
			/* Set the flag to 1 to select Asynchronous ISR not Chaining*/
			ADC_u8Flag = ADC_NOT_CHAINING;
			ADC_u8BusyState=BUSY;
			/*Select The Channel*/
			/*Clear Channel Bits*/
			Local_u8Reg=ADMUX_REG;
			Local_u8Reg &= (~ADC_Channel_Mask);
			/*Select The Channel Needed In ADMUX REG*/
			Local_u8Reg |= Cpy_enuChannel;
			ADMUX_REG = Local_u8Reg;
			/*Start Conversion*/
			ADCSRA_REG |= (1<<ADCSRA_ADSC_PIN);
			/*Make The Received Address Global, To Be Seen By ISR */ 
			ADC_pu16Reading=Add_pu16Reading;
			/*Make The Received Function Global, To Be Called By ISR */ 
			ADC_pvCallBackNotificationFunc=Add_pvNotificationFunc;
			/*Enable Interrupt*/
			ADCSRA_REG|=1<<ADCSRA_ADIE_PIN;
			Local_enuErrorStatus=ADC_enuOK;
		}
	}
	return Local_enuErrorStatus;
}

ADC_tenuErrorStatus ADC_enuAutoTriggerConversion (ADC_tenuChannel Cpy_enuChannel ,u8 Cpy_u8TriggerSource, u16 *Add_pu16Reading, void (*Add_pvNotificationFunc)(void))
{
	
	ADC_tenuErrorStatus Local_enuErrorStatus=ADC_enuOK;
	if(ADC_u8BusyState==BUSY)
	{
		Local_enuErrorStatus = ADC_enuBusyFunc;
	}
	else
	{
		u8 Local_u8Reg = 0;

		if((Cpy_enuChannel < ADC_enuChannel_Single_0) || (Cpy_enuChannel > ADC_enuChannel_Diff_42_1xG))
		{
			Local_enuErrorStatus = ADC_enuNOK;
		}
		else if((Add_pu16Reading == NULL) || (Add_pvNotificationFunc == NULL))
		{
			Local_enuErrorStatus = ADC_enuNullPtr;
		}
		else if(AUTO_TRIGGER == DISABLE)
		{
			Local_enuErrorStatus = ADC_enuNOK;
		}
		else
		{
			/* Set the flag to 1 to select Asynchronous ISR not Chaining*/
			ADC_u8Flag = 1;
			ADC_u8BusyState=BUSY;
			/*Select The Channel*/
			/*Clear Channel Bits*/
			Local_u8Reg=ADMUX_REG;
			Local_u8Reg &= (~ADC_Channel_Mask);
			/*Select The Channel Needed In ADMUX REG*/
			Local_u8Reg |= Cpy_enuChannel;
			ADMUX_REG = Local_u8Reg;
			/*Select The Trigger Source*/
			Local_u8Reg = SFIOR_REG;
			Local_u8Reg &= (~AUTO_TRIGGER_SOURCE_CLEAR_MASK);
			Local_u8Reg |= AUTO_TRIGGER_SOURCE;
			SFIOR_REG = Local_u8Reg;
			/*Make The Received Address Global, To Be Seen By ISR */
			ADC_pu16Reading=Add_pu16Reading;
			/*Make The Received Function Global, To Be Called By ISR */
			ADC_pvCallBackNotificationFunc=Add_pvNotificationFunc;
			/*Enable Interrupt*/
			ADCSRA_REG|=1<<ADCSRA_ADIE_PIN;
			Local_enuErrorStatus=ADC_enuOK;
		}
	}
	return Local_enuErrorStatus;
}
ADC_tenuErrorStatus ADC_enuStartChainConverstion (ADC_CHAIN_t * Chain)
{
	ADC_tenuErrorStatus Local_enuErrorStatus = ADC_enuOK;
	u8 Local_u8Reg=0;
	if(Chain == NULL)
	{
		Local_enuErrorStatus = ADC_enuNullPtr;
	}
	else
	{
		if(ADC_u8BusyState == IDLE)
		{
			/*Make ADC State Busy*/
			ADC_u8BusyState = BUSY;
			/*Start with index 0*/
			ADC_u8ChainIndex = 0;
		/* Clear ADC flag to select Chaining*/
		ADC_u8Flag = ADC_CHAINING;
		/*Make The Length Of Chain Global*/
		ADC_u8ChainLength = Chain->length;
		/*Make Chain EOJ Global*/
		ADC_ChainEOJ = Chain->EOJ;
		/*Make The Chain Result Array Global*/
		ADC_ChainResult = Chain->Result;
		/*Make The Chain Channels Global*/
		ADC_ChainChannels=Chain->Channels;
		/*Select First Channel*/
		/*Clear Channel Bits*/
		Local_u8Reg=ADMUX_REG;
		Local_u8Reg &= (~ADC_Channel_Mask);
		/*Select The Channel Needed In ADMUX REG*/
		Local_u8Reg |= Chain->Channels[ADC_u8ChainIndex];
		ADMUX_REG = Local_u8Reg;
		/*Start Conversion Of The First Channel*/
		ADCSRA_REG |= (1<<ADCSRA_ADSC_PIN);
		/*Enable Interrupt*/
		ADCSRA_REG|=1<<ADCSRA_ADIE_PIN;
		}
		else
		{
			Local_enuErrorStatus = ADC_enuBusyFunc;
		}
	}
	
	return Local_enuErrorStatus;
}
/***************ISR*******************/

void __vector_16 (void) __attribute__((signal));
void __vector_16 (void)
{	u8 Local_u8Reg=0;
	
	if(ADC_u8Flag == ADC_CHAINING) /*Start Conversion Using CHAINING*/
	{
		 /*Read ADC*/
		 if(RIGHT_ADJUST == ENABLE)
		 {
			 ADC_ChainResult[ADC_u8ChainIndex]=ADCL_REG;
		 }
		 else if(LEFT_ADJUST==ENABLE)
		 {
			 ADC_ChainResult[ADC_u8ChainIndex]=ADCH_REG;
		 }
		 
		if(ADC_u8ChainIndex == (ADC_u8ChainLength-1))
		{
			/*ADC is now IDLE*/
			ADC_u8BusyState = IDLE;
			ADC_ChainEOJ();
			/*Disable Interrupt*/
			ADCSRA_REG &=~(1<<ADCSRA_ADIE_PIN);
		}
		else
		{	 
			ADC_u8ChainIndex++;
			/*Select Next Channel*/
			/*Clear Channel Bits*/
			Local_u8Reg=ADMUX_REG;
			Local_u8Reg &= (~ADC_Channel_Mask);
			/*Select The Channel Needed In ADMUX REG*/
			Local_u8Reg |= ADC_ChainChannels[ADC_u8ChainIndex];
			ADMUX_REG = Local_u8Reg;
			/*Start Conversion Of The Next Channel*/
			ADCSRA_REG |= (1<<ADCSRA_ADSC_PIN);
		
		}
	}	
	else if(ADC_u8Flag== ADC_NOT_CHAINING)
	{ /*Start Conversion Using Single Conversion*/
		  /*Read ADC*/
		if(RIGHT_ADJUST == ENABLE)
		{
			*ADC_pu16Reading=ADCL_REG;
		}
		else if(LEFT_ADJUST==ENABLE)
		{
			*ADC_pu16Reading=ADCH_REG;
		}
		/*Call Back Notification Function To Tell User Than Conversion Completed*/
		/*Make ADC State be IDLE because it finished*/
		ADC_u8BusyState=IDLE;
		/*Call Back Function*/
		ADC_pvCallBackNotificationFunc();
	
		/*Disable Interrupt*/
		ADCSRA_REG &=~(1<<ADCSRA_ADIE_PIN);
	}
}
