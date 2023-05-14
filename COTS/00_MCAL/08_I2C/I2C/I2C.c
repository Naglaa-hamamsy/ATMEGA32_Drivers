#include "STD_Types.h"
#include "BIT_Math.h"
#include "I2C.h"
#include "I2C_Cfg.h"
/********************DEFINES******************/
#define TWDR ((volatile u8 *)0x23)
#define TWAR ((volatile u8 *)0x22)
#define TWSR ((volatile u8 *)0x21)
#define TWBR ((volatile u8 *)0x20)
#define TWI_EN 2
#define START_COND 5
#define STOP_COND 4
#define TWINT_FLAG 7
#define TWI_ACK_EN 6

#define STATUS_START                     0x08
#define STATUS_MW_SLA_W_ACK                 0x18
#define STATUS_MW_SLA_W_NACK                0x20
#define STATUS_MW_DATA_ACK                  0x28
#define STATUS_MW_DATA_NACK                 0x30
#define STATUS_MW_ARBITRATION_LOST          0x38
#define STATUS_REPEATED_START 0x10
#define STATUS_MR_SLA_R_ACK 0x40
#define STATUS_MR_DATA_ACK 0x50
/*************************STATIC FUNCTIONS PROTOTYPE**************************/
static u8 Get_Status(void);
void TWI_vidMasterInit(u8 Cpy_u8SlaveAddress)
{
	u8 Local_Reg = 0;
	/*Set Clock Frequency*/
	/*First, Set Prescaler Value*/
	Local_Reg = TWSR;
	Local_Reg |= TWI_PRESCALER;
	TWSR = Local_Reg;
	/*Second, Set TWBR Value*/
	TWBR = TWI_TWBR_VALUE;
	if(Cpy_u8SlaveAddress != 0)
	{
		TWAR = (Cpy_u8SlaveAddress << 1) | (GENERAL_CALL << 0); 
	}
	/*Enable Acknowledge */
	TWCR |= 1<<TWI_ACK_EN;
	/*Enable TWI */
	TWCR |= 1<<TWI_EN;
	
}
void TWI_vidSlaveInit(u8 Cpy_u8SlaveAddress)
{
	/*Initialize The Node Address*/
	TWAR = (Cpy_u8SlaveAddress << 1) | (GENERAL_CALL << 0); 
	/*Enable Acknowledge */
	TWCR |= 1<<TWI_ACK_EN;
		/*Enable TWI */
		TWCR |= 1<<TWI_EN;
}
TWI_tenuErrorStatus TWI_enuSendStartCondition(void)
{
	TWI_tenuErrorStatus LocalErrorStatus = TWI_enuOK;
	/*Send Start Condition*/
	TWCR |= 1<<START_COND;
	/*Clear the flag to start the previous operation*/
		TWCR |= 1<<TWINT_FLAG;
	/*Wait For The Flag To Be Set*/
	while(!(TWCR & (1<<TWINT_FLAG)));
	/*Clear Start Condition*/
	TWCR &= ~(1<<START_COND);
	/*Get Status Register */
	if(Get_Status() != STATUS_START)
	{
		LocalErrorStatus = TWI_enuStartConditionError;
	}
	else
	{
		/*Do Nothing*/
	}
	return LocalErrorStatus;
}
TWI_tenuErrorStatus TWI_enuSendRepeatedStart(void)
{
		TWI_tenuErrorStatus LocalErrorStatus = TWI_enuOK;
		/*Send Start Condition*/
		TWCR |= 1<<START_COND;
		/*Clear the flag to start the previous operation*/
		TWCR |= 1<<TWINT_FLAG;
		/*Wait For The Flag To Be Set*/
		while(!(TWCR & (1<<TWINT_FLAG)));
			/*Clear Start Condition*/
			TWCR &= ~(1<<START_COND);
		/*Get Status Register */
		if(Get_Status() != STATUS_REPEATED_START)
		{
			LocalErrorStatus = TWI_enuRepeatedStartError;
		}
		else
		{
			/*Do Nothing*/
		}
		return LocalErrorStatus;
}
TWI_tenuErrorStatus TWI_enuSendSlaveAddressWithWrite(u8 Cpy_u8SlaveAddress)
{
	TWI_tenuErrorStatus LocalErrorStatus = TWI_enuOK;
	/*Send SLA+W*/
	TWDR &= ~(1<<0);
	TWDR = Cpy_u8SlaveAddress << 1 ;
	/*Clear the flag to start the previous operation*/
	TWCR |= 1<<TWINT_FLAG;
	/*Wait For The Flag To Be Set*/
	while(!(TWCR & (1<<TWINT_FLAG)));
	/*Get Status Register */
	if(Get_Status() != STATUS_MW_SLA_W_ACK)
	{
		LocalErrorStatus =	TWI_enuSLA_W_Error;
	}
	else
	{
		/*Do Nothing*/
	}
	return LocalErrorStatus;
	
}
TWI_tenuErrorStatus TWI_enuSendSlaveAddressWithRead(u8 Cpy_u8SlaveAddress)
{
		TWI_tenuErrorStatus LocalErrorStatus = TWI_enuOK;
		/*Send SLA+R*/
		TWDR = (Cpy_u8SlaveAddress << 1) | (1<<0) ;
		/*Clear the flag to start the previous operation*/
		TWCR |= 1<<TWINT_FLAG;
		/*Wait For The Flag To Be Set*/
		while(!(TWCR & (1<<TWINT_FLAG)));
		/*Get Status Register */
		if(Get_Status() != STATUS_MR_SLA_R_ACK)
		{
			LocalErrorStatus = 	TWI_enuSLA_R_Error;
		}
		else
		{
			/*Do Nothing*/
		}
		return LocalErrorStatus;
}
TWI_tenuErrorStatus TWI_enuMasterWriteDataByte(u8 Cpy_u8DataByte)
{
	TWI_tenuErrorStatus LocalErrorStatus = TWI_enuOK;
	/*Send SLA+R*/
	TWDR = Cpy_u8DataByte;
	/*Clear the flag to start the previous operation*/
	TWCR |= 1<<TWINT_FLAG;
	/*Wait For The Flag To Be Set*/
	while(!(TWCR & (1<<TWINT_FLAG)));
	/*Get Status Register */
	if(Get_Status() != STATUS_MW_DATA_ACK)
	{
		LocalErrorStatus = 	TWI_enuMW_DATA_ACK_Error;
	}
	else
	{
		/*Do Nothing*/
	}
	return LocalErrorStatus;
}
TWI_tenuErrorStatus TWI_enuMasterReadDataByte(u8 * Add_pu8DataByte)
{
	
	TWI_tenuErrorStatus LocalErrorStatus = TWI_enuOK;
	/*Clear the flag to start the previous operation*/
	TWCR |= 1<<TWINT_FLAG;
	/*Wait For The Flag To Be Set*/
	while(!(TWCR & (1<<TWINT_FLAG)));
	/*Get Status Register */
	if(Get_Status() != STATUS_MR_DATA_ACK)
	{
		LocalErrorStatus = 	TWI_enuMR_DATA_ACK_Error;
	}
	else
	{
			/*Read The Data ON Bus*/
			*Add_pu8DataByte = TWDR;
	}
	return LocalErrorStatus;
}
void TWI_enuSendStopCondition(void)
{
	/*Send Start Condition*/
	TWCR |= 1<<STOP_COND;
	/*Clear the flag to start the previous operation*/
	TWCR |= 1<<TWINT_FLAG;

	
}
/******************************STATIC FUNCTIONS IMPLEMENTATION**************************/

static u8 Get_Status(void)
{
	return TWSR & 0xf8;
}
