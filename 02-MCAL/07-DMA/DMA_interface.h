/*********************************/
/* Author : Mohamed Ahmed Abdalaziem abdullah
   /*version    : V01        */
/*
		Date     : 8/2/24

*/
#ifndef DMA_INTERFACE_H
#define DMA_INTERFACE_H

#define DMA_GIF   0
#define DMA_TCIF  1
#define DMA_HTIF  2
#define DMA_TEIF  3
//DMA CHANNELS
#define CHANNEL1  0
#define CHANNEL2  1
#define CHANNEL3  2
#define CHANNEL4  3
#define CHANNEL5  4
#define CHANNEL6  5
#define CHANNEL7  6
//Interrupt Enable
#define DMA_TCIE  1
#define DMA_HTIE  2
#define DMA_TEIE  3
//Enable
#define DMA_ENABLE  0
#define DMA_DISABLE 1
//DMA Configuration
//Direction
#define MEM_TO_MEM   0
#define PREI_TO_MEM  1
#define MEM_TO_PERI  2
//Circular
#define DMA_ENABLE_CIRCULAR  0
#define DMA_DISABLE_CIRCULAR 1
//PIN & MIN
#define PERIPHERAL_INCREMENT_ENABLE  0
#define PERIPHERAL_INCREMENT_DISABLE 1
//MIN
#define MEM_INCREMENT_ENABLE  0
#define MEM_INCREMENT_DISABLE 1
//Size
#define BYTE       0
#define HALF_WORD  1
#define WORD       2
//Channel Priority
#define DMA_LOW         0
#define DMA_MEDIUM      1
#define DMA_HIGH        2
#define DMA_VERY_HIGH   3


void MDMA_voidSetConfiguration( u8 Copy_u8Channel , u8 Copy_u8Direction , u8 Copy_u8DMAMode , u8 Copy_u8PINC ,
		u8 Copy_u8MINC , u8 Copy_MEMSize , u8 Copy_u8PERSize , u8 Copy_u8ChannelPriority );

void MDMA_voidDMAEnable( u8 Copy_u8Channel );

void MDMA_voidDMADisable( u8 Copy_u8Channel );

void MDMA_voidInerruptEnable( u8 Copy_u8Channel , u8 Copy_u8INTSource );

void MDMA_voidSetAddress( u8 Copy_u8Channel , u32 * PeripheralAddress , u32 * MemoryAddress , u16 Copy_u16NDT );

void MDMA_voidClearFlag( u8 Copy_u8Channel , u8 Copy_u8Flag );

u8   MDMA_u8GetFlag( u8 Copy_u8Channel , u8 Copy_u8Flag );

void MDMA_voidSetCallBackChannel1( void ( *Ptr ) ( void ) );

/*void MDMA_voidChannelInit(void);
void MDMA_voidChannelStart(u32 * Copy_Pu32SourceAddress , u32 * Copy_Pu32DestinationAddress , u16 Copy_u16BlockLength);
*/
#endif
