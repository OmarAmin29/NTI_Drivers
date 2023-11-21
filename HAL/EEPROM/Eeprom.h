/*
 * Eeprom.h
 *
 *  Created on: Oct 31, 2023
 *      Author: lenovo
 */

#ifndef HAL_EEPROM_EEPROM_H_
#define HAL_EEPROM_EEPROM_H_


#include"../../MCAL/I2c/I2c.h"

void H_Eeprom_Init(void);
I2c_ErrorType H_Eeprom_WriteByte(u16 adress, u8 data);
I2c_ErrorType H_Eeprom_ReadByte(u16 adress, u8* data);

#endif /* HAL_EEPROM_EEPROM_H_ */
