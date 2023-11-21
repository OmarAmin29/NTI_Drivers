/*
 * Lcd.h
 *
 *  Created on: Oct 23, 2023
 *      Author: lenovo
 */

#ifndef HAL_LCD_LCD_H_
#define HAL_LCD_LCD_H_

#include"Lcd_Cfg.h"
#include"Lcd_Priv.h"


void H_LCD_void_Init(void);
void H_LCD_void_sendData(u8 copy_u8data);
void H_LCD_void_sendCommand(u8 copy_u8command);
void H_LCD_void_ClearDisplay(void);
void H_LCD_void_sendString(const u8 * pstr);
void H_LCD_void_sendIntNum(s32 copy_s32Num);
void H_Lcd_SetCursorPosition(u8 row, u8 column);





#endif /* HAL_LCD_LCD_H_ */
