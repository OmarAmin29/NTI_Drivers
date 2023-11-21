/*
 * Timer_Priv.h
 *
 *  Created on: Oct 27, 2023
 *      Author: lenovo
 */

#ifndef MCAL_TIMER_TIMER_PRIV_H_
#define MCAL_TIMER_TIMER_PRIV_H_



/*************TIMER0  REGISTERS*************/
#define TCCR0           *((volatile u8*) 0x53)
#define TCNT0           *((volatile u8*) 0x52)       
#define OCR0            *((volatile u8*) 0x5C)             
#define TIMSK           *((volatile u8*) 0x59)  
#define TIFR            *((volatile u8*) 0x58)

/************TIMER0 PINS*****************/
#define WGM00           6
#define WGM01           3

#define OCIE0           1
#define TOIE0           0

/*************TIMER1  REGISTERS*************/
#define TCCR1A		    *((volatile u8*) 0x4F)
#define TCCR1B		    *((volatile u8*) 0x4E)

#define TCNT1		    *((volatile u16*) 0x4C)
#define TCNT1L		    *((volatile u8*) 0x4C)
#define TCNT1H		    *((volatile u8*) 0x4D)

#define OCR1A		    *((volatile u16*) 0x4A)
#define OCR1AL		    *((volatile u8*) 0x4A)
#define OCR1AH		    *((volatile u8*) 0x4B)

#define OCR1B		    *((volatile u16*) 0x48)
#define OCR1BL		    *((volatile u8*) 0x48)
#define OCR1BH		    *((volatile u8*) 0x49)

#define ICR1		    *((volatile u16*) 0x46)
#define ICR1L		    *((volatile u8*) 0x46)
#define ICR1H		    *((volatile u8*) 0x47)

/*****************TIMER1 PINS******************/ 
#define WGM10           0
#define WGM11           1
#define FOC1B           2
#define FOC1A           3
#define COM1B0          4
#define COM1B1          5
#define COM1A0          6
#define COM1A1          7

#define CS10            0
#define CS11            1
#define CS12            2
#define WGM12           3
#define WGM13           4
#define ICES1           6
#define ICNC1           7

#define TOIE1           2
#define OCIE1B          3
#define OCIE1A          4
#define TICIE1          5


#define COMP_OUTPUT_MODE_MASKING        0b11001111
#define TIMER0_PRESCALING_MASKING       0b11111000






#define VECTOR_TIM1_ICU            	__vector_6
#define VECTOR_TIM1_COMPA           __vector_7
#define VECTOR_TIM1_COMPB           __vector_8
#define VECTOR_TIM1_OVF             __vector_9
#define VECTOR_TIMER0_COMP          __vector_10
#define VECTOR_TIMER0_OVF           __vector_11

#define ISR(vector) void vector (void) __attribute__((signal));\
void vector (void)
#endif /* MCAL_TIMER_TIMER_PRIV_H_ */
