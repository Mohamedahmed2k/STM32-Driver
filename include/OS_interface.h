/*************************************************/
/*
Author : Mohamed Ahmed Abdalaziem abdullah
		Date     : 8/2/24

*/
#ifndef OS_INTERFACE_H
#define OS_INTERFACE_H

//Example: OS_voidCreateTask(0,1000,func,0);
void OS_voidCreateTask(u8 Copy_u8TaskID,u16 period,void (*ptr)(void),u16 Copy_u16firstDelay);
void OS_voidStart(void);

void OS_voidSuspendTask(u8 Copy_u8TaskID);
void OS_voidResumeTask(u8 Copy_u8TaskID);
void OS_voidDeleteTask(u8 Copy_u8TaskID);

/*void  SOS_voidCreateTask(u8 Copy_u8ID , u16 Copy_u8Priodicity , u8 Copu_u8FirstDelay , void (*ptr) (void) );
void  SOS_voidStart(void);*/


#endif
