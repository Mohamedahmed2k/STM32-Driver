/****************************************************************/
/* Author    : Ahmed Elbadry                                    */
/* Date      : 28 SEP 2020                                      */
/* Version   : V01                                              */
/****************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "UART_interface.h"
#include "STK_interface.h"

#include "ESP_interface.h"



u8 volatile Iterator = 0  ;
u8 volatile DataCome[200] ;
u8 volatile result =0;

void ValidateCommand( void )
{
	while(result ==0){
	for(u8 i=0;i<Iterator;i++){
		if (DataCome[i] == 'O' && DataCome[(i+1)] == 'K')
	        {
	        	result = 1;
	        }
	}
	}
}

void MUSART_CallBack ( void ){

	/* Receive ESP8266 Response */
	DataCome[ Iterator ] = MUSART1_u8ReadDataRegister();
	/* ------------------ */
	Iterator++;
	MUSART1_VidClearFlags();

}

void ESP8266_VidInit ( void ){

	/* Set USART1 CallBack To Receive The Response Of The ESP8266 */
	MUSART1_VidSetCallBack( MUSART_CallBack );

	/* Sending AT Command To Check ESP8266 Is Working Or Not  */
	MUSART1_VidSendStringSynch( (u8 *)"AT\r\n" );


ValidateCommand();


	/* Clear ESP8266 Buffer */
	ESP8266_VidClearBuffer();

	MUSART1_VidSendStringSynch( (u8 *)"AT+CWMODE=3\r\n" );
	ValidateCommand();

	ESP8266_VidClearBuffer();

	MUSART1_VidSendStringSynch( (u8 *)"AT+CIPMODE=0\r\n" );
	ValidateCommand();

}

void ESP8266_VidConnectToWiFi ( u8 * SSID , u8 * Password ){

	ESP8266_VidClearBuffer();

	MUSART_voidTransmit( (u8 *) "AT+CWJAP=\"" );
	MUSART_voidTransmit( (u8 *) SSID );
	MUSART_voidTransmit( (u8 *) "\",\"" );
	MUSART_voidTransmit( (u8 *) Password);
	MUSART_voidTransmit( (u8 *) "\"\r\n");
	ValidateCommand();

}


void ESP8266_VidConnectToSrvTcp ( u8 * Copy_u8Domain , u8 * Copy_u8Port ){

	ESP8266_VidClearBuffer();

	MUSART_voidTransmit( (u8 *) "AT+CIPSTART=\"TCP\",\"" );
	MUSART_voidTransmit( (u8 *) Copy_u8Domain );
	MUSART_voidTransmit( (u8 *) "\"," );
	MUSART_voidTransmit( (u8 *) Copy_u8Port );
	MUSART_voidTransmit( (u8 *) "\r\n" );

	MSTK_voidSetBusyWait(1000000); // 1_sec

}

void ESP8266_VidSendHttpReq( u8 * Copy_u8Key , u8 * Copy_u8Data , u8 * Copy_u8Length ){

	ESP8266_VidClearBuffer();

	MUSART_voidTransmit( (u8 *) "AT+CIPSEND=" );
	MUSART_voidTransmit( (u8 *) Copy_u8Length );
	MUSART_voidTransmit( (u8 *) "\r\n" );
	MSTK_voidSetBusyWait(4000000); // 1_sec

	ESP8266_VidClearBuffer();

	MUSART_voidTransmit( (u8 *) "GET /update?api_key=" );
	MUSART_voidTransmit( (u8 *) Copy_u8Key );
	MUSART_voidTransmit( (u8 *) "&field1=" );
	MUSART_voidTransmit( (u8 *) Copy_u8Data );
	MUSART_voidTransmit( (u8 *) "\r\n" );
	MSTK_voidSetBusyWait(20000000); // 1_sec

}

u8   ESP8266_u8ReceiveHttpReq( u8 * Copy_u8ChannelID , u8 * Copy_u8Length ){

	ESP8266_VidClearBuffer();

	MUSART_voidTransmit( (u8 *) "AT+CIPSEND=" );
	MUSART_voidTransmit( (u8 *) Copy_u8Length );
	MUSART_voidTransmit( (u8 *) "\r\n" );
	MSTK_voidSetBusyWait(4000000); // 4_sec

	ESP8266_VidClearBuffer();

	MUSART_voidTransmit( (u8 *) "GET http://" );
	MUSART_voidTransmit( (u8 *) Copy_u8ChannelID );
	MUSART_voidTransmit( (u8 *) "/status.txt\r\n" );
	MSTK_voidSetBusyWait(2000000);

	ESP8266_VidConnectToSrvTcp( (u8 *)"162.253.155.226" , (u8 *)"80" );

	/*For yrabiot3.freevar.com ( Value Array Index )*/
	return  DataCome[82] ;

}

void ESP8266_VidClearBuffer ( void ){

	u8 LOC_u8Iterator1 = 0 ;
	Iterator     = 0 ;
	result       = 0 ;

	for( LOC_u8Iterator1 = 0 ; LOC_u8Iterator1 < 150 ; LOC_u8Iterator1++ ){

		DataCome[ LOC_u8Iterator1 ] = 0 ;

	}

}
