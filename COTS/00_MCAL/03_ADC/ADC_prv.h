#ifndef ADC_PRV_H
#define ADC_PRV_H
/* ****************DEFINES*********** */
#define ADMUX_REG *((volatile u8*)0x27)
#define ADCSRA_REG *((volatile u8*)0x26)
#define ADCH_REG *((volatile u8*)0x25)
#define ADCL_REG *((volatile u16*)0x24)
#define SFIOR_REG *((volatile u8*)0x50)
#define ADMUX_ADLAR_PIN 5  
#define ADC_REF_SELECTION_CLEAR_MASK 0xc0 // w fl clear hstkhdm toggle ~
#define ADC_PRESCALER_CLEAR_MASK 0x07
#define ADCSRA_ADEN_PIN 7
#define ADCSRA_ADSC_PIN 6
#define ADCSRA_ADATE_PIN 5
#define ADCSRA_ADIF_PIN 4
#define ADCSRA_ADIE_PIN 3
#define AUTO_TRIGGER_SOURCE_CLEAR_MASK 0xE0
#define IDLE 0
#define BUSY 1
#define ADC_CHAINING 0
#define ADC_NOT_CHAINING 1
#define ADC_Channel_Mask 0x1f



#endif