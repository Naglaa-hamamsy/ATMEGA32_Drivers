#ifndef RTOS_CFG_H
#define RTOS_CFG_H

/**********************************************TYPES**************************************************/
/*Set Tasks Starting From Higher Priority*/

typedef enum
{
	LEDTASK1,
	LEDTASK2,
	TASKS_NUM
	
};
	
typedef struct
{
	u16 Periodicity;
	void(*TaskFunc)(void);
}Task_t;

/*Note That Index Of Task Is It's PRIORITY*/
extern const Task_t Tasks[TASKS_NUM];

/***********************************************DEFINES*********************************************/
/* Set The Max Number Of Tasks*/
//#define TASKS_NUM 2
#define SYSTEM_TICK_TIME 1  /* With ms*/


#endif