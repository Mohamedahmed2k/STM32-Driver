/*
 * main.c
 *
 *  Created on: ???/???/????
 *      Author: Mohamed
 */

/*#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "GPIO_interface.h"

#include "RCC_interface.h"
#include "STK_interface.h"

#include "LEDMATRIX_interface.h"
//// LED matrix

u8 Dataarray1[8] = {255, 128, 128, 128, 128, 0, 0, 60, 66, 66, 66, 66, 60, 0, 0, 255, 128, 128, 128, 128, 0, 0, 190, 0} ;
u8 Dataarray2[8] = { 128, 128, 128, 128, 0, 0, 60, 66, 66, 66, 66, 60, 0, 0, 255, 128, 128, 128, 128, 0, 0, 190, 0} ;
u8 Dataarray3[8] = { 128, 128, 128, 0, 0, 60, 66, 66, 66, 66, 60, 0, 0, 255, 128, 128, 128, 128, 0, 0, 190, 0} ;
u8 Dataarray4[8] = { 128, 128, 0, 0, 60, 66, 66, 66, 66, 60, 0, 0, 255, 128, 128, 128, 128, 0, 0, 190, 0} ;
u8 Dataarray5[8] = { 128, 0, 0, 60, 66, 66, 66, 66, 60, 0, 0, 255, 128, 128, 128, 128, 0, 0, 190, 0} ;
u8 Dataarray6[8] = { 0, 0, 60, 66, 66, 66, 66, 60, 0, 0, 255, 128, 128, 128, 128, 0, 0, 190, 0} ;
u8 Dataarray7[8] = { 0, 60, 66, 66, 66, 66, 60, 0, 0, 255, 128, 128, 128, 128, 0, 0, 190, 0} ;
u8 Dataarray8[8] = { 60, 66, 66, 66, 66, 60, 0, 0, 255, 128, 128, 128, 128, 0, 0, 190, 0} ;
u8 Dataarray9[8] = { 66, 66, 66, 66, 60, 0, 0, 255, 128, 128, 128, 128, 0, 0, 190, 0} ;
u8 Dataarray10[8] = { 66, 66, 66, 60, 0, 0, 255, 128, 128, 128, 128, 0, 0, 190, 0} ;
u8 Dataarray11[8] = { 66, 66, 60, 0, 0, 255, 128, 128, 128, 128, 0, 0, 190, 0} ;
u8 Dataarray12[8] = {66, 60, 0, 0, 255, 128, 128, 128, 128, 0, 0, 190, 0} ;
u8 Dataarray13[8] = { 60, 0, 0, 255, 128, 128, 128, 128, 0, 0, 190, 0} ;
u8 Dataarray14[8] = { 0, 0, 255, 128, 128, 128, 128, 0, 0, 190, 0} ;
u8 Dataarray15[8] = { 0, 255, 128, 128, 128, 128, 0, 0, 190, 0} ;
u8 Dataarray16[8] = { 255, 128, 128, 128, 128, 0, 0, 190, 0} ;
u8 Dataarray17[8] = {  128, 128, 128, 128, 0, 0, 190, 0} ;


void main (void)
{

	RCC_voidInitSysClock();
	RCC_voidEnableClock(RCC_APB2,2);
	RCC_voidEnableClock(RCC_APB2,3);

	STK_Init();
    HLEDMRX_voidInit();
    while(1)
    {
    HLEDMRX_voidDisplay(Dataarray1) ;
    STK_SetDelay(30);
    HLEDMRX_voidDisplay(Dataarray2) ;
        STK_SetDelay(30);
        HLEDMRX_voidDisplay(Dataarray3) ;
            STK_SetDelay(30);
            HLEDMRX_voidDisplay(Dataarray4) ;
            STK_SetDelay(30);
            HLEDMRX_voidDisplay(Dataarray5) ;
            STK_SetDelay(30);
            HLEDMRX_voidDisplay(Dataarray6) ;
            STK_SetDelay(30);
            HLEDMRX_voidDisplay(Dataarray7) ;
            STK_SetDelay(30);
            HLEDMRX_voidDisplay(Dataarray8) ;
            STK_SetDelay(30);
            HLEDMRX_voidDisplay(Dataarray9) ;
            STK_SetDelay(30);
            HLEDMRX_voidDisplay(Dataarray10) ;
            STK_SetDelay(30);
            HLEDMRX_voidDisplay(Dataarray11) ;
            STK_SetDelay(30);
            HLEDMRX_voidDisplay(Dataarray12) ;
            STK_SetDelay(30);
            HLEDMRX_voidDisplay(Dataarray13) ;
            STK_SetDelay(30);
            HLEDMRX_voidDisplay(Dataarray14) ;
            STK_SetDelay(30);
            HLEDMRX_voidDisplay(Dataarray15) ;
            STK_SetDelay(30);
            HLEDMRX_voidDisplay(Dataarray16) ;
            STK_SetDelay(30);
            HLEDMRX_voidDisplay(Dataarray17) ;
            STK_SetDelay(30);

    }
}
*/

