#include "BIT_Math.h"
#include "GlobalInterrupt_prv.h"
#include "GlobalInterrupt_cfg.h"



 /* **************************************** */
/* Global Interrupt Enable Function
 Input:void
 Output: void*/
 /* ***************************************** */
void GlobalInterupt_vidEnable(void)
{
	SET_BIT(SREG_REG,GLOBAL_INTERRUPT_PIN);
	
}
 /* **************************************** */
/* Global Interrupt Disable Function
 Input:void
 Output: void*/
 /* ***************************************** */

void GlobalInterupt_vidDisable(void)
{
	
	CLR_BIT(SREG_REG,GLOBAL_INTERRUPT_PIN);
}
