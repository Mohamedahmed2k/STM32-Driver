/*********************************/
/* Author : Mohamed Ahmed Abdalaziem abdullah
   /*version    : V01        */
/*
		Date     : 17/2/24

*/

#ifndef ADC_INTERFACE_H
#define ADC_INTERFACE_H

void MADC_voidInit( u8 Copy_u8Port, u8 Copy_u8Pin);
u8 MADC_u8Check(void);
u16 MADC_u16Results( void);

#endif
