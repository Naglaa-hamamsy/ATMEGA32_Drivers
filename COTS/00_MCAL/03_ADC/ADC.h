#ifndef ADC_H
#define ADC_H

/* ****************TYPES*********** */
typedef enum
{
	ADC_enuOK,
	ADC_enuNOK,
	ADC_enuNullPtr,
	ADC_enuBusyFunc
}ADC_tenuErrorStatus;
	
typedef enum
{
	ADC_enuChannel_Single_0,
	ADC_enuChannel_Single_1=0x01,
	ADC_enuChannel_Single_2,
	ADC_enuChannel_Single_3,
	ADC_enuChannel_Single_4,
	ADC_enuChannel_Single_5,
	ADC_enuChannel_Single_6,
	ADC_enuChannel_Single_7,
	ADC_enuChannel_Diff_00_10xG,
	ADC_enuChannel_Diff_10_10xG,
	ADC_enuChannel_Diff_00_200xG,
	ADC_enuChannel_Diff_10_200xG,
	ADC_enuChannel_Diff_22_10xG,
	ADC_enuChannel_Diff32_10xG,
	ADC_enuChannel_Diff_22_200xG,
	ADC_enuChannel_Diff_32_200xG,
	ADC_enuChannel_Diff_01_1xG,
	ADC_enuChannel_Diff_11_1xG,
	ADC_enuChannel_Diff_21_1xG,
	ADC_enuChannel_Diff_31_1xG,
	ADC_enuChannel_Diff_41_1xG,
	ADC_enuChannel_Diff_51_1xG,
	ADC_enuChannel_Diff_61_1xG,
	ADC_enuChannel_Diff_71_1xG,
	ADC_enuChannel_Diff_02_1xG,
	ADC_enuChannel_Diff_12_1xG,
	ADC_enuChannel_Diff_22_1xG,
	ADC_enuChannel_Diff_32_1xG,
	ADC_enuChannel_Diff_42_1xG,
	
}ADC_tenuChannel;
/* ****************INTERFACES*********** */

/* **************************************** */
/* ADC Initialization Function According To Configurations
 Input:Void
 Output: ADC_tenuErrorStatus to report error */
 /* ***************************************** */
ADC_tenuErrorStatus ADC_enuInit(void);
/* **************************************** */
/* ADC Start Conversion Function 
 Input:Void
 Output: ADC_tenuErrorStatus to report error */
 /* ***************************************** */
ADC_tenuErrorStatus ADC_enuStartConversion(void);
/* **************************************** */
/* ADC Select Channel Function 
 Input:ADC_Channel Either Single Ended Or Differential From These Options:
 
		1)ADC_enuChannel_Single_0,
		2)ADC_enuChannel_Single_1,
		3)ADC_enuChannel_Single_2,
		4)ADC_enuChannel_Single_3,
		5)ADC_enuChannel_Single_4,
		6)ADC_enuChannel_Single_5,
		7)ADC_enuChannel_Single_6,
		8)ADC_enuChannel_Single_7,
		9)ADC_enuChannel_Diff_00_10xG,
		10)ADC_enuChannel_Diff_10_10xG,
		11)ADC_enuChannel_Diff_00_200xG,
		12)ADC_enuChannel_Diff_10_200xG,
		13)ADC_enuChannel_Diff_22_10xG,
		14)ADC_enuChannel_Diff32_10xG,
		15)ADC_enuChannel_Diff_22_200xG,
		16)ADC_enuChannel_Diff_32_200xG,
		17)ADC_enuChannel_Diff_01_1xG,
		19)ADC_enuChannel_Diff_11_1xG,
		19)ADC_enuChannel_Diff_21_1xG,
		20)ADC_enuChannel_Diff_31_1xG,
		21)ADC_enuChannel_Diff_41_1xG,
		22)ADC_enuChannel_Diff_51_1xG,
		23)ADC_enuChannel_Diff_61_1xG,
		24)ADC_enuChannel_Diff_71_1xG,
		25)ADC_enuChannel_Diff_02_1xG,
		26)ADC_enuChannel_Diff_12_1xG,
		27)ADC_enuChannel_Diff_22_1xG,
		28)ADC_enuChannel_Diff_32_1xG,
		29)ADC_enuChannel_Diff_42_1xG,
 		
 Output: ADC_tenuErrorStatus to report error */
 /* ***************************************** */
