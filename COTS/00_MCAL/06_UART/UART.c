#include "STD_Types.h"
#include "BIT_Math.h"
#include "UART.h"
#include "UART_Cfg.h"
/******************************************DEFINES********************************************/
#define SPEED_PIN 1
#define MULTIPROCESSOR_PIN 0
#define UART_MODE_MASK 0b01000000
#define TXEN 3
#define RXEN 4
#define URSEL 7
#define UART_PARITY_MASK 0b00110000
#define UART_STOP_MASK 0b00001000
#define UART_DATA_MASK 0b00000110
#define UCSZ2 2
#define UART_POLARITY_MASK 0b00000001
#define UBRRH_CLR_MASK 0b00001111
#define UART_DATA_EMPTY 5
#define UART_TRANSMIT_COMPLETE 6
#define UART_RECEIVE_COMPLETE 7
#define UART_TRANSMIT_BIT8 0
#define UART_RECEIVE_BIT8 1
#define IDLE 0
#define BUSY 1
#define UART_TRANSMIT_INTERRUPT_EN 6
#define UART_RECEIVE_INTERRUPT_EN  7
#define UART_DATA_EMPTY_INTERRUPT_EN  5
/******************************************REGISTERS ADDRESSES********************************************/
#define UCSRA *((volatile u8 *)0x2B)
#define UCSRB *((volatile u8*)0x2A)
#define UCSRC *((volatile u8*)0x40)
#define UBRRL *((volatile u8*)0x29)
#define UBRRH *((volatile u8*)0x40)
#define UDR *((volatile u8*)0x2C)

/*******************************************STATIC FUNCTIONS***********************************************/
static u8 UART_DataEmptyFlag = 0;
static u8 UART_STATE = IDLE;
static CBF_t UART_TransmitCBF = NULL;
static u16 UART_DATA = 0;

static void voidBaudRate_CALC(void);


/*****************************************FUNCTIONS IMPLEMENTATION****************************************/

