
/******************************************DEFINES*******************************************/


/******************************************TYPES*******************************************/

typedef enum
{
	UART_enuOK,
	UART_enuNOK,
	UART_enuBusy,
	UART_enuNullPtr
	
}UART_tenuErrorStatus;

typedef void(*CBF_t)(void);
/******************************************INTERFACES*******************************************/
void UART_vidInit(void);
UART_tenuErrorStatus UART_enuSynchSendData(u16 Cpy_u16Data);
UART_tenuErrorStatus UART_enuSynchReceiveData(u16 * Cpy_u16Data);
UART_tenuErrorStatus UART_enuASynchSendData(u16 Cpy_u16Data,CBF_t Cpy_CBF);
UART_tenuErrorStatus UART_enuASynchReceiveData(u16 * Cpy_u16Data,CBF_t Cpy_CBF);