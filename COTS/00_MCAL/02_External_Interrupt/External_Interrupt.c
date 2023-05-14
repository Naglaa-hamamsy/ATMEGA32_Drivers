#include "BIT_Math.h"		
#include "STD_Types.h"
#include "External_Interrupt.h"
#include "External_Interrupt_prv.h"
#include "External_Interrupt_cfg.h"
#include <avr/interrupt.h>
void(*EXTI_pvINT012Func[3])(void)={NULL,NULL,NULL};

void EXTI_vidInit(void)
{ u8 Temp_Reg=0;
 u8 ClearMask=0b11;

	#if EXTI_INT0_STATUS == ENABLE_INTERRUPT
		SET_BIT(GICR_REG,GICR_INT0_PIN);
		#if EXTI_INT0_MODE==INT0_MODE_LOW_LEVEL_TRIGGER
		
		Temp_Reg=MCUCR_REG;
		Temp_Reg&=~ClearMask;
		Temp_Reg|=INT0_MODE_LOW_LEVEL_TRIGGER;
		MCUCR_REG=Temp_Reg;
		
		#elif EXTI_INT0_MODE==INT0_MODE_FALLING_EDGE_TRIGGER
		
		
				Temp_Reg=MCUCR_REG;
				Temp_Reg&=~ClearMask;
				Temp_Reg|=INT0_MODE_FALLING_EDGE_TRIGGER;
					MCUCR_REG=Temp_Reg;
				
		#elif EXTI_INT0_MODE==INT0_MODE_RISING_EDGE_TRIGGER 
		
			Temp_Reg=MCUCR_REG;
			Temp_Reg&=~ClearMask;
			Temp_Reg|=INT0_MODE_RISING_EDGE_TRIGGER;
			MCUCR_REG=Temp_Reg;
			
			#else 
			Temp_Reg=MCUCR_REG;
			Temp_Reg&=~ClearMask;
			Temp_Reg|=INT0_MODE_LOGICAL_CHANGE_TRIGGER;
			MCUCR_REG=Temp_Reg;
			
			#endif
		#endif
			
		#if EXTI_INT1_STATUS == ENABLE_INTERRUPT
				SET_BIT(GICR_REG,GICR_INT1_PIN);
		#if EXTI_INT1_MODE==INT1_MODE_LOW_LEVEL_TRIGGER
		
		Temp_Reg=MCUCR_REG;
		Temp_Reg&=~(ClearMask<<2);
		Temp_Reg|=(INT1_MODE_LOW_LEVEL_TRIGGER<<2);
		MCUCR_REG=Temp_Reg;
		
		#elif EXTI_INT1_MODE==INT1_MODE_FALLING_EDGE_TRIGGER
		
		
		Temp_Reg=MCUCR_REG;
		Temp_Reg&=~(ClearMask<<2);
		Temp_Reg|=(INT1_MODE_FALLING_EDGE_TRIGGER<<2);
		MCUCR_REG=Temp_Reg;
		
		#elif EXTI_INT1_MODE==INT1_MODE_RISING_EDGE_TRIGGER
		
		Temp_Reg=MCUCR_REG;
		Temp_Reg&=~(ClearMask<<2);
		Temp_Reg|=(INT1_MODE_RISING_EDGE_TRIGGER<<2);
		MCUCR_REG=Temp_Reg;
		
		#else
		Temp_Reg=MCUCR_REG;
		Temp_Reg&=~(ClearMask<<2);
		Temp_Reg|=(INT1_MODE_LOGICAL_CHANGE_TRIGGER<<2);
		MCUCR_REG=Temp_Reg;
		
		#endif
		
	#endif
		#if EXTI_INT2_STATUS == ENABLE_INTERRUPT
			SET_BIT(GICR_REG,GICR_INT2_PIN);
		#if EXTI_INT2_MODE==INT2_MODE_RISING_EDGE_TRIGGER
		
			SET_BIT(MCUCSR_REG,MCUCSR_ISC2_PIN);
			
		#elif  EXTI_INT2_MODE==INT2_MODE_FALLING_EDGE_TRIGGER
		
			CLR_BIT(MCUCSR_REG,MCUCSR_ISC2_PIN);
		
			
		#endif
	#endif
}

u8 EXTI_SetCallBackFunc(void(*PtrToFunc)(void),u8 index)
{ u8 Local_u8ErrorStatus=EXTI_OK;
	u8 static Local_u8Counter=0;
	if(PtrToFunc==NULL)
	{
	Local_u8ErrorStatus=EXTI_NOK;	
	}
	else
	{
	EXTI_pvINT012Func[index]=PtrToFunc;
	}
	return Local_u8ErrorStatus;
}
ISR(INT0_vect)
{
EXTI_pvINT012Func[0]();
}
ISR(INT1_vect)
{
	EXTI_pvINT012Func[1]();
}