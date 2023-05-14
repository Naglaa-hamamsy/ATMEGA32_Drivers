#ifndef KPAD_H
#define KPAD_H	


/* **************************************** */
/*KeyPad Function to  Get the pressed key
 Input:Void
 Output: The key pressed*/
 /* ***************************************** */
 


typedef enum
{
	KPAD_enuOK,
	KPAD_enuNOK
	}KPAD_enuErrorStatus;
KPAD_enuErrorStatus KPAD_u8GetThePressedKey(u8 * Add_pu8PressedKey);
#endif