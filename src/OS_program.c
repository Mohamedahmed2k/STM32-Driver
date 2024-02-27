/*************************************************/
/*
Author : Mohamed Ahmed Abdalaziem abdullah
		Date     : 8/2/24

*/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "STK_interface.h"

#include "OS_interface.h"
#include "OS_private.h"
#include "OS_config.h"

static Task OStasks[NUMBER_OF_TASKS] = {NULL};

void OS_voidCreateTask(u8 Copy_u8TaskID,u16 period,void (*ptr)(void),u16 Copy_u16firstDelay)
{
	OStasks[Copy_u8TaskID].Period = period;
	OStasks[Copy_u8TaskID].TaskHandler = ptr;
	OStasks[Copy_u8TaskID].firstDelay = Copy_u16firstDelay;
	OStasks[Copy_u8TaskID].State = TASK_READY;
}

void OS_voidStart(void)
{
	MSTK_voidInit();

	/*when HSE=8Mhz , sytem tick is 1ms*/
	MSTK_voidSetIntervalPeriodic(1000 , SCHEDULER );

}

void OS_voidSuspendTask(u8 Copy_u8TaskID)
{
	OStasks[Copy_u8TaskID].State=TASK_SUSPENDED;
}

void OS_voidResumeTask(u8 Copy_u8TaskID)
{
	OStasks[Copy_u8TaskID].State=TASK_READY;
}

void OS_voidDeleteTask(u8 Copy_u8TaskID)
{
	OStasks[Copy_u8TaskID].TaskHandler=NULL;
}

static void SCHEDULER(void)
{
	//static u16 Local_u16TickCounter=0;
	u8 Local_u8TaskCounter;
	/*Increment of Scheduler tick counter*/

		/*Loop on the tasks*/
		for(Local_u8TaskCounter=0;Local_u8TaskCounter<NUMBER_OF_TASKS;Local_u8TaskCounter++)
		{
			/*chack that task isn't deleted or suspended */
			if((OStasks[Local_u8TaskCounter].TaskHandler != NULL) && (OStasks[Local_u8TaskCounter].State == TASK_READY) )
			{
				/*Check until the first delay equal to zero*/
				if(OStasks[Local_u8TaskCounter].firstDelay == 0)
				{
					OStasks[Local_u8TaskCounter].firstDelay=OStasks[Local_u8TaskCounter].Period-1;
					/*Invoke the task function*/
					OStasks[Local_u8TaskCounter].TaskHandler();
				}
				else
				{
					/*Decrement the first delay*/
					OStasks[Local_u8TaskCounter].firstDelay--;
				}
			}
			else
			{
				/*Do nothing*/
			}
		}
}

/* array of tasks */
/*static Task OS_Tasks[NUMBER_OF_TASKS] = {NULL} ;

void  SOS_voidCreateTask(u8 Copy_u8ID , u16 Copy_u8Priodicity , u8 Copu_u8FirstDelay , void (*ptr) (void) )
{
	OS_Tasks[Copy_u8ID].Priodicity = Copy_u8Priodicity ;
	OS_Tasks[Copy_u8ID].Fptr       = ptr               ;
}
void  SOS_voidStart(void)
{
	MSTK_Init();
	// tick = 1 msec
	MSTK_SetIntervalPeriodic( 1 , Scheduler );
}

volatile u16 TickCounts = 0 ;
void Scheduler(void)
{
	
	for (u8 i = 0 ; i < NUMBER_OF_TASKS ; i++ )
	{
		if((TickCounts % OS_Tasks[i].Priodicity) == 0 )
		{
			OS_Tasks[i].Fptr();
		}
	}
	TickCounts++ ;

}*/

/*void Scheduler(void)
{
	
	for (u8 i = 0 ; i < NUMBER_OF_TASKS ; i++ )
	{
		if((OS_Tasks[i].Fptr() != NULL ) && (OS_Tasks[i].State == Task_Ready) )
		{
			if (OS_Tasks[i].FirstDelay == 0)
			{
				OS_Tasks[i].FirstDelay = OS_Tasks[i].Priodicity-1 ;
				OS_Tasks[i].Fptr();
			}
			else
			{
				OS_Tasks[i].FirstDelay--;
			}

		}
	}
}
	*/
