#ifndef TIMER1_PRV_H
#define TIMER1_PRV_H

#define		TCCR1A			         *((volatile u8 *)(0x4F))		// Timer/Counter 1 Control Register A
#define		TCCR1B			         *((volatile u8 *)(0x4E))		// Timer/Counter 1 Control Register B
#define		TCNT1L					*((volatile u8 *)(0x4C))		// Timer/Counter 1 Low Register
#define		TCNT1H					*((volatile u8 *)(0x4D))		// Timer/Counter 1 High Register
#define		TCNT1					*((volatile u16 *)(0x4C))		// Timer/Counter 1 Register

#define		OCR1AL					*((volatile u8 *)(0x4A))		// Output Compare 1 Channel A Low Register
#define		OCR1AH					*((volatile u8 *)(0x4B))		// Output Compare 1 Channel A High Register
#define     OCR1A					*((volatile u16 *)(0x4A))		// Output Compare 1 Channel A Register

#define		OCR1BL					*((volatile u8 *)(0x48))		// Output Compare 1 Channel B Low Register
#define		OCR1BH					*((volatile u8 *)(0x49))		// Output Compare 1 Channel B High Register
#define     OCR1B					*((volatile u16 *)(0x48))		// Output Compare 1 Channel B Register

#define		ICR1L					*((volatile u8 *)(0x46))		// Input Capture 1 Low Register
#define		ICR1H					*((volatile u8 *)(0x47))		// Input Capture 1 High Register
#define     ICR1					*((volatile u16 *)(0x46))		// Input Capture 1 Register

#define     TIMSK		      *((volatile u8 *)(0x59))


/***********************************************MASKS**************************************************/
#define TMR1_PRESCALER_MASK 0b00000111
#define TMR1_ICU_EDGE_SELECT_MASK 0b01000000
#define TMR1_ICU_INTERRUPT_MASK 0b00100000
#define TMR1_COMP_MATCHA_INTERRUPT_MASK 0b00010000
#define TMR1_COMP_MATCHB_INTERRUPT_MASK 0b00001000
#define TMR1_OVF_INTERRUPT_MASK 0b00000100
#define TMR1_CLEAR_TCTN1 0
#define TMR1_OVERFLOW 65535
#endif