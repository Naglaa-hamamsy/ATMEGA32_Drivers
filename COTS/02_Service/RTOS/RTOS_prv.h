#ifndef RTOS_PRV_H
#define RTOS_PRV_H


typedef struct
{
	u16 Periodicity;
	void(*TaskFunc)(void);
}Task_t;

static void voidScheduler(void);
extern Task_t Tasks[TasksNum];

#endif