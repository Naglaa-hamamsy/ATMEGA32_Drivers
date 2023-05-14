
#include "STD_Types.h"
#include "BIT_Math.h"
#include "SPI_Cfg.h"
#include "SPI.h"

const SPI_Cfg_t SPI_Cfg[NUMBER_OF_MODES] = 
{
	[MODE_MASTER] = 
	{
		.Mode = Mode_enuMaster,
		.Prescaler = Prescaler_enuDivide_16,
		.ClockPhase = ClockPhase_enuSample_Setup,
		.ClockPolarity = ClockPolarity_enuIdleLow,
		.DataOrder = DataOrder_enuMSB,
		.DoubleSpeed = DoubleSpeed_enuDisable
	},
	[MODE_SLAVE] =
	{
		.Mode = Mode_enuSlave,
		.ClockPhase = ClockPhase_enuSample_Setup,
		.ClockPolarity = ClockPolarity_enuIdleLow,
		.DataOrder = DataOrder_enuMSB,
		.DoubleSpeed = DoubleSpeed_enuDisable
		/*Note That No Prescaler In Slave Mode*/
	}
};