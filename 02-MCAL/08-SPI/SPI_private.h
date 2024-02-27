/*********************************/
/* Author : Mohamed Ahmed Abdalaziem abdullah
   /*version    : V01        */
/*
		Date     : 12/2/24

*/
#ifndef SPI_PRIVATE_H
#define SPI_PRIVATE_H

typedef struct
{
	volatile u32 CR1    ;
	volatile u32 CR2    ;
	volatile u32 SR     ;
	volatile u32 DR     ;
	volatile u32 CRCPR  ;
	volatile u32 RXCRCR ;
	volatile u32 TXCRCR ;
	volatile u32 I2SCFGR;
	volatile u32 I2SPR  ;

}SPI_Register;


#define MSPI1   ((SPI_Register *)(0x40013000))

#define MSPI2   ((SPI_Register *)(0x40003800))

#define SPI_MSB_FIRST 0
#define SPI_LSB_FIRST 1

#define SPI_FIRST_CLOCK_FIRST_CAPTURE   0
#define SPI_SECOND_CLOCK_FIRST_CAPTURE  1

#define SPI_CK_0_WHEN_IDLE 0
#define SPI_CK_1_WHEN_IDLE 1

#define SPI_BAUDRATE_PRESCALER_2    0
#define SPI_BAUDRATE_PRESCALER_4    1
#define SPI_BAUDRATE_PRESCALER_8    2
#define SPI_BAUDRATE_PRESCALER_16   3
#define SPI_BAUDRATE_PRESCALER_32   4
#define SPI_BAUDRATE_PRESCALER_64   5
#define SPI_BAUDRATE_PRESCALER_128  6
#define SPI_BAUDRATE_PRESCALER_256  7

static void SPI_voidSetBaudRatePrescaler (u8 copy_u8Prescaler);

#endif
