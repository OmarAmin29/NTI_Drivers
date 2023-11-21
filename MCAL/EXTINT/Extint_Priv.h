/*
 * Extint_Priv.h
 *
 *  Created on: Oct 22, 2023
 *      Author: lenovo
 */

#ifndef MCAL_EXTINT_EXTINT_PRIV_H_
#define MCAL_EXTINT_EXTINT_PRIV_H_


#define MCUCR		*((volatile u8*) 0x55)
#define MCUCSR		*((volatile u8*) 0x54)
#define GICR		*((volatile u8*) 0x5B)

#define EXT_INT0     6
#define EXT_INT1     7
#define EXT_INT2     5






#define VECTOR_EXT_INT0          __vector_1
#define VECTOR_EXT_INT1          __vector_2
#define VECTOR_EXT_INT2          __vector_3

#define ISR(vector) void vector (void) __attribute__((signal));\
void vector (void)
#endif /* MCAL_EXTINT_EXTINT_PRIV_H_ */