/*#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "RCC_interface.h"
//#include "EXTI_interface.h"
#include "GPIO_interface.h"
#include "TFT_interface.h"
//#include "NVIC_interface.h"
#include "STK_interface.h"
#include "SPI_interface.h"*/
// IR
/*volatile u8 Start          = 0 ;
volatile u32 FrameData[50] = {0};
volatile u8  EdgeCounter   = 0 ;
volatile u8 data           = 0 ;

void play(void)
{
	switch(data)
	{
	case 70 :     ; break; // mode
	case 69 :     ; break; // power
	}
}
void TakeAction(void)
{
	u8 i ;
	data = 0 ;
	if (FrameData[0] >= 10000 && FrameData[0] < 14000)
	{
	for(i=0;i<8;i++)
	{
		if ((FrameData[17+i] >= 2000) &&  (FrameData[17+i] >= 2300))
		{
			SET_BIT (data , i );
		}
		else
		{
			CLR_BIT (data ,i);
		}
	}

	}
	else
	{
		// invalid frame
	}
	Start = 0 ;
	FrameData[0] = 0 ;
	EdgeCounter = 0 ;
}


void GetFrame(void)
{
	if (Start == 0 )
	{
		STK_SetIntervalSingle(1000000,TakeAction);
		Start = 1 ;
	}
	else
	{
		FrameData[EdgeCounter] = STK_GetElapsedCounts();
		STK_SetIntervalSingle(1000000,TakeAction);
		EdgeCounter++;
	}
}

void main()
{

	RCC_voidInitSysClock();
	RCC_voidEnableClock(RCC_APB2,2);

	GPIO_voidSetPinMode(GPIO_PORTA,0,0b0100);
	GPIO_voidSetPinMode(GPIO_PORTA,1,0b0010);
	GPIO_voidSetPinMode(GPIO_PORTA,2,0b0010);
	GPIO_voidSetPinMode(GPIO_PORTA,3,0b0010);

    MEXTI_voidSetCallBack(GetFrame);
	MEXTI_voidInit();

	MNVIC_voidInit();
	MNVIC_voidEnableIntererrupt(6);

	STK_Init();


	while(1)
	{

	}
}*/

