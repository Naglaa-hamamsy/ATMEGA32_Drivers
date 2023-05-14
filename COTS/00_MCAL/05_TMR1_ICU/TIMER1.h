#ifndef TIMER1_H
#define TIMER1_H

typedef void ( *CBF_t )(void);
typedef enum
{
	TMR1_enuOK,
	TMR1_enuNOK,
	TMR1_enuNullPtr,
	
}TMR1_tenuErrorStatus;
void TMR1_init(void);
void TMR1_ICU_INIT(void);
TMR1_tenuErrorStatus TMR1_ICU_SetEdge(u8);
TMR1_tenuErrorStatus  TMR1_ICU_SetCallBack(CBF_t CBF);
u16 TMR1_ICU_u16GetICR(void);
TMR1_tenuErrorStatus TMR1_ICU_INTERRUPT_STATE(u8);
 TMR1_tenuErrorStatus TMR1_enuSetTimerValue(u16);
 TMR1_tenuErrorStatus TMR1_OVF_SetCallBack(CBF_t CBF);
#endif