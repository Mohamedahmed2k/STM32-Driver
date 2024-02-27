/*********************************/
/* Author : Mohamed Ahmed Abdalaziem abdullah
   /*version    : V01        */
/*date       : 28/1/2024  */   
/*******************************/
#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "../../halloledmrx/include/RCC_config.h"
#include "../../halloledmrx/include/RCC_interface.h"
#include "RCC_private.h"


void MRCC_voidInitSysClock(void)
{
	#if RCC_CLOCK_TYPE == RCC_HSE_CRYSTAL
	   RCC_CR    = 0x00010000 ; /* enable HSE with no bypass */

	   RCC_CFGR  = 0x00000001 ;
	#elif RCC_CLOCK_TYPE == RCC_HSE_RC
	   RCC_CR = 0x00050000 ; /* enable HSE with bypass */
	   RCC_CFGR  = 0x00000001 ;
	#elif RCC_CLOCK_TYPE == RCC_HSI
	   RCC_CR    = 0x00000081 ; /*enable HSI */
	   while(!GET_BIT(RCC_CR, RCC_HSIRDY_BIT));
	   RCC_CFGR  = 0x00000000 ;
	#elif RCC_CLOCK_TYPE == RCC_PLL
	   RCC_CFGR |= ((RCC_PLL_MUL_VAL)<<18);
	  #if RCC_PLL_INPUT == RCC_PLL_IN_HSI_DIV_2
	CLR_BIT(RCC_CFGR, RCC_PLLSRC_BIT);
	#elif RCC_PLL_INPUT == RCC_PLL_IN_HSE_DIV_2
	
	#elif RCC_PLL_INPUT == RCC_PLL_IN_HSE 
	
	#else 
#endif
		#error("you choose wrong clock type")
	#endif
}

void MRCC_voidEnableClock(u8 Copy_u8BusId,u8 Copy_u8PerId)
{
	if(Copy_u8PerId <= 31)
	{
		switch(Copy_u8BusId)
		{
			case RCC_AHB  : SET_BIT(RCC_AHBENR  ,Copy_u8PerId);   break;
			case RCC_APB1 : SET_BIT(RCC_APB1ENR ,Copy_u8PerId);   break;
			case RCC_APB2 : SET_BIT(RCC_APB2ENR ,Copy_u8PerId);   break;
		}
	}
	else
	{
		/*return error */
	}
}
void MRCC_voidDisableClock(u8 Copy_u8BusId,u8 Copy_u8PerId)
{
	if(Copy_u8PerId <= 31)
	{
		switch(Copy_u8BusId)
		{
			case RCC_APB1 : CLR_BIT(RCC_APB1ENR ,Copy_u8PerId);   break;
			case RCC_AHB  : CLR_BIT(RCC_AHBENR  ,Copy_u8PerId);   break;
			case RCC_APB2 : CLR_BIT(RCC_APB2ENR ,Copy_u8PerId);   break;
		}
	}
	else
	{
		/*return error */
	}
}
