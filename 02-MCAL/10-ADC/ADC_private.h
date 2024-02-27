/*********************************/
/* Author : Mohamed Ahmed Abdalaziem abdullah
   /*version    : V01        */
/*
		Date     : 17/2/24

*/
#ifndef ADC_PRIVATE_H
#define ADC_PRIVATE_H

typedef struct{

	volatile u32 SR;
	volatile u32 CR1;
	volatile u32 CR2;
	volatile u32 SMPR[2];
	volatile u32 JOFR[4];
	volatile u32 HTR;
	volatile u32 LTR;
	volatile u32 SQR[3];
	volatile u32 JSOR;
	volatile u32 JDR[4];
	volatile u32 DR;


}ADC_t;


#define ADC1 ( ( volatile ADC_t* ) 0x40012400 )
#define ADC2 ( ( volatile ADC_t* ) 0x40012800 )
#define ADC3 ( ( volatile ADC_t* ) 0x40013C00 )

#define PORTA   0
#define PORTB   1
#define PORTC   2

#endif
