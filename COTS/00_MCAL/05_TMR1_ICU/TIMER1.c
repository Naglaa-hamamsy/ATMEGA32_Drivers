
#include "STD_Types.h"
#include "BIT_Math.h"
#include "TIMER1_Cfg.h"
#include "TIMER1.h"
#include "TIMER1_prv.h"

static CBF_t ICU_NotifyFunc = NULL;
static CBF_t TMR1_OVF_NotifyFunc = NULL;
static Count_NumOfOVF(void);
u8 Num_Of_OverFlows = 0;
void TMR1_init(void)
{
	u8 Local_Reg = 0;
	
	/*SELECT THE NORMAL MODE*/
	
	/*SELECT PRESCALER*/
	Local_Reg = TCCR1B;
	Local_Reg &= ~ TMR1_PRESCALER_MASK;
	Local_Reg |= TMR1_CLK_SOURCE;
	TCCR1B = Local_Reg;
}

void TMR1_ICU_INIT(void)
{
	u8 Local_Reg = 0;
	
	/*SELECT EDGE TRIGGER */
	#if ICU_EDGE == ICU_EDGE_RISING
		Local_Reg = TCCR1B; 
		Local_Reg &= ~ TMR1_ICU_EDGE_SELECT_MASK;
		Local_Reg |= ICU_EDGE_RISING;
		TCCR1B = Local_Reg;
	
	#elif ICU_EDGE == ICU_EDGE_FALLING
		Local_Reg = TCCR1B;
		Local_Reg &= ~ TMR1_ICU_EDGE_SELECT_MASK;
		Local_Reg |= ICU_EDGE_FALLING;
		TCCR1B = Local_Reg;
	#endif
	
	/*Enable ICU Interrupt & OverFlow Interrupt*/
	TIMSK|=(TMR1_ICU_INTERRUPT_MASK | TMR1_OVF_INTERRUPT_MASK);
	
	TMR1_OVF_SetCallBack(Count_NumOfOVF);
}
TMR1_tenuErrorStatus TMR1_ICU_SetEdge(u8 Cpy_u8TriggerEdge)
{
	u8 Local_Reg = 0;
	
	TMR1_tenuErrorStatus Local_enuErrorStatus = TMR1_enuOK;
	if((Cpy_u8TriggerEdge == ICU_EDGE_RISING) || (Cpy_u8TriggerEdge == ICU_EDGE_FALLING))
	{
			Local_Reg = TCCR1B; 
			Local_Reg &= ~ TMR1_ICU_EDGE_SELECT_MASK;
			Local_Reg |= Cpy_u8TriggerEdge;
			TCCR1B = Local_Reg;
	}
	else
	{
		Local_enuErrorStatus = TMR1_enuNOK;
	}
	return Local_enuErrorStatus;
}
TMR1_tenuErrorStatus TMR1_ICU_SetCallBack(CBF_t CBF)
{ 
	TMR1_tenuErrorStatus Local_enuErrorStatus = TMR1_enuOK;
	if(CBF == NULL)
	{
		Local_enuErrorStatus = TMR1_enuNullPtr;
	}
	else
	{
		ICU_NotifyFunc = CBF;
	}
	return Local_enuErrorStatus;
}
u16 TMR1_ICU_u16GetICR(void)
{
	return ICR1;
}
TMR1_tenuErrorStatus TMR1_ICU_INTERRUPT_STATE(u8 State)
{
	TMR1_tenuErrorStatus Local_enuErrorStatus = TMR1_enuOK;
	u8 Local_Reg=0;
	if((State == TMR1_ICU_INTERRUPT_ENABLE) || State == (TMR1_ICU_INTERRUPT_DISABLE))
	{
		Local_Reg = TIMSK;
		Local_Reg &=~ TMR1_ICU_INTERRUPT_MASK;
		Local_Reg |=State;
		TIMSK = Local_Reg;
	}
}
 TMR1_tenuErrorStatus TMR1_enuSetTimerValue(u16 Cpy_u16Value)
 {
	 	TMR1_tenuErrorStatus Local_enuErrorStatus = TMR1_enuOK;
		 if(Cpy_u16Value > 65535)
		 {
			 Local_enuErrorStatus = TMR1_enuNOK;
		 }
		 else
		 {
			 TCNT1 = Cpy_u16Value;
		 }
	 
 }
 static Count_NumOfOVF(void)
 {
	 Num_Of_OverFlows ++;
 }
void __vector_6 (void) __attribute__((signal));
void __vector_6 (void)
{
	if(ICU_NotifyFunc)
	{
		ICU_NotifyFunc();
	}
}
void __vector_9 (void) __attribute__((signal));
void __vector_9 (void)
{
	if(TMR1_OVF_NotifyFunc)
	{
		TMR1_OVF_NotifyFunc();
	}
}

TMR1_tenuErrorStatus TMR1_OVF_SetCallBack(CBF_t CBF)
{
	TMR1_tenuErrorStatus Local_enuErrorStatus = TMR1_enuOK;
	if(CBF == NULL)
	{
		Local_enuErrorStatus = TMR1_enuNullPtr;
	}
	else
	{
		TMR1_OVF_NotifyFunc = CBF;
	}
	return Local_enuErrorStatus;
}