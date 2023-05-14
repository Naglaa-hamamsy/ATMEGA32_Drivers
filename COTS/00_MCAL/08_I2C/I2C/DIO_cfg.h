/******************************************/

/*DIO Configuration File*/
/******************************************/
#ifndef DIO_CFG_H
#define DIO_CFG_H
/*  There macros are in cfg not in .h as its used in cfg files only, we dont use it as parameters to functions*/
#define DIO_DIR_INPUT 0
#define DIO_DIR_OUTPUT 1

#define DIO_INPUT_PULLUP 0
#define DIO_INPUT_PULLDOWN 1

typedef struct{
	u8 DIO_PinDirection; //output or input
	u8 DIO_InputStatus; //pull up or down
	
}DIO_strPinCfg_t;

/* making array of struct DIO_strPinCfg_t */

extern const DIO_strPinCfg_t DIO_strPinCfg [32]; //array of pins ==> const as its not allowed to change it in runtime




#endif /*DIO_CFG_H*/