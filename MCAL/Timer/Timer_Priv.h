/*
 * Timer_Priv.h
 *
 *  Created on: Oct 27, 2023
 *      Author: lenovo
 */

#ifndef MCAL_TIMER_TIMER_PRIV_H_
#define MCAL_TIMER_TIMER_PRIV_H_

#define TCCR0           *((volatile u8*) 0x53)
#define TCNT0           *((volatile u8*) 0x52)       
#define OCR0            *((volatile u8*) 0x5C)             
#define TIMSK           *((volatile u8*) 0x59)  
#define TIFR            *((volatile u8*) 0x58)



#define WGM00           6
#define WGM01           3

#define OCIE0           1
#define TOIE0           0

#define COMP_OUTPUT_MODE_MASKING        0b11001111
#define TIMER0_PRESCALING_MASKING       0b11111000




#define VECTOR_TIMER0_COMP         __vector_10
#define VECTOR_TIMER0_OVF          __vector_11

#define ISR(vector) void vector (void) __attribute__((signal));\
void vector (void)

#endif /* MCAL_TIMER_TIMER_PRIV_H_ */
