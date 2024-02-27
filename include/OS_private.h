/*************************************************/
/*
Author : Mohamed Ahmed Abdalaziem abdullah
		Date     : 8/2/24

*/
#ifndef OS_PRIVATE_H
#define OS_PRIVATE_H

#define			TASK_SUSPENDED			1

#define			TASK_READY				2


typedef struct
{
	u16 Period;
	void (*TaskHandler)(void);
	u16	firstDelay;
	u8 State;
}Task;



static void SCHEDULER(void);

#endif
