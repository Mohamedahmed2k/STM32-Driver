/*****************************/
/* Auther    : Mohamed Abdalaziem */
/* Date      : 27 jan 2024*/
/* Version   : V01   */
#ifndef BIT_MATH_H
#define BIT_MATH_H

#define SET_BIT(var,bit)     var |= (1<<(bit))
#define CLR_BIT(var,bit)     var &=~(1<<(bit))
#define GET_BIT(var,bit)    ((var >> bit) & 1 )
#define TOG_BIT(var,bit)     var ^= (1<<(bit))

#define NULL   (void *)0


#endif
