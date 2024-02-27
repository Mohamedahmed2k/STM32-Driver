/*********************************/
/* Author : Mohamed Ahmed Abdalaziem abdullah
   /*version    : V01        */
/*date       : 28/1/2024  */
/*******************************/
#ifndef RCC_INTERFACE_H
#define RCC_INTERFACE_H_H

#define RCC_AHB     0
#define RCC_APB1    1
#define RCC_APB2    2

void MRCC_voidDisableClock(u8 Copy_u8BusId,u8 Copy_u8PerId);
void MRCC_voidEnableClock(u8 Copy_u8BusId,u8 Copy_u8PerId);
void MRCC_voidInitSysClock(void);

#endif
