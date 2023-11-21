/*
 * Keypad.h
 *
 *  Created on: Oct 22, 2023
 *      Author: lenovo
 */

#ifndef HAL_KEYPAD_KEYPAD_H_
#define HAL_KEYPAD_KEYPAD_H_

#include"../../Private/Types.h"


void Keypad_Init(void);
u8 Keypad_GetButtonState(void);


#endif /* HAL_KEYPAD_KEYPAD_H_ */
