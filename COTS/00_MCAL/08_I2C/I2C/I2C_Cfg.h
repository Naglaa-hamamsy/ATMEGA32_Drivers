/*Clock Frequency Is For Master Mode Only*/
#define TWI_PRESCALER_1 0b00000000
#define TWI_PRESCALER_4 0b00000001
#define TWI_PRESCALER_16 0b00000010
#define TWI_PRESCALER_64  0b00000011
/*Select The Prescaler*/
#define TWI_PRESCALER TWI_PRESCALER_1
/*Select TWBR Value*/
#define TWI_TWBR_VALUE 2
/*Select General call Enable/Disable */
#define ENABLE 1
#define DISABLE 0
#define GENERAL_CALL ENABLE
