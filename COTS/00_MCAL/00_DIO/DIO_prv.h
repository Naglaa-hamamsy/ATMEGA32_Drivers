/******************************************/

/*DIO Private File*/
/******************************************/
#ifndef DIO_PRV_H
#define DIO_PRV_H
#define PORT_PIN_CHECK 8

#define DIO_PORTA 0
#define DIO_PORTB 1
#define DIO_PORTC 2
#define DIO_PORTD 3

#define PORTA_REG *(volatile u8*)0x3B
#define DDRA_REG  *(volatile u8*)0x3A
#define PINA_REG  *(volatile u8*)0x39

#define PORTB_REG *(volatile u8*)0x38
#define DDRB_REG  *(volatile u8*)0x37
#define PINB_REG  *(volatile u8*)0x36

#define PORTC_REG *(volatile u8*)0x35
#define DDRC_REG  *(volatile u8*)0x34
#define PINC_REG  *(volatile u8*)0x33

#define PORTD_REG *(volatile u8*)0x32
#define DDRD_REG  *(volatile u8*)0x31
#define PIND_REG  *(volatile u8*)0x30





#endif /*DIO_PRV_H*/