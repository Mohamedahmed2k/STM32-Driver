/*********************************/
/* Author : Mohamed Ahmed Abdalaziem abdullah


		Date     : 12/2/24

*/
#ifndef UART_CONFIG_H
#define UART_CONFIG_H

#define MUSART      MUSART1

#define F_CPU                    8000000UL

/* USART_Configuration */

#define USART_STATUS            USART1_ENABLE
#define USART_BAUD_RATE         (u32)115200

#define USART_WORD_LENGTH       _8BIT_WORD_LENGTH
#define USART_PARITY            PARITY_DISABLE
#define USART_INTERRUPT         RXNE_INT_ENABLE

#define USART_TRANSMITTER       TRANSMITTER_ENABLE
#define USART_RECEIVER          RECEIVER_ENABLE

#define USART_STOP_BITS         ONE_STOP_BIT

#endif
