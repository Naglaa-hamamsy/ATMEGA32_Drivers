/******************************************DEFINES*******************************************/

/*Select UART MODE*/
/************OPTIONS******************/
#define UART_MODE_SYNCHRONOUS 0b01000000
#define UART_MODE_ASYNCHRONOUS 0b00000000
/*************************************/
#define UART_MODE  UART_MODE_ASYNCHRONOUS

/*Select Speed Of ASynchronous*/
/************OPTIONS***********/
#define ENABLE 1
#define DISABLE 0
/*******************************/
#define UART_ASYNCH_SPEED_DOUBLE DISABLE

/*Select Multiprocessor Or Not*/
 #define UART_MULTIPROCESSOR ENABLE
 /*Select Parity Mode*/
 /************OPTIONS***************/
 #define UART_PARITY_ODD 0b00110000
 #define UART_PARITY_EVEN 0b00100000
 #define UART_PARITY_DISABLED 0b00000000
 /************************************/
 #define UART_PARITY UART_PARITY_DISABLED
 
 /*Select Stop Bits*/
  /************OPTIONS***************/
  #define UART_STOP_1BIT 0b00000000
  #define UART_STOP_2BIT 0b00001000
  /***********************************/
  #define UART_STOP_BITS UART_STOP_1BIT
  
 /*Select Data Size*/
 /************OPTIONS***************/
#define UART_DATA_5BIT 0b00000000
#define UART_DATA_6BIT 0b00000010
#define UART_DATA_7BIT 0b00000100
#define UART_DATA_8BIT 0b00000110
#define UART_DATA_9BIT 0
/***********************************/
#define UART_DATA_BITS UART_DATA_8BIT
 
/*Select Polarity*/
/************OPTIONS***************/
#define UART_TRANSMIT_RISING_RECEIVE_FALLING 0b00000000
#define UART_TRANSMIT_FALLING_RECEIVE_RISING 0b00000001
/***********************************/
#define UART_POLARITY UART_TRANSMIT_RISING_RECEIVE_FALLING
/*Select Frequency */
/************OPTIONS***************
			1)1 MHZ
			2)1.8432 MHZ
			3)2 MHZ
			4)3.6864 MHZ
			5)4 MHZ
			6)7.3728 MHZ
			7)8 MHZ
			8)11.0592 MHZ
			9)14.7456 MHZ
			10)16 MHZ
			11)18.4320 MHZ
			12)20 MHZ
**********************************/
#define FREQUENCY 8000000UL

/*Select Baud Rate */
/************OPTIONS***************
      	1) 2400
      	2) 4800
      	3) 9600
      	4) 14.4K
      	5) 19.2K
      	6) 28.8K
      	7)38.4K
      	8) 57.6K
      	9) 76.8K
      	10)115.2K
      	11)230.4K
      	12)250K
/**********************************/
#define BAUDRATE 9600