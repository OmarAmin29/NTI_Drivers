/*
 * Dio_Cfg.h
 *
 *  Created on: Oct 21, 2023
 *      Author: lenovo
 */

#ifndef DIO_DIO_CFG_H_
#define DIO_DIO_CFG_H_


#define PERIPHERAL   		*((volatile DIO_PrephieralType *)0x30)
#define PORTA               *((volatile DIO_PrephieralType *)0x39)                
#define PORTB               *((volatile DIO_PrephieralType *)0x36)               
#define PORTC               *((volatile DIO_PrephieralType *)0x33)                   
#define PORTD               *((volatile DIO_PrephieralType *)0x30)


#endif /* DIO_DIO_CFG_H_ */

