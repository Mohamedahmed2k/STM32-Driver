/*********************************/
/* Author : Mohamed Ahmed Abdalaziem abdullah


		Date     : 12/2/24

*/

#ifndef UART_INTERFACE_H
#define UART_INTERFACE_H

void MUSART_voidInit ( void );
void MUSART_voidTransmit(u8 ARR[]);
u8   MUSART_u8Receive( void );
void MUSART_voidSetCallBack( void (*ptr) (void) );


#endif
