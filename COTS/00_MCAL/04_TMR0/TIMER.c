#include "STD_Types.h"
#include "BIT_Math.h" 
#include "GlobalInterrubt.h"
#include "TIMER_Cfg.h"
#include "TIMER.h"
#include "TIMER_prv.h"

static CBF_t TMR0_pvNotifyFunc[2] = {NULL};
/*This is for a post-build initialization*/ 
static void TMR0_enuEnableInterrupt(u8 Cpy_u8Mode);

void TMR0_vidInitPreCompile(void)
{
	u8 Local_u8Register =0;
	
	/*Set Timer Mode*/
	Local_u8Register = TCCR0;
	Local_u8Register &=~TMR0_MODE_CLR_MASK;
	Local_u8Register |=TMR0_MODE;
	TCCR0 = Local_u8Register;
	
	/*Select The HW Action on OC0 Pin in CTC Mode*/
	#if  TMR0_MODE == TMR0_MODE_CTC
		
		Local_u8Register = TCCR0;
		Local_u8Register &=~TMR0_MODE_OUTPUT_CLR_MASK;
		Local_u8Register |=TMR0_MODE_CTC_OUTPUT;
		TCCR0 = Local_u8Register;
		/*Output Mode Of Fast PWM Mode*/
	#elif TMR0_MODE == TMR0_MODE_FAST_PWM
		Local_u8Register = TCCR0;
		Local_u8Register &=~TMR0_MODE_OUTPUT_CLR_MASK;
		Local_u8Register |= TMR0_MODE_FAST_PWM_OUTPUT;
		TCCR0 = Local_u8Register;
		
		/*Output Mode Of PWM Phase Correct Mode*/
	#elif TMR0_MODE == TMR0_MODE_PWM_PHASE_CORRECT
		Local_u8Register = TCCR0;
		Local_u8Register &=~TMR0_MODE_OUTPUT_CLR_MASK;
		Local_u8Register |= TMR0_MODE_PWM_PHASE_CORRECT_OUTPUT;
		TCCR0 = Local_u8Register;
	#endif
	
	/*Set The Prescaler*/
	Local_u8Register = TCCR0;
	Local_u8Register &=~TMR0_PRESCALER_CLR_MASK;
	Local_u8Register |=TMR0_CLK_SOURCE;
	TCCR0 = Local_u8Register;
	
	 /*Enable the corresponding interrupt*/
	#if TMR0_MODE == TMR0_MODE_NORMAL
		/*Enable OverFlow Interrupt Only*/
		TIMSK |= 1<< TMR0_OVER_FLOW_INTERRUPT_ENABLE_PIN;
		

	#elif TMR0_MODE == TMR0_MODE_CTC                	/*CTC Mode*/
	/*Enable Compare match only*/
		TIMSK |=(1<<TMR0_COMPARE_MATCH_INTERRUPT_ENABLE_PIN);

	#endif
}

void TMR0_vidInitPostCompile(TMR0Config_t *Cfg)
{
		u8 Local_u8Register = 0;
		u8 Temp_Mode = 0;
		u8 Temp_Output = 0;
		
		/*Set Prescaler*/
		
		Local_u8Register = TCCR0;
		Local_u8Register &=~TMR0_PRESCALER_CLR_MASK;
		Local_u8Register |=Cfg->TMR0_Prescaler;
		TCCR0 = Local_u8Register;
		
		/*Set Timer Output Behavior*/
		Local_u8Register = TCCR0;
		Local_u8Register &=~TMR0_MODE_OUTPUT_CLR_MASK;
		Temp_Output = Cfg->TMR0_Mode_Output;
		Temp_Output>>=4;
		Local_u8Register |= (Temp_Output<<4);
		TCCR0 = Local_u8Register;
				
		/*Set Timer Mode*/
		Local_u8Register = TCCR0;
		Local_u8Register &=~TMR0_MODE_CLR_MASK;
		Temp_Mode = Cfg->TMR0_Mode_Output;
		Temp_Mode &=TMR0_MODE_POST_BUILD_CLR_MASK;
		Local_u8Register |=(Temp_Mode<<3);
		TCCR0 = Local_u8Register;
		 TMR0_enuEnableInterrupt(Cfg->TMR0_Mode_Output);
}
TMR0_enuErrorStatus TMR0_enuSetCompareValue(u8 Cpy_u8CompareValue)
{
	TMR0_enuErrorStatus Local_enuErrorStatus = TMR0_enuOK;
	if(Cpy_u8CompareValue > TMR0_OVERFLOW_VALUE )
	{
		Local_enuErrorStatus = TMR0_enuNOK;
	}
	else
	{
		OCR0=Cpy_u8CompareValue;
		Local_enuErrorStatus = TMR0_enuOK;
	}
	return Local_enuErrorStatus;
	
}
TMR0_enuErrorStatus TMR0_enuSetTimerValue(u8 Cpy_u8TCNTValue)
{
	TMR0_enuErrorStatus Local_enuErrorStatus = TMR0_enuOK;
	if(Cpy_u8TCNTValue > TMR0_OVERFLOW_VALUE )
	{
		Local_enuErrorStatus = TMR0_enuNOK;
	}
	else
	{
		TCNT0 = Cpy_u8TCNTValue;
		Local_enuErrorStatus = TMR0_enuNOK;
	}
	return Local_enuErrorStatus;
}
static void TMR0_enuEnableInterrupt(u8 Cpy_u8Mode)
{
	u8 Local_u8Register = 0;
	
	/*if((Cpy_u8Mode == TMR0_MODE_OUTPUT_FPWM_SCCT) || (Cpy_u8Mode == TMR0_MODE_OUTPUT_FPWM_CCST) 
	|| (Cpy_u8Mode == TMR0_MODE_OUTPUT_PHASE_CORRECT_CCUSCD) || (Cpy_u8Mode == TMR0_MODE_OUTPUT_PHASE_CORRECT_SCUCCD))

	{
		
		Local_u8Register = TIMSK;
		Local_u8Register |= ((1<<TMR0_COMPARE_MATCH_INTERRUPT_ENABLE_PIN) | (1<<TMR0_OVER_FLOW_INTERRUPT_ENABLE_PIN));
		TIMSK = Local_u8Register;
		
	} 
	*/
	 if (Cpy_u8Mode == TMR0_MODE_OUTPUT_NORMAL)
	{
		/*Enable OverFlow Interrupt Only*/
			TIMSK |= 1<< TMR0_OVER_FLOW_INTERRUPT_ENABLE_PIN;
	}
	 /*CTC Mode*/
	else if((Cpy_u8Mode == TMR0_MODE_OUTPUT_CTC_TOGGLE) || (Cpy_u8Mode == TMR0_MODE_OUTPUT_CTC_SET) || (Cpy_u8Mode == TMR0_MODE_OUTPUT_CTC_CLEAR))  
	{
		/*Enable Compare Match Interrupt Only*/
		TIMSK |= 1<< TMR0_COMPARE_MATCH_INTERRUPT_ENABLE_PIN;
	}
	
}
TMR0_enuErrorStatus TMR0_enuRegisterCallback(CBF_t CBF, u8 Index)

