/*
 * Keypad.h
 *
 *  Created on: Oct 22, 2023
 *      Author: lenovo
 */

#ifndef HAL_KEYPAD_KEYPAD_H_
#define HAL_KEYPAD_KEYPAD_H_

#include"Keypad_Cfg.h"
#include"Keypad_Priv.h"


typedef enum{
    KEYPAD_BUTTON_00,
    KEYPAD_BUTTON_01,
    KEYPAD_BUTTON_02,
    KEYPAD_BUTTON_03,
    KEYPAD_BUTTON_04,
    KEYPAD_BUTTON_05,
    KEYPAD_BUTTON_06,
    KEYPAD_BUTTON_07,
    KEYPAD_BUTTON_08,
    KEYPAD_BUTTON_09,
    KEYPAD_BUTTON_10,
    KEYPAD_BUTTON_11,
    KEYPAD_BUTTON_12,
    KEYPAD_BUTTON_13,
    KEYPAD_BUTTON_14,
    KEYPAD_BUTTON_15
}Keypad_ButtonType;


typedef enum{
    KEYPAD_BUTTON_NOT_PRESSED = 0,
    KEYPAD_BUTTON_PRESSED = 1    
}Keypad_ButtonSTateType;



void Keypad_Init(void);
Keypad_ButtonSTateType Keypad_GetButtonState(Keypad_ButtonType button);




#endif /* HAL_KEYPAD_KEYPAD_H_ */
