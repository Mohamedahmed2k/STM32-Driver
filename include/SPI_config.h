/*********************************/
/* Author : Mohamed Ahmed Abdalaziem abdullah
   /*version    : V01        */
/*
		Date     : 12/2/24

*/
#ifndef  SPI_CONFIG_H
#define  SPI_CONFIG_H


#define MSPI             MSPI1
#define MSPI_SLAVE_PIN  GPIOA,PIN0

#define SPI_DATA_ORDER          	 SPI_MSB_FIRST
/* Options:
    SPI_FIRST_CLOCK_FIRST_CAPTURE
    SPI_SECOND_CLOCK_FIRST_CAPTURE
*/
#define SPI_CLK_PHASE      	 	     SPI_SECOND_CLOCK_FIRST_CAPTURE
/* Options:
    SPI_FIRST_CLOCK_FIRST_CAPTURE
    SPI_SECOND_CLOCK_FIRST_CAPTURE
*/
#define SPI_CLK_POLARITY      	 	 SPI_CK_1_WHEN_IDLE
/* Options:
    SPI_BAUDRATE_PRESCALER_2
    SPI_BAUDRATE_PRESCALER_4
    SPI_BAUDRATE_PRESCALER_8
    SPI_BAUDRATE_PRESCALER_16
    SPI_BAUDRATE_PRESCALER_32
    SPI_BAUDRATE_PRESCALER_64
    SPI_BAUDRATE_PRESCALER_128
    SPI_BAUDRATE_PRESCALER_256
*/
#define SPI_BAUDRATE_PRESCALER       SPI_BAUDRATE_PRESCALER_2

#endif