/*
#include "OS_interface.h"

void LED1(void);
void LED2(void);
void LED3(void);

void main()
{
	RCC_voidInitSysClock();
	RCC_voidEnableClock(RCC_APB2,2);
	GPIO_voidSetPinMode(GPIO_PORTA,0,0b0100);
	GPIO_voidSetPinMode(GPIO_PORTA,1,0b0010);
	GPIO_voidSetPinMode(GPIO_PORTA,2,0b0010);
	GPIO_voidSetPinMode(GPIO_PORTA,3,0b0010);
	SOS_voidCreateTask(0,1000 , LED1 , 0);
	SOS_voidCreateTask(1,5000 , LED2 , 1);
	SOS_voidCreateTask(2,10000 , LED3 , 2);
	SOS_voidStart();
	while(1)
	{

	}
}

void LED1(void)
{
	static u8 Local_u8Pin1 = 0 ;
	TOG_BIT(Local_u8Pin1 , 0);
	GPIO_voidSetPinValue(GPIO_PORTA,GPIO_PIN3,Local_u8Pin1);

}
void LED2(void)
{
	static u8 Local_u8Pin2 = 0 ;
	TOG_BIT(Local_u8Pin2 , 0);
	GPIO_voidSetPinValue(GPIO_PORTA,GPIO_PIN1,Local_u8Pin2);

}
void LED3(void)
{
	static u8 Local_u8Pin3 = 0 ;
	TOG_BIT(Local_u8Pin3 , 0);
	GPIO_voidSetPinValue(GPIO_PORTA,GPIO_PIN2,Local_u8Pin3);

}
*/


/*void main()
{
	RCC_voidInitSysClock();
	RCC_voidEnableClock(RCC_APB2,2);
	RCC_voidEnableClock(RCC_APB2,14);
	GPIO_voidSetPinMode(GPIO_PORTA,9,0b0011);
	GPIO_voidSetPinMode(GPIO_PORTA,10,0b0100);
	GPIO_voidSetPinMode(GPIO_PORTA,0,0b0010);
	MUSART1_voidInit();
	u8 x ;
	while(1)
	{
		MUSART1_voidTransmit("97");
		x = MUSART1_u8Receive();
		if (x == '5' )
		{

			GPIO_voidSetPinValue(GPIO_PORTA,GPIO_PIN0,1);


		}
		else if (x == 'R')
		{
			GPIO_voidSetPinValue(GPIO_PORTA,GPIO_PIN0,0);
		}
	}



}*/
//#include "image.h"



//#include "UART_interface.h"
//#include "FPEC_interface.h"
/*
void ParserParser_voidParseRecord(u8* Copy_u8BufData);

volatile u8 u8RecBuffer[100] ;
volatile u8 u8RecCounter     = 0 ;
volatile u8 u8TimeOutFlag    = 0 ;
volatile u16 u16TimerCounter = 0 ;
volatile u8 u8BLWriteReg     = 1 ;
typedef void (*Function_t)(void);
Function_t addr_to_call = 0 ;

void func(void)
{
#define SCB_VTOR *((volatile u32*)0xE000ED08)
	SCB_VTOR = 0x08001000;

	addr_to_call = *(Function_t*)(0x08001004);
	addr_to_call();

}


void main (void)
{
	u8 Local_u8RecStatus;
	RCC_voidInitSysClock();
	RCC_voidEnableClock(RCC_APB2,14);
	RCC_voidEnableClock(RCC_APB2,2);
	RCC_voidEnableClock(RCC_AHB,4);

	MGPIO_voidSetPinDirection(GPIOA,9,0b1010);
	MGPIO_voidSetPinDirection(GPIOA,10,0b0100);

	MUSART1_voidInit();
	STK_Init();
	STK_SetIntervalSingle(15000000,func);
	while(u8TimeOutFlag == 0)
	{
		Local_u8RecStatus = MUSART_u8Receive(&(u8RecBuffer[u8RecCounter]));
		if (Local_u8RecStatus == 1)
		{
			STK_Stop();
			if (u8RecBuffer[u8RecCounter] == '\n')
			{
				if (u8BLWriteReg == 1)
				{
					FPEC_voidEraseAppArea();
					u8BLWriteReg = 0 ;
				}

				Parser_voidParseRecord(u8RecBuffer);
				MUSART_voidTransmit("ok");
				u8RecCounter = 0  ;
			}
			else
			{
				u8RecCounter ++ ;
			}
			STK_SetIntervalSingle(15000000,func);
		}
		else
		{
			//do noting
		}
	}
}

*/
void main()
{

}
