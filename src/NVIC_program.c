/*********************************/
/* Author : Mohamed Ahmed Abdalaziem abdullah
   date   : 1/2/2024 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "NVIC_config.h"
#include "NVIC_interface.h"
#include "NVIC_private.h"



void MNVIC_voidInit(void)
{
    #define SCB_AIRCR      *((volatile u32*)0xE000ED0C)
	SCB_AIRCR = MNVIC_GROUP_SUB_DISTRIBUTION ;

}
void MNVIC_voidSetPriority(u8 Copy_u8PeripheralIdx , u8 Copy_u8Priority)
{
	if(Copy_u8PeripheralIdx < 60)
	{
		NVIC_IPR[Copy_u8PeripheralIdx] = Copy_u8Priority ;
	}
	else
	{
		/* report error */
	}
}
void MNVIC_voidEnableIntererrupt( u8 Copy_u8INtNum)
{
	if ( Copy_u8INtNum <= 31)
	{
		NVIC_ISER0 = ( 1 << Copy_u8INtNum);
	}
	else if(  Copy_u8INtNum <= 59)
	{
		Copy_u8INtNum -= 32 ; 
		NVIC_ISER1 = ( 1 << Copy_u8INtNum);
	}
	else
	{
	   /*return  error */	
	}
		
}

void MNVIC_voidDisableIntererrupt( u8 Copy_u8INtNum)
{
	if ( Copy_u8INtNum <= 31)
	{
		NVIC_ICER0 = ( 1 << Copy_u8INtNum);
	}
	else if(  Copy_u8INtNum <= 59)
	{
		Copy_u8INtNum -= 32 ; 
		NVIC_ICER1 = ( 1 << Copy_u8INtNum);
	}
	else
	{
	   /*return  error */	
	}
		
}

void MNVIC_voidSetPendingFlag( u8 Copy_u8INtNum)
{
	if ( Copy_u8INtNum <= 31)
	{
		NVIC_ISPR0 = ( 1 << Copy_u8INtNum);
	}
	else if(  Copy_u8INtNum <= 59)
	{
		Copy_u8INtNum -= 32 ; 
		NVIC_ISPR1 = ( 1 << Copy_u8INtNum);
	}
	else
	{
	   /*return  error */	
	}
		
}

void MNVIC_voidClearPendingFlag( u8 Copy_u8INtNum)
{
	if ( Copy_u8INtNum <= 31)
	{
		NVIC_ICPR0 = ( 1 << Copy_u8INtNum);
	}
	else if(  Copy_u8INtNum <= 59)
	{
		Copy_u8INtNum -= 32 ; 
		NVIC_ICPR1 = ( 1 << Copy_u8INtNum);
	}
	else
	{
	   /*return  error */	
	}
		
}

u8 MNVIC_voidGetPendingFlag( u8 Copy_u8INtNum)
{
	u8 Local_u8Result = 0 ;
	if ( Copy_u8INtNum <= 31)
	{
		Local_u8Result = GET_BIT(NVIC_ICPR0 ,Copy_u8INtNum);
	}
	else if(  Copy_u8INtNum <= 59)
	{
		Copy_u8INtNum -= 32 ; 
		Local_u8Result = GET_BIT(NVIC_ICPR0 ,Copy_u8INtNum);
	}
	else
	{
	   /*return  error */	
	}
		return Local_u8Result ;
}


/*void MNVIC_voidSetPriority(s8 Copy_s8IntID , u8 Copy_u8GroupPriority , u32 Copy_u32SubPriority , u8 Copy_u8Group )
{
	u8 Local_u8Priority = (Copy_u32SubPriority | (Copy_u8GroupPriority<<((Copy_u8Group - 0x05FA0300)/256)));
	
	if(Copy_s8IntID >= 0 )
	{
		NVIC_IPR[Copy_s8IntID] = Local_u8Priority << 4 ;
	}
	SCB_AIRCR = Copy_u8Group ;
}
*/