void UART_vidInit(void)
{
	u8 Local_Reg = 0;
	
	/*UCSRC REGISTER*/
	/*Select Accessing UCSRC*/
	Local_Reg =1<<URSEL;
	/* Select Synchronous or Asynchronous*/
	//Local_Reg = UCSRC;
	Local_Reg &=~UART_MODE_MASK;
	Local_Reg |= UART_MODE;
	
	//UCSRC = Local_Reg;
	
	/*Selecting Parity Mode*/
	//Local_Reg = UCSRC;
	Local_Reg &=~UART_PARITY_MASK;
	Local_Reg |= UART_PARITY;
	//UCSRC = Local_Reg;
	
	/*Select Stop Bits*/
	//Local_Reg = UCSRC;
	Local_Reg &=~UART_STOP_MASK;
	Local_Reg |= UART_STOP_BITS;
	//UCSRC = Local_Reg;
	
	/*Select Data Bits*/
	#if UART_DATA_BITS == UART_DATA_9BIT
		SET_BIT(UCSRB,UCSZ2);

	#else 
		CLR_BIT(UCSRB,UCSZ2);
		#endif
	//Local_Reg = UCSRC;
	Local_Reg &=~UART_DATA_MASK;
	Local_Reg |= UART_DATA_8BIT;
	//UCSRC = Local_Reg;
	
	
	/* SELECT POLARITY*/
	#if UART_MODE == UART_MODE_SYNCHRONOUS
			//Local_Reg = UCSRC;
			Local_Reg &=~UART_POLARITY_MASK;
			Local_Reg |= UART_POLARITY;
	#endif
			UCSRC = Local_Reg;

	

	
		/*UCSRA REGISTER*/
		
	/*Select Normal / Double Speed For ASynchronous Mode*/
	#if ((UART_MODE == UART_MODE_ASYNCHRONOUS) && (UART_ASYNCH_SPEED_DOUBLE == ENABLE))
			SET_BIT(UCSRA,SPEED_PIN);
	#endif
	/* Select MultiProcessor*/
	#if UART_MULTIPROCESSOR == ENABLE
		SET_BIT(UCSRA,MULTIPROCESSOR_PIN);
	#endif
	
		/*UCSRB REGISTER*/
		/*Enable Tx */
		SET_BIT(UCSRB,TXEN);
		/*Enable Rx*/
		SET_BIT(UCSRB,RXEN);
		
	/*Select Baud Rate*/
//	voidBaudRate_CALC();		
UBRRH = 0;
UBRRL = 51;
}
/*****************************************STATIC FUNCTIONS IMPLEMENTATION**************************/
void voidBaudRate_CALC(void)
{
	u16 Local_Reg = 0;
	u16 Local_calc_reg = 0;
	#if UART_MODE == UART_MODE_ASYNCHRONOUS 
		#if UART_ASYNCH_SPEED_DOUBLE == DISABLE
			Local_Reg = (u16)(FREQUENCY/ (u16)(16 * BAUDRATE)) - 1;
		#elif UART_ASYNCH_SPEED_DOUBLE == ENABLE
		Local_Reg = (u16)(FREQUENCY/ (u16)(8 * BAUDRATE)) - 1;
		#endif
	#elif UART_MODE == UART_MODE_SYNCHRONOUS 
		Local_Reg = (u16)(FREQUENCY/ (u16)(2 * BAUDRATE)) - 1;
	#endif
		Local_calc_reg = Local_Reg;
		/*Clear The Upper 8 Bits To Extract Only The Lower 8 Bits*/
		/*#if UART_DATA_BITS == UART_DATA_9BIT
		Local_calc_reg <<= 8;
		Local_calc_reg >>= 8;
		*/
		UBRRL = Local_Reg;
		/* Extract The Higher 8 Bits*/
		UBRRH = (u8)((Local_Reg >> 8) & (UBRRH_CLR_MASK));
		
		
}
UART_tenuErrorStatus UART_enuSynchSendData(u16 Cpy_u16Data)
{
	/*Wait Until Data Buffer Is Empty*/
	//while(!GET_BIT(UCSRA,UART_DATA_EMPTY));
	
	/*Send Data*/
	/*Check On The 9th Bit*/
//	if(Cpy_u16Data & 0x0100)
	//{
		//SET_BIT(UCSRB,UART_TRANSMIT_BIT8);
	//}
	//else
	//{
	//CLR_BIT(UCSRB,UART_TRANSMIT_BIT8);
	//}
	UDR = Cpy_u16Data;
	/*Wait Until Making Sure That All Data Is Sent*/
	while(!GET_BIT(UCSRA,UART_TRANSMIT_COMPLETE));
	
	return UART_enuOK; 
}
UART_tenuErrorStatus UART_enuSynchReceiveData(u16 * Cpy_u16Data)
{
	u8 Low_Bits = 0;
	u8 High_Bits = 0;
	u8 Local_Reg ;
	while(!GET_BIT(UCSRA,UART_RECEIVE_COMPLETE));
	/*Read The 9th Bit First*/
	High_Bits = GET_BIT(UCSRA,UART_RECEIVE_BIT8);
	/*Read The Low 8 Bits*/
	Low_Bits = UDR;
	Cpy_u16Data = (Low_Bits | High_Bits);
	
	return UART_enuOK;
}
UART_tenuErrorStatus UART_enuASynchSendData(u16 Cpy_u16Data,CBF_t Cpy_TransmitCBF)
{
	UART_tenuErrorStatus LocalErrorStatus = UART_enuOK;
	

		if(UART_STATE == IDLE)
		{
			if(Cpy_TransmitCBF == NULL)
			{
				LocalErrorStatus = UART_enuNullPtr;
			}
			else
			{	
				/*Make UART State Busy*/
				UART_STATE = BUSY;
				while(!GET_BIT(UCSRA,UART_DATA_EMPTY));
			/*Send Data*/
				if(Cpy_u16Data & 0x0100)
				{
					SET_BIT(UCSRB,UART_TRANSMIT_BIT8);
				}
				else
				{
					CLR_BIT(UCSRB,UART_TRANSMIT_BIT8);
				}
				UDR = Cpy_u16Data;
				/*Make CBF Global For ISR*/
				UART_TransmitCBF = Cpy_TransmitCBF;
				/*Enable Data Empty Interrupt*/
			 UCSRB |=UART_DATA_EMPTY_INTERRUPT_EN;
			/*Enable Transmit Interrupt*/
			 UCSRB |=1<<UART_TRANSMIT_INTERRUPT_EN;
			 
			}
		}
		else
		{
			LocalErrorStatus = UART_enuBusy;
		}
	return LocalErrorStatus;
}

/*ISR OF DATA EMPTY*/

void __vector_14 (void) __attribute__((signal));
void __vector_14 (void)
{
	UART_DataEmptyFlag = 1;
}
/* ISR Of Rx Complete*/
void __vector_13 (void) __attribute__((signal));
void __vector_13 (void)
{
	
}
/* ISR OF Tx Complete*/
void __vector_15 (void) __attribute__((signal));
void __vector_15 (void)
{
	UART_TransmitCBF();
}