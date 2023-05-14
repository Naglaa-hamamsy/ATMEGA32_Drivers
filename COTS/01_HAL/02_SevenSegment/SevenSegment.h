#ifndef SEVENSEGMENT_H
#define SEVENSEGMENT_H
 #define ZERO 0b00111111
 #define ONE 0b00000110
 #define TWO 0b01011011
 #define THREE 0b01001111
 #define FOUR 0b01100110
 #define FIVE 0b01101101
 #define SIX 0b01111101
 #define SEVEN 0b00000111
 #define EIGHT 0b01111111
 #define NINE 0b01101111

 typedef enum
 {
 SSEG_enuOk,
 SSEG_enuInvalidValue
}SSEG_tenuErrorStatus;

/* **************************************** */
/* Seven Segment Display Function
 Input:Value to display on seven segment
 Output: SevenSegment_tenuErrorStatus to report error*/
 /* ***************************************** */
SSEG_tenuErrorStatus SSEG_enuDisplay(u8 Cpy_u8SSGValue);

 
#endif