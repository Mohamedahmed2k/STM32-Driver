/*********************************/
/* Author : Mohamed Ahmed Abdalaziem abdullah


		Date     : 12/2/24

*/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "UART_interface.h"
#include "UART_private.h"
#include "UART_config.h"

#define THRESHOLD_VALUE  5000000UL

void (*MUSART_CallBack)(void);

void MUSART_voidInit ( void )
{

	u32 LOC_u64Mantissa = ( F_CPU ) / ( 16 * USART_BAUD_RATE ) ;

	u32 LOC_u64Fraction = ( ( ( F_CPU * 100 ) / ( 16 * USART_BAUD_RATE )  ) % 100 ) * 16 ;

	if( LOC_u64Fraction > 1500 ){ LOC_u64Mantissa += 1 ; LOC_u64Fraction  = 0 ; }

	#if USART1_STATUS == USART1_ENABLE

		MUSART -> SR = 0;

		#if   USART1_WORD_LENGTH == _8BIT_WORD_LENGTH

					CLR_BIT( MUSART -> CR1 , 12 );

		#elif USART_WORD_LENGTH == _9BIT_WORD_LENGTH

					SET_BIT( MUSART -> CR1 , 12 );

		#endif

		#if   USART1_PARITY == PARITY_DISABLE

					CLR_BIT( MUSART -> CR1 , 10 );

		#elif USART_PARITY == EVEN_PARITY

					SET_BIT( MUSART -> CR1 , 10 );
					CLR_BIT( MUSART -> CR1 , 11 );

		#elif USART_PARITY == ODD_PARITY

					SET_BIT( MUSART -> CR1 , 10 );
					SET_BIT( MUSART -> CR1 , 11 );

		#endif

		#if  USART1_INTERRUPT == INT_DISABLE

					CLR_BIT( MUSART -> CR1 , 5 );
					CLR_BIT( MUSART -> CR1 , 6 );
					CLR_BIT( MUSART -> CR1 , 7 );

		#elif USART_INTERRUPT == TXE_INT_ENABLE

					SET_BIT( MUSART -> CR1 , 7 );

		#elif USART_INTERRUPT == TCE_INT_ENABLE

					SET_BIT( MUSART -> CR1 , 6 );

		#elif USART_INTERRUPT == RXNE_INT_ENABLE

					SET_BIT( MUSART -> CR1 , 5 );

		#endif

		#if   USART1_TRANSMITTER == TRANSMITTER_ENABLE

					SET_BIT( MUSART -> CR1 , 3 );

		#elif USART_TRANSMITTER == TRANSMITTER_DISABLE

					CLR_BIT( MUSART -> CR1 , 3 );

		#endif

		#if   USART1_RECEIVER == RECEIVER_ENABLE

					SET_BIT( MUSART -> CR1 , 2 );

		#elif USART_RECEIVER == RECEIVER_DISBLE

					CLR_BIT( MUSART -> CR1 , 2 );

		#endif

		#if   USART1_STOP_BITS == ONE_STOP_BIT

					CLR_BIT( MUSART -> CR2 , 12 ); CLR_BIT( MUSART -> CR2 , 13 );

		#elif USART_STOP_BITS == HALF_STOP_BIT

					SET_BIT( MUSART -> CR2 , 12 ); CLR_BIT( MUSART -> CR2 , 13 );

		#elif USART_STOP_BITS == TWO_STOP_BIT

					CLR_BIT( MUSART -> CR2 , 12 ); SET_BIT( MUSART -> CR2 , 13 );

		#elif USART_STOP_BITS == ONE_AND_HALF_STOP_BIT

					SET_BIT( MUSART -> CR2 , 12 ); SET_BIT( MUSART -> CR2 , 13 );


		#endif

		MUSART -> BRR = ( LOC_u64Mantissa << 4  ) | ( LOC_u64Fraction / 100 ) ;
		SET_BIT( MUSART -> CR1 , 13 );

	#elif USART_STATUS == USART_DISABLE
		CLR_BIT( MUSART -> CR1 , 0 );

	#endif

}

void	 MUSART_voidTransmit(u8 ARR[])
{
	u8 i = 0 ;
	while(ARR[i] != '\0')
	{
		MUSART -> DR = ARR[i];
		while((GET_BIT( MUSART -> SR , 6)) == 0 );
		i++ ;
	}
	
}
u8 MUSART_u8Receive( void )
{

	u8  LOC_u8Data  = 0 ;
	u32 LOC_TimeOut = 0 ;

	CLR_BIT ( MUSART -> SR, 5);

	while( ( GET_BIT ( MUSART -> SR, 5) == 0 ) && ( LOC_TimeOut < THRESHOLD_VALUE ) )
	{
		LOC_TimeOut++;
	}

	if( LOC_TimeOut == THRESHOLD_VALUE )
	{
		LOC_u8Data = 255;
	}
	else
	{

		LOC_u8Data = MUSART -> DR;
	}

	return LOC_u8Data;

}
void MUSART_voidSetCallBack( void (*ptr) (void) )
{

	MUSART_CallBack = ptr ;

}



void USART1_IRQHandler(void)
{

	MUSART_CallBack();
}



/*

void USART2_IRQHandler(void)
{

	MUSART_CallBack();
}


void USART3_IRQHandler(void)
{

	MUSART_CallBack();
}
*/
