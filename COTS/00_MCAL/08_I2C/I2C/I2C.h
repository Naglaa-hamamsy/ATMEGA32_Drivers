typedef enum
{
	TWI_enuOK,
	TWI_enuNOK,
	TWI_enuStartConditionError,
	TWI_enuRepeatedStartError,
	TWI_enuSLA_W_Error,
	TWI_enuSLA_R_Error,
	TWI_enuMW_DATA_ACK_Error,
	TWI_enuMR_DATA_ACK_Error
}TWI_tenuErrorStatus;

/*If Passed 0 , then it's a master and address is not required*/
void TWI_vidMasterInit(u8 Cpy_u8SlaveAddress);
void TWI_vidSlaveInit(u8 Cpy_u8SlaveAddress);
TWI_tenuErrorStatus TWI_enuSendStartCondition(void);
TWI_tenuErrorStatus TWI_enuSendRepeatedStart(void);
TWI_tenuErrorStatus TWI_enuSendSlaveAddressWithWrite(u8 Cpy_u8SlaveAddress);
TWI_tenuErrorStatus TWI_enuSendSlaveAddressWithRead(u8 Cpy_u8SlaveAddress);
TWI_tenuErrorStatus TWI_enuMasterWriteDataByte(u8 Cpy_u8DataByte);
TWI_tenuErrorStatus TWI_enuMasterReadDataByte(u8 * Add_pu8DataByte);
void TWI_enuSendStopCondition(void);


