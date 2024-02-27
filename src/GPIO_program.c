/*********************************/
/* Author : Mohamed Ahmed Abdalaziem abdullah
   date   : 1/2/2024 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "GPIO_config.h"
#include "GPIO_interface.h"
#include "GPIO_private.h"


void MGPIO_voidSetPinDirection(u8 Copy_PORT, u8 Copy_PIN, u8 Copy_Mode)
{
	switch(Copy_PORT)
	{
		case GPIOA:
			if(Copy_PIN < 8)
			{
				GPIOA_CRL &= ~((0b1111) << (Copy_PIN * 4));
				GPIOA_CRL |= ((Copy_Mode) << (Copy_PIN * 4));
			}
			else if(Copy_PIN < 16)
			{
				Copy_PIN-=8;
				GPIOA_CRH &= ~((0b1111) << (Copy_PIN * 4));
			    GPIOA_CRH |= ((Copy_Mode) << (Copy_PIN * 4));
			}
			else
			{
				/**< RETURN ERROR STATUS */
			}
		break;
		case GPIOB:
			if(Copy_PIN < 8)
			{
				GPIOB_CRL &= ~((0b1111) << (Copy_PIN * 4));
				GPIOB_CRL |= ((Copy_Mode) << (Copy_PIN * 4));
			}
			else if(Copy_PIN < 16)
			{
				Copy_PIN-=8;
				GPIOB_CRH &=~ ((0b1111) << (Copy_PIN * 4));
				GPIOB_CRH |= ((Copy_Mode) << (Copy_PIN * 4));
			}
			else
			{
				/**< RETURN ERROR STATUS */
			}
		break;
		case GPIOC:
			if(Copy_PIN < 8)
			{
				GPIOC_CRL &=~ ((0b1111) << (Copy_PIN * 4));
				GPIOC_CRL |= ((Copy_Mode) << (Copy_PIN * 4));
			}
			else if(Copy_PIN < 16)
			{
				Copy_PIN-=8;
				GPIOC_CRH &=~ ((0b1111) << (Copy_PIN * 4));
				GPIOC_CRH |= ((Copy_Mode) << (Copy_PIN * 4));
			}
			else
			{
				/**< RETURN ERROR STATUS */
			}
		break;
		default:
			/**< RETURN ERROR STATUS */
		break;
	}
	/**< RETURN ERRORSTATUS */
}

void MGPIO_voidSetPinValue(u8 Copy_PORT,u8 Copy_PIN, u8 Copy_Value)
{
	if(Copy_PIN < 16)
	{
		switch(Copy_PORT)
		{
			case GPIOA:
				if(Copy_Value == HIGH)
				{
					SET_BIT(GPIOA_ODR, Copy_PIN);
				}
				else if(Copy_Value == LOW)
				{
					CLR_BIT(GPIOA_ODR, Copy_PIN);
				}
				else
				{
					/**< RETURN ERROR STATUS */
				}
			break;
			case GPIOB:
				if(Copy_Value == HIGH)
				{
					SET_BIT(GPIOB_ODR, Copy_PIN);
				}
				else if(Copy_Value == LOW)
				{
					CLR_BIT(GPIOB_ODR, Copy_PIN);
				}
				else
				{
					/**< RETURN ERROR STATUS */
				}
			break;
			case GPIOC:
				if(Copy_Value == HIGH)
				{
					SET_BIT(GPIOC_ODR, Copy_PIN);
				}
				else if(Copy_Value == LOW)
				{
					CLR_BIT(GPIOC_ODR, Copy_PIN);
				}
				else
				{
					/**< RETURN ERROR STATUS */
				}
			break;
			default:
				/**< RETURN ERROR STATUS */
			break;
		}
	}
	else
	{
		/**< RETURN ERROR STATUS */
	}
	/**< RETURN ERROR STATUS */
}

u8  MGPIO_u8GetPinValue(u8 Copy_PORT, u8 Copy_PIN)
{
	u8 Local_u8ReturnPinValue = 0;
	if(Copy_PIN < 16)
	{
		switch(Copy_PORT)
		{
			case GPIOA: Local_u8ReturnPinValue = GET_BIT(GPIOA_IDR, Copy_PIN); break;
			case GPIOB: Local_u8ReturnPinValue = GET_BIT(GPIOB_IDR, Copy_PIN); break;
			case GPIOC: Local_u8ReturnPinValue = GET_BIT(GPIOC_IDR, Copy_PIN); break;
		}
	}
	else
	{
		/**< RETURN ERROR STATUS */
	}
	return Local_u8ReturnPinValue;
}


void MGPIO_voidLockPin(u8 Copy_u8Port, u8 Copy_u8Pin)
{
	MGPIO_voidLockPinSequence( Copy_u8Port,  Copy_u8Pin) ;
	 SET_BIT(GPIOA_LCK, Copy_u8Pin);
}
void MGPIO_voidUnlockPin(u8 Copy_u8Port, u8 Copy_u8Pin)
{
	MGPIO_voidLockPinSequence( Copy_u8Port,  Copy_u8Pin) ;
	 CLR_BIT(GPIOA_LCK, Copy_u8Pin);
}

static void MGPIO_voidLockPinSequence(u8 Copy_u8Port, u8 Copy_u8Pin)
{
	u8 Local_u8Var ;
    switch (Copy_u8Port)
    {

    case GPIOA:
        SET_BIT(GPIOA_LCK, Copy_u8Pin);
        CLR_BIT(GPIOA_LCK, Copy_u8Pin);
        SET_BIT(GPIOA_LCK, Copy_u8Pin);
        Local_u8Var = GET_BIT(GPIOA_LCK, Copy_u8Pin);
        Local_u8Var = GET_BIT(GPIOA_LCK, Copy_u8Pin);
        break;

    case GPIOB:
    	  SET_BIT(GPIOB_LCK, Copy_u8Pin);
    	  CLR_BIT(GPIOB_LCK, Copy_u8Pin);
    	  SET_BIT(GPIOB_LCK, Copy_u8Pin);
    	  Local_u8Var = GET_BIT(GPIOB_LCK, Copy_u8Pin);
    	  Local_u8Var = GET_BIT(GPIOB_LCK, Copy_u8Pin);
        break;

    case GPIOC:
    	  SET_BIT(GPIOC_LCK, Copy_u8Pin);
    	  CLR_BIT(GPIOC_LCK, Copy_u8Pin);
    	  SET_BIT(GPIOC_LCK, Copy_u8Pin);
    	  Local_u8Var = GET_BIT(GPIOC_LCK, Copy_u8Pin);
    	  Local_u8Var = GET_BIT(GPIOC_LCK, Copy_u8Pin);
    	  break;
    default:
        break;
    }

}
