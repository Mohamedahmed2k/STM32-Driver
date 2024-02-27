/*********************************/
/* Author : Mohamed Ahmed Abdalaziem abdullah
   date   : 1/2/2024 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "EXTI_interface.h"
#include "EXTI_private.h"
#include "EXTI_config.h"


static void(*EXTI_callback[16])(void);

void MEXTI_voidInit()
{
	#if EXTI_MODE == RISING
	SET_BIT(EXTI -> RSTR , EXTI_LINE);
	#elif EXTI_MODE == FALLING
	SET_BIT(EXTI -> FTSR , EXTI_LINE);
	#elif EXTI_MODE == ON_CHANGE
	SET_BIT(EXTI -> RSTR , EXTI_LINE);
	SET_BIT(EXTI -> FTSR , EXTI_LINE);
	#else  #error "Wrong Mode And Line Choice"
	#endif
	CLR_BIT(EXTI -> IMR , EXTI_MODE);
}
void MEXTI_voidenableEXTI(u8 Copy_u8Line)
{
	SET_BIT(EXTI -> IMR , Copy_u8Line);
}
void MEXTI_voidDisableEXTI(u8 Copy_u8Line)
{
	CLR_BIT(EXTI -> IMR , Copy_u8Line);
}
void MEXTI_voidSwTrigger(u8 Copy_u8Line)
{
	SET_BIT(EXTI -> SWIER , Copy_u8Line);
}
void MEXTI_voidSetSignalLatch(u8 Copy_u8Line, u8 Copy_u8Mode)
{
	switch(Copy_u8Mode)
	{
		case RISING    :  SET_BIT(EXTI -> RSTR , EXTI_LINE);break;
		case FALLING   :  SET_BIT(EXTI -> FTSR , EXTI_LINE); break;
		case ON_CHANGE :  SET_BIT(EXTI -> RSTR , EXTI_LINE);
	                      SET_BIT(EXTI -> FTSR , EXTI_LINE); break;
		default        :   /* error */ break;
	}
}

void MEXTI_vidSetCallBack (u8 copy_u8Line, void (*ptr) (void))
{
    EXTI_callback[copy_u8Line] = ptr;
}


void EXTI0_IRQHandler (void)
{
    EXTI_callback[0]();
    SET_BIT(EXTI -> PR, 0);
}
void EXTI1_IRQHandler (void)
{
    EXTI_callback[1]();
    SET_BIT(EXTI -> PR, 1);
}
void EXTI2_IRQHandler (void)
{
    EXTI_callback[2]();
    SET_BIT(EXTI -> PR, 2);
}
void EXTI3_IRQHandler (void)
{
    EXTI_callback[3]();
    SET_BIT(EXTI -> PR, 3);
}
void EXTI4_IRQHandler (void)
{
    EXTI_callback[4]();
    SET_BIT(EXTI -> PR, 4);
}
void EXTI5_IRQHandler (void)
{
    EXTI_callback[5]();
    SET_BIT(EXTI -> PR, 5);
}
void EXTI6_IRQHandler (void)
{
    EXTI_callback[6]();
    SET_BIT(EXTI -> PR, 6);
}
void EXTI7_IRQHandler (void)
{
    EXTI_callback[7]();
    SET_BIT(EXTI -> PR, 7);
}
void EXTI8_IRQHandler (void)
{
    EXTI_callback[8]();
    SET_BIT(EXTI -> PR, 8);
}
void EXTI9_IRQHandler (void)
{
    EXTI_callback[9]();
    SET_BIT(EXTI -> PR, 9);
}
void EXTI10_IRQHandler (void)
{
    EXTI_callback[10]();
    SET_BIT(EXTI -> PR, 10);
}
void EXTI11_IRQHandler (void)
{
    EXTI_callback[11]();
    SET_BIT(EXTI -> PR, 11);
}
void EXTI12_IRQHandler (void)
{
    EXTI_callback[12]();
    SET_BIT(EXTI -> PR, 12);
}
void EXTI13_IRQHandler (void)
{
    EXTI_callback[13]();
    SET_BIT(EXTI -> PR, 13);
}
void EXTI14_IRQHandler (void)
{
    EXTI_callback[14]();
    SET_BIT(EXTI -> PR, 14);
}
void EXTI15_IRQHandler (void)
{
    EXTI_callback[15]();
    SET_BIT(EXTI -> PR, 15);
}
