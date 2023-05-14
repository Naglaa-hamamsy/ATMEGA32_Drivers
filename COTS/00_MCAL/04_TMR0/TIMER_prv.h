#ifndef TIMER_PRV_H
#define TIMER_PRV_H

/**********************************************TIMER0 REGISTERS*****************************************************/

#define     TCNT0		      *((volatile u8 *)(0x52))	
#define     TCCR0		      *((volatile u8 *)(0x53))	
#define     OCR0		      *((volatile u8 *)(0x5C))
#define     TIMSK		      *((volatile u8 *)(0x59))
#define     TIFR              *((volatile u8 *)(0x58))

/**********************************************MASKS*****************************************************************/
#define TMR0_PRESCALER_CLR_MASK 0b00000111
#define TMR0_MODE_CLR_MASK 0b01001000
#define TMR0_MODE_OUTPUT_CLR_MASK 0b00110000 
/*These defines are for post build init configuration*/

#define TMR0_MODE_OUTPUT_CTC_TOGGLE 0b010001
#define TMR0_MODE_OUTPUT_CTC_CLEAR 0b100001
#define TMR0_MODE_OUTPUT_CTC_SET 0b110001
#define TMR0_MODE_OUTPUT_FPWM_CCST 0b101001
#define TMR0_MODE_OUTPUT_FPWM_SCCT 0b111001
#define TMR0_MODE_OUTPUT_PHASE_CORRECT_CCUSCD 0b101000
#define TMR0_MODE_OUTPUT_PHASE_CORRECT_SCUCCD 0b111000
#define TMR0_MODE_OUTPUT_NORMAL 0b00000000

/*Clear Masks for Mode & Behavior used in post build configurations */
#define TMR0_MODE_POST_BUILD_CLR_MASK 0b001111
#define TMR0_OVERFLOW_VALUE 255
#define TMR0_OVER_FLOW_INTERRUPT_ENABLE_PIN 0
#define TMR0_COMPARE_MATCH_INTERRUPT_ENABLE_PIN 1
#define TMR0_MAX_TICKS 256
#define TMR0_COM00_PIN 4
#endif