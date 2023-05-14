
typedef enum
{
	LM35_enuOK,
	LM35_enuNOK,
	LM35_enuNullPtr
}LM35_tenuErrorStatus;

LM35_tenuErrorStatus LM35_enuGetSensorReading(u8 Cpy_enuChannel , u16 *Add_pu16Reading);