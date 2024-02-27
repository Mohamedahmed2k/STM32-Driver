/*************************************************/
/*
		Author   : Mohamed
		Date     : 12/2/24

*/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "SPI_interface.h"
#include "STK_interface.h"

#include "TFT_interface.h"
#include "TFT_private.h"
#include "TFT_config.h"

void HTFT_voidInit(void)
{
	MGPIO_voidSetPinValue(TFT_RST_PIN,HIGH);
	STK_SetBusyWait(100);
	MGPIO_voidSetPinValue(TFT_RST_PIN,LOW);
	STK_SetBusyWait(1);
	MGPIO_voidSetPinValue(TFT_RST_PIN,HIGH);
	STK_SetBusyWait(100);
	MGPIO_voidSetPinValue(TFT_RST_PIN,LOW);
	STK_SetBusyWait(100);
	MGPIO_voidSetPinValue(TFT_RST_PIN,HIGH);
	STK_SetBusyWait(120000);
	voidWriteCommand(0x11);
	STK_SetBusyWait(150000);
	voidWriteCommand(0x3A);
	voidWriteData(0x05);
	voidWriteCommand(0x29);


}
void HTFTvoidDisplayImage(const u16* Copy_Image)
{
	u16 counter = 0 ;
	// X
	voidWriteCommand(0x2A);
	voidWriteData(0);
	voidWriteData(0);
	voidWriteData(0);
	voidWriteData(127);
	// Y
	voidWriteCommand(0x2B);
	voidWriteData(0);
	voidWriteData(0);
	voidWriteData(0);
	voidWriteData(159);
	// Draw
	voidWriteCommand(0x2C);
	for (counter = 0 ; counter < 20480 ; counter++)
	{
		// high
		voidWriteData(Copy_Image[counter] >> 8);
		// low
		voidWriteData(Copy_Image[counter] & 0x00FF);
	}



	
}
void HTFTvoidFillColor( u16 Copy_u16Color)
{
	u16 counter = 0 ;
	// X
	voidWriteCommand(0x2A);
	voidWriteData(0);
	voidWriteData(0);
	voidWriteData(0);
	voidWriteData(127);
	// Y
	voidWriteCommand(0x2B);
	voidWriteData(0);
	voidWriteData(0);
	voidWriteData(0);
	voidWriteData(159);
	// Draw
	voidWriteCommand(0x2C);
	for (counter = 0 ; counter < 20480 ; counter++)
	{
		// high
		voidWriteData(Copy_u16Color >> 8);
		// low
		voidWriteData(Copy_u16Color & 0x00FF);
	}




}
void HTFTvoidDrawRect( u8 x1 ,u8 x2 , u8 y1 ,u8 y2, u16 Copy_u16Color)
{
	u16 counter = 0 ;
	u16 Size = (x2-x1)*(y2-y1);
	// X
	voidWriteCommand(0x2A);
	voidWriteData(0);
	voidWriteData(x1);
	voidWriteData(0);
	voidWriteData(x2);
	// Y
	voidWriteCommand(0x2B);
	voidWriteData(0);
	voidWriteData(y1);
	voidWriteData(0);
	voidWriteData(y2);
	// Draw
	voidWriteCommand(0x2C);
	for (counter = 0 ; counter < Size ; counter++)
	{
		// high
		voidWriteData(Copy_u16Color >> 8);
		// low
		voidWriteData(Copy_u16Color & 0x00FF);
	}




}
static void voidWriteCommand ( u8 Copy_u8Command )
{
	// A0 low
	u8 Local_u8Temp;
    MGPIO_voidSetPinValue(TFT_A0_PIN,LOW);
    MSPI_voidSendReceiveSync(Copy_u8Command , &Local_u8Temp);
	
}
static void voidWriteData(u8 Copy_u8Data)
{
	u8 Local_u8Temp;
	// A0 high
	MGPIO_voidSetPinValue(TFT_A0_PIN,HIGH);
	MSPI_voidSendReceiveSync(Copy_u8Data , &Local_u8Temp);
}
