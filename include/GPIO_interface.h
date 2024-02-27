/*********************************/
/* Author : Mohamed Ahmed Abdalaziem abdullah
   date   : 1/2/2024 */
#ifndef GPIO_INTERFACE_H
#define GPIO_INTERFACE_H

#define HIGH    1
#define LOW     0

#define GPIOA   0
#define GPIOB   1
#define GPIOC   2

#define PIN0     0
#define PIN1     1
#define PIN2     2
#define PIN3     3
#define PIN4     4
#define PIN5     5
#define PIN6     6
#define PIN7     7
#define PIN8     8
#define PIN9     9
#define PIN10    10
#define PIN11    11
#define PIN12    12
#define PIN13    13
#define PIN14    14
#define PIN15    15



#define INPUT_ANLOG               0b0000  // to receive analog signal
#define INPUT_FLOATING            0b0100  // input floating, used with sensors
#define INPUT_PULLUP_PULLDOWN     0b1000  // pull_up or pull_down

//For Speed 10
#define OUTPUT_SPEED_10MHZ_PP     0b0001  // push pull : high and low
#define OUTPUT_SPEED_10MHZ_OD     0b0101  // open drain
#define OUTPUT_SPEED_10MHZ_AFPP   0b1001  // alternative function push pull
#define OUTPUT_SPEED_10MHZ_AFOD   0b1101  // alternative function open drain

//For Speed 2
#define OUTPUT_SPEED_2MHZ_PP      0b0010  // push pull  : high and low
#define OUTPUT_SPEED_2MHZ_OD      0b0110  // open drain
#define OUTPUT_SPEED_2MHZ_AFPP    0b1010  // alternative function push pull
#define OUTPUT_SPEED_2MHZ_AFOD    0b1110  // alternative function open drain

//For Speed 2
#define OUTPUT_SPEED_50MHZ_PP     0b0011  // push pull  : high and low
#define OUTPUT_SPEED_50MHZ_OD     0b0111  // open drain
#define OUTPUT_SPEED_50MHZ_AFPP   0b1011  // alternative function push pull
#define OUTPUT_SPEED_50MHZ_AFOD   0b1111  // alternative function open drain


void MGPIO_voidSetPinDirection(u8 copy_u8PORT , u8 copy_u8PIN , u8 copy_u8MODE);
void MGPIO_voidSetPinValue(u8 copy_u8PORT , u8 copy_u8PIN , u8 copy_u8VALUE);

u8   MGPIO_u8GetPinValue(u8 copy_u8PORT , u8 copy_u8PIN );
void MGPIO_voidLockPin(u8 Copy_u8Port, u8 Copy_u8Pin);
void MGPIO_voidUnlockPin(u8 Copy_u8Port, u8 Copy_u8Pin);





#endif
