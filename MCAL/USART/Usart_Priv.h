/*
 * Usart_Priv.h
 *
 *  Created on: Oct 29, 2023
 *      Author: lenovo
 */

#ifndef MCAL_USART_USART_PRIV_H_
#define MCAL_USART_USART_PRIV_H_


#define UDR             *((volatile u8*) 0x2C)
#define UCSRA           *((volatile u8*) 0x2B)
#define UCSRB           *((volatile u8*) 0x2A)
#define UCSRC           *((volatile u8*) 0x40)
#define UBRRH           *((volatile u8*) 0x40)
#define UBRRL           *((volatile u8*) 0x29)



/*********UCSRA PINS******/
#define RXC             7
#define TXC             6
#define UDRE            5
#define FE              4
#define DOR             3
#define PE              2
#define U2X             1
#define MPCM            0

/*********UCSRB PINS******/
#define RXCIE           7           
#define TXCIE           6
#define UDRIE           5
#define RXEN            4
#define TXEN            3
#define UCSZ2           2
#define RXB8            1
#define TXB8            0

/*********UCSRC PINS******/
#define URSEL           7
#define UMSEL           6
#define UPM1            5
#define UPM0            4
#define USBS            3
#define UCSZ1           2
#define UCSZ0           1
#define UCPOL           0





#define VECTOR_UART_RX          __vector_13
#define VECTOR_UART_REG_EMPTY   __vector_14
#define VECTOR_UART_TX          __vector_15

#define ISR(vector) void vector (void) __attribute__((signal));\
void vector (void)

#endif /* MCAL_USART_USART_PRIV_H_ */
