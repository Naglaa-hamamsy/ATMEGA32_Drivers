typedef enum
{	MODE_MASTER,
	MODE_SLAVE,
	NUMBER_OF_MODES
}MODES_t;
typedef enum
{
	DataOrder_enuLSB = 0b00100000,
	DataOrder_enuMSB = 0b00000000
}DataOrder_t;
typedef enum
{
	Mode_enuMaster = 0b00010000,
	Mode_enuSlave =  0b00000000
	
}Mode_t;
typedef enum
{
	ClockPolarity_enuIdleHigh = 0b00001000,
	ClockPolarity_enuIdleLow = 0b00000000
}ClockPolarity_t;
typedef enum
{
	ClockPhase_enuSample_Setup = 0b00000000,
	ClockPhase_enuSetup_Sample = 0b00000100,
	
}ClockPhase_t;
typedef enum
{
	Prescaler_enuDivide_4,
	Prescaler_enuDivide_16 ,
	Prescaler_enuDivide_64 ,
	Prescaler_enuDivide_128 ,
	
	
}Prescaler_t;
typedef enum
{
	DoubleSpeed_enuDisable = 0,
	DoubleSpeed_enuEnable = 1
}DoubleSpeed_t;
typedef struct
{
	DataOrder_t DataOrder;
	Mode_t Mode;
	ClockPolarity_t ClockPolarity;
	ClockPhase_t ClockPhase;
	Prescaler_t Prescaler;
	DoubleSpeed_t DoubleSpeed;
	
	
}SPI_Cfg_t;
extern const SPI_Cfg_t SPI_Cfg[NUMBER_OF_MODES];