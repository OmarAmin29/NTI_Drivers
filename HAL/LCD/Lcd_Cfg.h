/*
 * Lcd_Cfg.h
 *
 *  Created on: Oct 23, 2023
 *      Author: lenovo
 */

#ifndef HAL_LCD_LCD_CFG_H_
#define HAL_LCD_LCD_CFG_H_

#define LCD_MODE            _4BIT_MODE


#define _8BIT_MODE          1
#define _4BIT_MODE          2





#define LCD_PIN_RS          DIO_PORTA,3
#define LCD_PIN_EN          DIO_PORTA,2

#define LCD_PIN_DB0         
#define LCD_PIN_DB1         
#define LCD_PIN_DB2         
#define LCD_PIN_DB3         
#define LCD_PIN_DB4         DIO_PORTB,0         
#define LCD_PIN_DB5         DIO_PORTB,1                  
#define LCD_PIN_DB6         DIO_PORTB,2
#define LCD_PIN_DB7         DIO_PORTB,4         



#endif /* HAL_LCD_LCD_CFG_H_ */
