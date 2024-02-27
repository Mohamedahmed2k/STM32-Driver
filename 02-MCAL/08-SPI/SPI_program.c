/*********************************/
/* Author : Mohamed Ahmed Abdalaziem abdullah
   /*version    : V01        */
/*
		Date     : 12/2/24

*/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "SPI_interface.h"
#include "SPI_config.h"
#include "SPI_private.h"
#include "GPIO_interface.h"

void (*CallBack)(u8);

void MSPI_voidInit(void)
{
	MSPI -> CR1 = 0x0347 ;
	SPI_voidSetBaudRatePrescaler(SPI_BAUDRATE_PRESCALER);

	    #if SPI_DATA_ORDER   == SPI_LSB_FIRST
	        SET_BIT(MSPI->CR1, 7);
	    #endif
	    #if SPI_CLK_PHASE    == SPI_FIRST_CLOCK_FIRST_CAPTURE
	        CLR_BIT(MSPI->CR1, 0);
	    #endif
	    #if SPI_CLK_POLARITY == SPI_CK_0_WHEN_IDLE
	        CLR_BIT(MSPI->CR1, 1);
	    #endif

   // #if  MSPI ==  MSPI1

        MGPIO_voidSetPinDirection(GPIOA, PIN5, OUTPUT_SPEED_10MHZ_AFPP  ); /*SCK*/
        MGPIO_voidSetPinDirection(GPIOA, PIN6, INPUT_FLOATING           ); /*MISO*/
        MGPIO_voidSetPinDirection(GPIOA, PIN7, OUTPUT_SPEED_10MHZ_AFPP  ); /*MOSI*/
   /*
    * #elif  MSPI       ==      MSPI2
        GPIO_vidSetPinDirection(GPIOB, PIN13, OUTPUT_SPEED_10MHZ_AFPP  );
        GPIO_vidSetPinDirection(GPIOB, PIN14, INPUT_FLOATING           );
        GPIO_vidSetPinDirection(GPIOB, PIN15, OUTPUT_SPEED_10MHZ_AFPP  );
    #endif
*/
}

void MSPI_voidSendReceiveSync(u16 Copy_u16DataToTransmit , u16 *Copy_u16DataToReceive)
{
	// clr 
	MGPIO_voidSetPinValue(MSPI_SLAVE_PIN,LOW);
	
	MSPI -> DR = Copy_u16DataToTransmit ;
	
	while (GET_BIT(MSPI -> SR , 7) == 1);
	
	*Copy_u16DataToReceive = MSPI -> DR ;
	
	MGPIO_voidSetPinValue(MSPI_SLAVE_PIN,HIGH);
}

static void SPI_voidSetBaudRatePrescaler (u8 copy_u8Prescaler)
{
    MSPI->CR1 |= (copy_u8Prescaler<<3);
}
/*void SPI1_IRQHandler(void)
{
	CallBack(MSPI1 -> DR );
}*/

