#ifndef TIMER_CFG_H
#define TIMER_CFG_H
/*This File Is Used Mainly For Pre-Build Configurations*/
/***************************************************DEFINES***********************************************************/
/**********************************************SELECT CLOCK SOURCE*****************************************************/
/*These prescalers used in prebuild & postbuild configurations*/
#define TMR0_PRESCALER_DIV_1 0x01
#define TMR0_PRESCALER_DIV_8 0x02
#define TMR0_PRESCALER_DIV_64 0x03
#define TMR0_PRESCALER_DIV_256 0x04
#define TMR0_PRESCALER_DIV_1024 0x05
#define TMR0_EXT_CLK_FALLING 0x06
#define TMR0_EXT_CLK_RISING 0x07

#define TMR0_CLK_SOURCE  TMR0_PRESCALER_DIV_8
/**********************************************SELECT MODE*****************************************************/
#define TMR0_MODE_NORMAL 0b00000000
#define TMR0_MODE_PWM_PHASE_CORRECT 0b01000000
#define TMR0_MODE_CTC 0b00001000
#define TMR0_MODE_FAST_PWM 0b01001000

#define TMR0_MODE TMR0_MODE_OUTPUT_PHASE_CORRECT_SCUCCD

/**********************************************CTC MODE*****************************************************/
#define TMR0_MODE_CTC_TOGGLE 0b00010000
#define TMR0_MODE_CTC_CLEAR 0b00100000
#define TMR0_MODE_CTC_SET 0b00110000

#define TMR0_MODE_CTC_OUTPUT TMR0_MODE_CTC_SET

/**********************************************FAST PWM MODE*****************************************************/

#define TMR0_MODE_FAST_PWM_CCST 0b00100000  /*Clear On Compare , Set On Top*/
#define TMR0_MODE_FAST_PWM_SCCT 0b00110000 /*Set On Compare Clear On Top*/

#define TMR0_MODE_FAST_PWM_OUTPUT TMR0_MODE_FAST_PWM_SCCT

/**********************************************PHASE CORRECT PWM MODE*****************************************************/

/*Clear OC0 On Compare Match When Up_Counting, Set OC0 On Compare Match When Down-Counting*/
#define TMR0_MODE_PWM_PHASE_CORRECT_CCUSCD 0b00100000
/*Set OC0 On Compare Match When Up_Counting, Clear OC0 On Compare Match When Down-Counting*/
#define TMR0_MODE_PWM_PHASE_CORRECT_SCUCCD 0b00110000

#define TMR0_MODE_PWM_PHASE_CORRECT_OUTPUT TMR0_MODE_PWM_PHASE_CORRECT_SCUCCD


#endif