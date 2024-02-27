/*********************************/
/* Author : Mohamed Ahmed Abdalaziem abdullah
   /*version    : V01        */
/*
		Date     : 17/2/24

*/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "ADC_config.h"
#include "ADC_interface.h"
#include "ADC_private.h"
#include "STK_interface.h"
#include "GPIO_interface.h"

/*
PA0 -> ADC12_IN0
PA1 -> ADC12_IN1
PA2 -> ADC12_IN2
PA3 -> ADC12_IN3
PA4 -> ADC12_IN4
PA5 -> ADC12_IN5
PA6 -> ADC12_IN6
PA7 -> ADC12_IN7
PB0 -> ADC12_IN8
PB1 -> ADC12_IN9

PC0 -> ADC12_IN10
PC1 -> ADC12_IN11
PC2 -> ADC12_IN12
PC3 -> ADC12_IN13
PC4 -> ADC12_IN14
PC5 -> ADC12_IN15



*/


// Initializing the ADC for the STM32F1
void MADC_voidInit( u8 Copy_u8Port, u8 Copy_u8Pin)
{
	u8 channel;

	if(Copy_u8Port == PORTA)
	{
		if(Copy_u8Pin < 8)
		{

			channel = Copy_u8Pin;
		}
	}
	else if (Copy_u8Port == PORTB)
	{
		if(Copy_u8Pin<2)
		{

		channel = 8 + Copy_u8Pin;
		}
	}
	else if (Copy_u8Port == PORTC)
	{
		if(Copy_u8Pin<6)
		{

		channel = 10 + Copy_u8Pin;
		}
	}

	MGPIO_voidSetPinDirection( Copy_u8Port , Copy_u8Pin , INPUT_ANLOG);

			ADC->CR2 = 0;
			ADC->SQR[2] = channel;
			ADC->CR2 |= 1;
			MSTK_voidInit();
            MSTK_voidSetBusyWait( 100 );
			ADC->CR2 |= 1;
			ADC->CR2 |= 2;
}


// Reading the ADC value
u16 MADC_u16Results( void)
{
	u16 Local_u16Result = 0;
	u16 Local_u16Data = 0;

	if(ADC->SR & 2)
				{


	Local_u16Data = ADC->DR;
	Local_u16Result = (Local_u16Data * 1000) / 0xfff;
				}

	return Local_u16Result;
}