ADC_tenuErrorStatus ADC_enuSelectChannel(ADC_tenuChannel Cpy_enuChannel);
/* **************************************** */
/* ADC Get Reading Function 
 Input:Pointer to u16 to get the reading into it
 Output: ADC_tenuErrorStatus to report error */
 /* ***************************************** */
ADC_tenuErrorStatus ADC_enuGetChannelReading(u16 *Add_pu8Reading);
/* **************************************** */
/* ADC Start Conversion Synchronous Function 
 Input:Pointer to u16 to get the reading into it, Channel of ADC
 ***************OPTIONS****************
 		1)ADC_enuChannel_Single_0,
 		2)ADC_enuChannel_Single_1,
 		3)ADC_enuChannel_Single_2,
 		4)ADC_enuChannel_Single_3,
 		5)ADC_enuChannel_Single_4,
 		6)ADC_enuChannel_Single_5,
 		7)ADC_enuChannel_Single_6,
 		8)ADC_enuChannel_Single_7,
 		9)ADC_enuChannel_Diff_00_10xG,
 		10)ADC_enuChannel_Diff_10_10xG,
 		11)ADC_enuChannel_Diff_00_200xG,
 		12)ADC_enuChannel_Diff_10_200xG,
 		13)ADC_enuChannel_Diff_22_10xG,
 		14)ADC_enuChannel_Diff32_10xG,
 		15)ADC_enuChannel_Diff_22_200xG,
 		16)ADC_enuChannel_Diff_32_200xG,
 		17)ADC_enuChannel_Diff_01_1xG,
 		19)ADC_enuChannel_Diff_11_1xG,
 		19)ADC_enuChannel_Diff_21_1xG,
 		20)ADC_enuChannel_Diff_31_1xG,
 		21)ADC_enuChannel_Diff_41_1xG,
 		22)ADC_enuChannel_Diff_51_1xG,
 		23)ADC_enuChannel_Diff_61_1xG,
 		24)ADC_enuChannel_Diff_71_1xG,
 		25)ADC_enuChannel_Diff_02_1xG,
 		26)ADC_enuChannel_Diff_12_1xG,
 		27)ADC_enuChannel_Diff_22_1xG,
 		28)ADC_enuChannel_Diff_32_1xG,
 		29)ADC_enuChannel_Diff_42_1xG,
 		
 
 Output: ADC_tenuErrorStatus to report error */
 /* ***************************************** */
ADC_tenuErrorStatus ADC_enuStartConversion_Synch (ADC_tenuChannel , u16 *Add_pu8Reading);
/* **************************************** */
/* ADC Start Conversion Synchronous Function 
 Input:Pointer to u16 to get the reading into it, Channel of ADC , pointer to function to call (End Of Job)
 ***************OPTIONS****************
 		1)ADC_enuChannel_Single_0,
 		2)ADC_enuChannel_Single_1,
 		3)ADC_enuChannel_Single_2,
 		4)ADC_enuChannel_Single_3,
 		5)ADC_enuChannel_Single_4,
 		6)ADC_enuChannel_Single_5,
 		7)ADC_enuChannel_Single_6,
 		8)ADC_enuChannel_Single_7,
 		9)ADC_enuChannel_Diff_00_10xG,
 		10)ADC_enuChannel_Diff_10_10xG,
 		11)ADC_enuChannel_Diff_00_200xG,
 		12)ADC_enuChannel_Diff_10_200xG,
 		13)ADC_enuChannel_Diff_22_10xG,
 		14)ADC_enuChannel_Diff32_10xG,
 		15)ADC_enuChannel_Diff_22_200xG,
 		16)ADC_enuChannel_Diff_32_200xG,
 		17)ADC_enuChannel_Diff_01_1xG,
 		19)ADC_enuChannel_Diff_11_1xG,
 		19)ADC_enuChannel_Diff_21_1xG,
 		20)ADC_enuChannel_Diff_31_1xG,
 		21)ADC_enuChannel_Diff_41_1xG,
 		22)ADC_enuChannel_Diff_51_1xG,
 		23)ADC_enuChannel_Diff_61_1xG,
 		24)ADC_enuChannel_Diff_71_1xG,
 		25)ADC_enuChannel_Diff_02_1xG,
 		26)ADC_enuChannel_Diff_12_1xG,
 		27)ADC_enuChannel_Diff_22_1xG,
 		28)ADC_enuChannel_Diff_32_1xG,
 		29)ADC_enuChannel_Diff_42_1xG,
 		
 
 Output: ADC_tenuErrorStatus to report error */
