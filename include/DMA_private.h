/*********************************/
/* Author : Mohamed Ahmed Abdalaziem abdullah
   /*version    : V01        */
/*
		Date     : 8/2/24

*/

#ifndef DMA_PRIVATE_H
#define DMA_PRIVATE_H

typedef struct{

	volatile u32 CCR       ;//0x000
	volatile u32 CNDTR     ;//0x004
	volatile u32 CPAR      ;//0x008
	volatile u32 CMAR      ;//0x00C
	volatile u32 RESERVED  ;//0x010

}DMA_CHANNEL;

typedef struct{

	volatile u32 ISR  ;//0x000
	volatile u32 IFCR ;//0x004
	DMA_CHANNEL CHANNEL[7];//0x008

}DMA;

#define MDMA ( ( volatile DMA * ) 0x40020000 )

#endif
