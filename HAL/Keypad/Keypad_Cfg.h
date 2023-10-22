/*
 * Keypad_Cfg.h
 *
 *  Created on: Oct 22, 2023
 *      Author: lenovo
 */

#ifndef HAL_KEYPAD_KEYPAD_CFG_H_
#define HAL_KEYPAD_KEYPAD_CFG_H_

#include"../../MCAL/DIO/Dio.h"

#define KEYPAD_RO       DIO_PORTC,DIO_PIN5    
#define KEYPAD_R1       DIO_PORTC,DIO_PIN4         
#define KEYPAD_R2       DIO_PORTC,DIO_PIN3  
#define KEYPAD_R3       DIO_PORTC,DIO_PIN2  

#define KEYPAD_CO       DIO_PORTD,DIO_PIN7  
#define KEYPAD_C1       DIO_PORTD,DIO_PIN6  
#define KEYPAD_C2       DIO_PORTD,DIO_PIN5  
#define KEYPAD_C3       DIO_PORTD,DIO_PIN3  



#endif /* HAL_KEYPAD_KEYPAD_CFG_H_ */
