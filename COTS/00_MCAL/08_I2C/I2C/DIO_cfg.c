/*
 * DIO_cfg.c
 *
 * Created: 17/01/2023 19:02:24
 *  Author: naglaaa
 */ 
#include "STD_Types.h"
#include "DIO_Cfg.h"
/* making array of struct DIO_strPinCfg_t */
 const DIO_strPinCfg_t DIO_strPinCfg [32]= //array of pins ==> const as its not allowed to change it in runtime
{
	
	/*Pin Direction*/ /*Pull Up Pull Down if input pin*/
	//If the pin is output, ignore input status
	//If you start any project, fill this array with the wanted pins
	
	/*PORTA*/
	
	/*PIN0*/{DIO_DIR_OUTPUT,DIO_INPUT_PULLDOWN},
	/*PIN1*/{DIO_DIR_OUTPUT,DIO_INPUT_PULLDOWN},
	/*PIN2*/{DIO_DIR_OUTPUT,DIO_INPUT_PULLDOWN},
	/*PIN3*/{DIO_DIR_OUTPUT,DIO_INPUT_PULLDOWN},
	/*PIN4*/{DIO_DIR_INPUT,DIO_INPUT_PULLUP},
	/*PIN5*/{DIO_DIR_INPUT,DIO_INPUT_PULLUP},
	/*PIN6*/{DIO_DIR_INPUT,DIO_INPUT_PULLUP},
	/*PIN7*/{DIO_DIR_INPUT,DIO_INPUT_PULLUP},
		
		
		/*PORTB*/
		
	/*PIN8*/{DIO_DIR_OUTPUT,DIO_INPUT_PULLDOWN},
	/*PIN9*/{DIO_DIR_OUTPUT,DIO_INPUT_PULLDOWN},
	/*PIN10*/{DIO_DIR_OUTPUT,DIO_INPUT_PULLDOWN},
	/*PIN11*/{DIO_DIR_OUTPUT,DIO_INPUT_PULLDOWN},
	/*PIN12*/{DIO_DIR_INPUT,DIO_INPUT_PULLUP},
	/*PIN13*/{DIO_DIR_OUTPUT,DIO_INPUT_PULLDOWN},
	/*PIN14*/{DIO_DIR_INPUT,DIO_INPUT_PULLDOWN},
	/*PIN15*/{DIO_DIR_OUTPUT,DIO_INPUT_PULLDOWN},
		
		/*PORTC*/
		
		
	/*PIN16*/{DIO_DIR_OUTPUT,DIO_INPUT_PULLDOWN},
	/*PIN17*/{DIO_DIR_OUTPUT,DIO_INPUT_PULLDOWN},
	/*PIN18*/{DIO_DIR_OUTPUT,DIO_INPUT_PULLDOWN},
	/*PIN19*/{DIO_DIR_OUTPUT,DIO_INPUT_PULLDOWN},
	/*PIN20*/{DIO_DIR_OUTPUT,DIO_INPUT_PULLDOWN},
	/*PIN21*/{DIO_DIR_OUTPUT,DIO_INPUT_PULLDOWN},
	/*PIN22*/{DIO_DIR_OUTPUT,DIO_INPUT_PULLDOWN},
	/*PIN23*/{DIO_DIR_OUTPUT,DIO_INPUT_PULLDOWN},
		
		
		/*PORTD*/
		
	/*PIN24*/{DIO_DIR_OUTPUT,DIO_INPUT_PULLDOWN},
	/*PIN25*/{DIO_DIR_OUTPUT,DIO_INPUT_PULLDOWN},
	/*PIN26*/{DIO_DIR_OUTPUT,DIO_INPUT_PULLUP},
	/*PIN27*/{DIO_DIR_OUTPUT,DIO_INPUT_PULLUP},
	/*PIN28*/{DIO_DIR_OUTPUT,DIO_INPUT_PULLDOWN},
	/*PIN29*/{DIO_DIR_OUTPUT,DIO_INPUT_PULLDOWN},
	/*PIN30*/{DIO_DIR_OUTPUT,DIO_INPUT_PULLDOWN},
	/*PIN31*/{DIO_DIR_OUTPUT,DIO_INPUT_PULLDOWN}
	
	
	
};
