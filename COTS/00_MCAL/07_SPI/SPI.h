/*************************************DEFINES****************************************/

/*************************************TYPES****************************************/
typedef enum
{
	SPI_enuOK,
	SPI_enuNOK,
	SPI_enuTimeOut,
	SPI_enuBusy,
	SPI_enuNullPtr,
}SPI_tenuErrorStatus;

typedef void(*CBF_t)(void);
/*************************************PROTOTYPES****************************************/
void SPI_vidMasterInit(void);
void SPI_vidSlaveInit(void);
SPI_tenuErrorStatus SPI_enuTransceiveByteSynch(u8, u8*);
SPI_tenuErrorStatus SPI_enuTransceiveBufferZeroCpyASynch(u8 * Add_pu8TransmitBuffer, u8* Add_pu8ReceiveBuffer , u8 Cpy_u8Size , CBF_t CBF);

