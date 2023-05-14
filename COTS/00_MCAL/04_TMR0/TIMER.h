#ifndef TIMER_H
#define TIMER_H

/*****************************************************DEFINES**********************************************/

/*****************************************************TYPES**********************************************/

typedef enum{
	
    TMR0_enuOK,
    TMR0_enuNOK,
	TMR0_enuNullPtr

}TMR0_enuErrorStatus;

typedef struct  
{
	u8 TMR0_Prescaler;
	u8 TMR0_Mode_Output; /*Mode and Output Behavior*/
	
}TMR0Config_t;

/*************************************PRESCALER OPTIONS**********************************************
			
									1) TMR0_PRESCALER_DIV_1
									2) TMR0_PRESCALER_DIV_8
									3) TMR0_PRESCALER_DIV_64
									4) TMR0_PRESCALER_DIV_256
									5) TMR0_PRESCALER_DIV_1024
									6) TMR0_EXT_CLK_FALLING
									7) TMR0_EXT_CLK_RISING
					
*******************************************************************************************************/					
/**************************************MODE OPTIONS****************************************************
			
									1)TMR0_MODE_OUTPUT_CTC_TOGGLE
									2)TMR0_MODE_OUTPUT_CTC_CLEAR
									3)TMR0_MODE_OUTPUT_CTC_SET
									4)TMR0_MODE_OUTPUT_FPWM_CCST
									5)TMR0_MODE_OUTPUT_FPWM_SCCT
									6)TMR0_MODE_OUTPUT_PHASE_CORRECT_CCUSCD
									7)TMR0_MODE_OUTPUT_PHASE_CORRECT_SCUCCD
							
			 
*******************************************************************************************************/
#define TMR0_OVF_INTERRUPT 0
#define TMR0_COMP_MATCH_INTERRUPT 1
#define MAX_NOTIFY_FUNC 2
/*****************************************************FUNCTIONS PROTOTYPES***********************************************/
typedef void (*CBF_t)(void);

void TMR0_vidInitPreCompile(void);
void TMR0_vidInitPostCompile(TMR0Config_t *);
TMR0_enuErrorStatus TMR0_enuSetTickTimeMS(u16 Copy_u16TickTime, u32 Copy_u32Clock);
//TMR0_enuErrorStatus TMR0_enuStart(void);
TMR0_enuErrorStatus TMR0_enuRegisterCallback(CBF_t , u8 Index);
TMR0_enuErrorStatus TMR0_enuSetCompareValue(u8);
TMR0_enuErrorStatus TMR0_enuSetTimerValue(u8);
TMR0_enuErrorStatus TMR0_enuSetDutyCycle_NonInverted(u8);
TMR0_enuErrorStatus TMR0_enuSetDutyCycle_Inverted(u8 Cpy_u8DutyCycle);

#endif