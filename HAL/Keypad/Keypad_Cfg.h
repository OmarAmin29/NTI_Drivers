/*
 * Keypad_Cfg.h
 *
 *  Created on: Oct 22, 2023
 *      Author: lenovo
 */

#ifndef HAL_KEYPAD_KEYPAD_CFG_H_
#define HAL_KEYPAD_KEYPAD_CFG_H_

#include"../../MCAL/DIO/Dio.h"

#define KEYPAD        {{'1','2','3','+'},\
					   {'4','5','6','-'},\
					   {'7','8','9','/'},\
					   {'A','0','=','*'}}

#define KEYPAD_CALC        {{'7','8','9','/'},\
					   	   {'4','5','6','*'},\
						   {'1','2','3','-'},\
						   {'A','0','=','+'}}

#define KEYPAD_PORT_ROW0         DIO_PORTC     
#define KEYPAD_PORT_ROW1         DIO_PORTC
#define KEYPAD_PORT_ROW2         DIO_PORTC
#define KEYPAD_PORT_ROW3         DIO_PORTC
#define KEYPAD_PORT_ROW			 DIO_PORTC

#define KEYPAD_PIN_ROW0          DIO_PIN5     
#define KEYPAD_PIN_ROW1          DIO_PIN4
#define KEYPAD_PIN_ROW2          DIO_PIN3
#define KEYPAD_PIN_ROW3          DIO_PIN2

#define KEYPAD_PORT_COLUMN0         DIO_PORTD     
#define KEYPAD_PORT_COLUMN1         DIO_PORTD
#define KEYPAD_PORT_COLUMN2         DIO_PORTD
#define KEYPAD_PORT_COLUMN3         DIO_PORTD
#define KEYPAD_PORT_COLUMN          DIO_PORTD


#define KEYPAD_PIN_COLUMN0          DIO_PIN7     
#define KEYPAD_PIN_COLUMN1          DIO_PIN6
#define KEYPAD_PIN_COLUMN2          DIO_PIN5
#define KEYPAD_PIN_COLUMN3          DIO_PIN3



#endif /* HAL_KEYPAD_KEYPAD_CFG_H_ */
