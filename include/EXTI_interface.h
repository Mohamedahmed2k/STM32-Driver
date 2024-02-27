/*********************************/
/* Author : Mohamed Ahmed Abdalaziem abdullah
   date   : 1/2/2024 */

#ifndef EXTI_INTERFACE_H
#define EXTI_INTERFACE_H

/* line and mode */
void MEXTI_voidInit();
void MEXTI_voidenableEXTI(u8 Copy_u8Line);
void MEXTI_voidDisableEXTI(u8 Copy_u8Line);
void MEXTI_voidSwTrigger(u8 Copy_u8Line);
void MEXTI_voidSetSignalLatch(u8 Copy_u8Line, u8 Copy_u8Mode);

void MEXTI_vidSetCallBack (u8 copy_u8Line, void (*ptr) (void));

#endif
