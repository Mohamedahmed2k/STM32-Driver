/*********************************/
/* Author : Mohamed Ahmed Abdalaziem abdullah
   /*version    : V01        */
/*date       : 28/1/2024  */
/*******************************/

#ifndef RCC_CONFIG_H
#define RCC_CONFIG_H

/* options:   RCC_HSE_CRYSTAL
              RCC_HSE_RC
              RCC_HSI
			  RCC_PLL */
#define RCC_CLOCK_TYPE    RCC_HSI


/* options:   RCC_PLL_IN_HSI_DIV_2
              RCC_PLL_IN_HSE_DIV_2 
              RCC_PLL_IN_HSE   */
#if RCC_CLOCK_TYPE == RCC_PLL

#define RCC_PLL_INPUT RCC_PLL_IN_HSE_DIV_2
/* options :
 * 		PLL_MUL_VAL_2
		PLL_MUL_VAL_3
		PLL_MUL_VAL_4
		PLL_MUL_VAL_5
		PLL_MUL_VAL_6
		PLL_MUL_VAL_7
		PLL_MUL_VAL_8
		PLL_MUL_VAL_9
		PLL_MUL_VAL_10
		PLL_MUL_VAL_11
		PLL_MUL_VAL_12
		PLL_MUL_VAL_13
		PLL_MUL_VAL_14
		PLL_MUL_VAL_15
		PLL_MUL_VAL_16
 *
 *
 */
#define RCC_PLL_MUL_VAL  PLL_MUL_VAL_2
#endif


#endif
