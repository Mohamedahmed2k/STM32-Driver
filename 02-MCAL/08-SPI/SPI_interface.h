/*********************************/
/* Author : Mohamed Ahmed Abdalaziem abdullah
   /*version    : V01        */
/*
		Date     : 12/2/24

*/

#ifndef SPI_INTERFACE_H
#define SPI_INTERFACE_H

void MSPI_voidInit(void);
void MSPI_voidSendReceiveSync(u16 Copy_u16DataToTransmit , u16 *Copy_u16DataToReceive);
//void MSPI_voidSendReceiveAsync(u8 Copy_u8DataToTransmit , void (*CallBack)(u8));

#endif