/*Note: You Should Enable Global Interrupt Before Using This Function*/
 /* ***************************************** */
ADC_tenuErrorStatus ADC_enuStartConversion_ASynch (ADC_tenuChannel , u16 *Add_pu16Reading, void (*Add_pvNotificationFunc)(void));
/* **************************************** */
/* ADC Start Conversion Synchronous Function 
 Input:Pointer to u16 to get the reading into it, Channel of ADC , pointer to function to call (End Of Job)
 ***************OPTIONS****************
 		1)ADC_enuChannel_Single_0,
 		2)ADC_enuChannel_Single_1,
 		3)ADC_enuChannel_Single_2,
 		4)ADC_enuChannel_Single_3,
 		5)ADC_enuChannel_Single_4,
 		6)ADC_enuChannel_Single_5,
 		7)ADC_enuChannel_Single_6,
 		8)ADC_enuChannel_Single_7,
 		9)ADC_enuChannel_Diff_00_10xG,
 		10)ADC_enuChannel_Diff_10_10xG,
 		11)ADC_enuChannel_Diff_00_200xG,
 		12)ADC_enuChannel_Diff_10_200xG,
 		13)ADC_enuChannel_Diff_22_10xG,
 		14)ADC_enuChannel_Diff32_10xG,
 		15)ADC_enuChannel_Diff_22_200xG,
 		16)ADC_enuChannel_Diff_32_200xG,
 		17)ADC_enuChannel_Diff_01_1xG,
 		19)ADC_enuChannel_Diff_11_1xG,
 		19)ADC_enuChannel_Diff_21_1xG,
 		20)ADC_enuChannel_Diff_31_1xG,
 		21)ADC_enuChannel_Diff_41_1xG,
 		22)ADC_enuChannel_Diff_51_1xG,
 		23)ADC_enuChannel_Diff_61_1xG,
 		24)ADC_enuChannel_Diff_71_1xG,
 		25)ADC_enuChannel_Diff_02_1xG,
 		26)ADC_enuChannel_Diff_12_1xG,
 		27)ADC_enuChannel_Diff_22_1xG,
 		28)ADC_enuChannel_Diff_32_1xG,
 		29)ADC_enuChannel_Diff_42_1xG,
		  
		
 	
		 *************TRIGGER SOURCE OPTIONS************
				   1) EXTI_REQ0_TRIGGER
				   2) TIMER0_COMP_MATCH_TRIGGER
				   3) TIMER0_OVER_FLOW_TRIGGER
				   4) TIMER_COM_MATCH_B_TRIGGER
				   5) TIMER1_OVER_FLOW
				   6) TIMER1_CAPTURE_EVENT_TRIGGER
				   7) ANALOG_COMPARATOR_TRIGGER
				   
				   
 Output: ADC_tenuErrorStatus to report error */
/*Note: You Should Enable Global Interrupt Before Using This Function*/
 /* ***************************************** */
ADC_tenuErrorStatus ADC_enuAutoTriggerConversion (ADC_tenuChannel ,u8 Cpy_u8TriggerSource, u16 *Add_pu16Reading, void (*Add_pvNotificationFunc)(void));
ADC_tenuErrorStatus ADC_enuStartChainConverstion (ADC_CHAIN_t *);
#endif