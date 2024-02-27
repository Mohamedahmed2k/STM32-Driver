/*********************************/
/* Author : Mohamed Ahmed Abdalaziem abdullah
   date   : 1/2/2024 */
#ifndef NVIC_INTERFACE_H
#define NVIC_INTERFACE_H

void MNVIC_voidSetPriority(u8 Copy_u8PeripheralIdx , u8 Copy_u8Priority);
void MNVIC_voidInit(void);
void MNVIC_voidEnableIntererrupt( u8 Copy_u8INtNum);
void MNVIC_voidDisableIntererrupt( u8 Copy_u8INtNum);
void MNVIC_voidSetPendingFlag( u8 Copy_u8INtNum);
void MNVIC_voidClearPendingFlag( u8 Copy_u8INtNum);
u8 MNVIC_voidGetPendingFlag( u8 Copy_u8INtNum);
//void MNVIC_voidSetPriority(s8 Copy_s8IntID , u8 Copy_u8GroupPriority , u32 Copy_u32SubPriority , u8 Copy_u8Group );




#endif 
