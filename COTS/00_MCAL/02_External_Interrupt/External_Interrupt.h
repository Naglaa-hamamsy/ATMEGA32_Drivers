#ifndef EXTERNAL_INTERRUPT_H
#define EXTERNAL_INTERRUPT_H

/* **************************************** */
/* External interrupt Initialization Function
 Input:Void
 Output:Void*/
 /* ***************************************** */
void EXTI_vidInit(void);
u8 EXTI_SetCallBackFunc(void(*PtrToFunc)(void),u8 index);
#define EXTI_OK 0
#define EXTI_NOK 1

#endif
