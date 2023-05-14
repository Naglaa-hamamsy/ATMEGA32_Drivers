
#include "STD_Types.h"
#include "BIT_Math.h"
#include "SPI_Cfg.h"
#include "SPI.h"


/************************************************DEFINES***************************************/
#define SPDR  *((volatile u8*)0x2F)
#define SPSR *((volatile u8*)0x2E)
#define SPCR *((volatile u8*)0x2D)
#define SPI_ENABLE_PIN 6
#define SPI_TRANSFER_FLAG 7
#define SPI_INTERRUPT_ENABLE_PIN 7
#define TIME_OUT 1000
/*Clear Masks*/
#define DATA_ORDER_CLR_MASK 0b00100000
#define MODE_CLR_MASK 0b00010000
#define CLOCK_POLARITY_CLR_MASK 0b00001000
#define CLOCK_PHASE_CLR_MASK 0b00000100
#define PRESCALER_CLR_MASK 0b00000011
#define DOUBLE_SPEED_CLR_MASK 0b00000001
/* Static variables defines*/
#define IDLE 0
#define BUSY 1

/***********************************************STATIC VARIABLES***********************************************/
static u8  SPI_State = IDLE;
static u8 * TransmitBuffer = NULL ;
static u8 * ReceiveBuffer = NULL;
static u8 BufferSize = 0;
static u8 BufferIdx = 0;
static CBF_t SPI_CBF = NULL;

/************************************************FUNCTIONS IMPLEMENTATION***************************************/
void SPI_vidMasterInit(void)
{
	u8 Local_Reg = 0;
	Local_Reg = SPCR;
	/*Configure Data Order*/
	Local_Reg &= ~DATA_ORDER_CLR_MASK;
	Local_Reg |= SPI_Cfg[MODE_MASTER].DataOrder;
	SPCR = Local_Reg;
	/*Configure Mode*/
	Local_Reg = SPCR;
	Local_Reg &= ~MODE_CLR_MASK;
	Local_Reg |= Mode_enuMaster;
	SPCR = Local_Reg;
	/*Configure Clock Polarity*/
		Local_Reg = SPCR;
	Local_Reg &= ~CLOCK_POLARITY_CLR_MASK;
	Local_Reg |= SPI_Cfg[MODE_MASTER].ClockPolarity;
	SPCR = Local_Reg;
	/*Configure Clock Phase*/
		Local_Reg = SPCR;
	Local_Reg &= ~CLOCK_PHASE_CLR_MASK;
	Local_Reg |= SPI_Cfg[MODE_MASTER].ClockPhase;
	SPCR = Local_Reg;
	/*Configure The Prescaler*/
		Local_Reg = SPCR;
	Local_Reg &= ~PRESCALER_CLR_MASK;
	Local_Reg |= SPI_Cfg[MODE_MASTER].Prescaler;
	SPCR = Local_Reg;
	/*Save These Changes In SPCR*/
	//SPCR = Local_Reg;
	
	/*Enable SPI*/
	SPCR |= 1<< SPI_ENABLE_PIN;
	

}
void SPI_vidSlaveInit(void)
{
	u8 Local_Reg = 0;
	Local_Reg = SPCR;
	/*Configure Data Order*/
	Local_Reg &= ~DATA_ORDER_CLR_MASK;
	Local_Reg |= SPI_Cfg[MODE_SLAVE].DataOrder;
	
	/*Configure Mode*/
	Local_Reg &= ~MODE_CLR_MASK;
	Local_Reg |= Mode_enuSlave;
	
	/*Configure Clock Polarity*/
	Local_Reg &= ~CLOCK_POLARITY_CLR_MASK;
	Local_Reg |= SPI_Cfg[MODE_SLAVE].ClockPolarity;
	
	/*Configure Clock Pahse*/
	Local_Reg &= ~CLOCK_PHASE_CLR_MASK;
	Local_Reg |= SPI_Cfg[MODE_SLAVE].ClockPhase;
	
	
	/*Save These Changes In SPCR*/
	SPCR = Local_Reg;
	
	/*Enable SPI*/
	SPCR |= 1<< SPI_ENABLE_PIN;
	

}
SPI_tenuErrorStatus SPI_enuTransceiveByteSynch(u8 Cpy_u8Data , u8 * Add_pu8Data)
{
	u16 TimeOut = 0;
	SPI_tenuErrorStatus LocalErrorStatus = SPI_enuOK;
	/*Put Any Data From Master Into SPDR To Initiate The Communication*/
	SPDR = Cpy_u8Data;
	/*Wait Until Data Transmit*/
	while((((SPSR >> SPI_TRANSFER_FLAG) & 0x01) == 0) && (TimeOut < TIME_OUT))
	{
		TimeOut ++ ;
	}
	if ((SPSR >> SPI_TRANSFER_FLAG) & 0x01)
	{
		/*Read SPDR To Clr Flag*/
		/*Receive This Data If Interested*/
		*Add_pu8Data = SPDR;
	}
	else
	{
		LocalErrorStatus = SPI_enuTimeOut;
	}
	return LocalErrorStatus;
}
SPI_tenuErrorStatus SPI_enuTransceiveBufferZeroCpyASynch(u8 * Add_pu8TransmitBuffer, u8* Add_pu8ReceiveBuffer , u8 Cpy_u8Size , CBF_t CBF)
{
	SPI_tenuErrorStatus LocalErrorStatus = SPI_enuOK;
	
	if(SPI_State == BUSY)
	{
		LocalErrorStatus = SPI_enuBusy;	
	}
	else if((Add_pu8TransmitBuffer || Add_pu8ReceiveBuffer) == NULL)
	{
		LocalErrorStatus = SPI_enuNullPtr;
	}
	/*IDLE State */
	else
	{
		SPI_State = BUSY;
		 TransmitBuffer = Add_pu8TransmitBuffer;
		 ReceiveBuffer = Add_pu8ReceiveBuffer;
		 BufferSize	= Cpy_u8Size;
		 BufferIdx = 0;
		 SPI_CBF = CBF;
			  SPDR = TransmitBuffer[BufferIdx];
		 /*Enable Interrupt */
		 SPCR |= 1<< SPI_INTERRUPT_ENABLE_PIN;
	
	}
	return LocalErrorStatus;
}
/*********************HANDLER***********************/

void __vector_12 (void) __attribute__((signal));
void __vector_12 (void)
{
	/*Receive First Byte (First Exchange) */
	if(BufferIdx < BufferSize)
	{
	  ReceiveBuffer[BufferIdx] = SPDR;
	  BufferIdx ++;
	  SPDR = TransmitBuffer[BufferIdx];
	}
	else
	{
		SPI_State = IDLE;
		/*Disable Interrupt*/
		SPCR &= ~ (1<<SPI_INTERRUPT_ENABLE_PIN);
		if(SPI_CBF)
		{
			SPI_CBF();
		}
	}
}