{
	
	TMR0_enuErrorStatus Local_enuErrorStatus = TMR0_enuNOK;
	if( CBF == NULL)
	{
		Local_enuErrorStatus = TMR0_enuNullPtr;
	}
	else
	{
			if(Index < MAX_NOTIFY_FUNC)
			{
				
				TMR0_pvNotifyFunc[Index] = CBF;
				Local_enuErrorStatus = TMR0_enuOK;
			}
			else
			{
				Local_enuErrorStatus = TMR0_enuNOK;
			}
	}
	
	return Local_enuErrorStatus;
	
}
TMR0_enuErrorStatus TMR0_enuSetDutyCycle_NonInverted(u8 Cpy_u8DutyCycle)
{
		TMR0_enuErrorStatus Local_enuErrorStatus = TMR0_enuOK;
		u8 Local_u8CompValue = 0;
		
		 if(Cpy_u8DutyCycle > 100)
		{
			Local_enuErrorStatus = TMR0_enuNOK;
		}
		 /*Check if mode is inverted or not in case of FPWM or PHASE CORRECT*/
		else if((TCCR0 >> TMR0_COM00_PIN)&1)
		{
			Local_enuErrorStatus = TMR0_enuNOK;
			/*To make sure that there's no signal on this pin*/
			OCR0 = TMR0_OVERFLOW_VALUE;
			
		}
		else
		{
			Local_u8CompValue = ((u32)(Cpy_u8DutyCycle * TMR0_MAX_TICKS )) /100;
			OCR0 = Local_u8CompValue;
		}
		return Local_enuErrorStatus;
}
TMR0_enuErrorStatus TMR0_enuSetDutyCycle_Inverted(u8 Cpy_u8DutyCycle)
{
	TMR0_enuErrorStatus Local_enuErrorStatus = TMR0_enuOK;
	u8 Local_u8CompValue = 0;
	
	if(Cpy_u8DutyCycle > 100)
	{
		Local_enuErrorStatus = TMR0_enuNOK;
	}
	 /*Check if mode is inverted or not in case of FPWM or PHASE CORRECT*/
	else if (((TCCR0 >> TMR0_COM00_PIN)&1)==0)
	{
		Local_enuErrorStatus = TMR0_enuNOK;

	}
	else
	{
		Local_u8CompValue = (TMR0_MAX_TICKS - ((u32)(Cpy_u8DutyCycle * TMR0_MAX_TICKS )/100));
		OCR0 = Local_u8CompValue;
	}
	return Local_enuErrorStatus;
}
void __vector_11 (void) __attribute__((signal));
void __vector_11 (void)
{
	if(TMR0_pvNotifyFunc[TMR0_OVF_INTERRUPT])
	{
		TMR0_pvNotifyFunc[TMR0_OVF_INTERRUPT]();
	}
}
void __vector_10 (void) __attribute__((signal));
void __vector_10 (void)
{
		if(TMR0_pvNotifyFunc[TMR0_COMP_MATCH_INTERRUPT])
		{
			TMR0_pvNotifyFunc[TMR0_COMP_MATCH_INTERRUPT]();
		}
}