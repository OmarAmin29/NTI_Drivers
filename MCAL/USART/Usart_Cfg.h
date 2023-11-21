/*
 * Usart_Cfg.h
 *
 *  Created on: Oct 29, 2023
 *      Author: lenovo
 */

#ifndef MCAL_USART_USART_CFG_H_
#define MCAL_USART_USART_CFG_H_


#define USART_FREQ_OSC       16000000UL

#define USART_PARITY_DISABLED       0
#define USART_PARITY_ODD            1
#define USART_PARITY_EVEN           2

#define USART_DISABLED           0
#define USART_ENABLED            1


/********************* USER CONFIGURATIONS *********************/

#define UART_RX_STATE       UART_ENABLED
#define UART_TX_STATE       UART_ENABLED
#define UART_FREQ_OSC       8000000UL
#define UART_BAUDRATE       9600UL
#define UART_CHAR_SIZE      8
#define UART_STOP_BITS      1
#define UART_PARITY_BIT     UART_PARITY_DISABLED



#endif /* MCAL_USART_USART_CFG_H_ */
