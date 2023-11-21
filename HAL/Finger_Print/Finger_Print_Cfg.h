/*
 * Finger_Print_Cfg.h
 *
 *  Created on: Nov 4, 2023
 *      Author: lenovo
 */

#ifndef HAL_FINGER_PRINT_FINGER_PRINT_CFG_H_
#define HAL_FINGER_PRINT_FINGER_PRINT_CFG_H_



#define TRANSMIT_STRING			1



#define HAND_SHAKE			0xEF, 0x01, 0xFF, 0xFF, 0xFF, 0xFF, 0x01, 0x00, 0x03, 0x40, 0x00, 0x44, '#'
#define GEN_IMG				0xEF, 0x01, 0xFF, 0xFF, 0xFF, 0xFF, 0x01, 0x00, 0x03, 0x01, 0x00, 0x05, '#'
#define IMG_TO_CHAR			0xEF, 0x01, 0xFF, 0xFF, 0xFF, 0xFF, 0x01, 0x00, 0x04, 0x02, 0x00, 0x00, 0x00, '#'
#define GEN_TEMPLATE		0xEF, 0x01, 0xFF, 0xFF, 0xFF, 0xFF, 0x01, 0x00, 0x03, 0x05, 0x00, 0x09, '#'
#define STORE_TEMPELATE		0xEF, 0x01, 0xFF, 0xFF, 0xFF, 0xFF, 0x01, 0x00, 0x06, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, '#'
#define SEARCH_FINGER		0xEF, 0x01, 0xFF, 0xFF, 0xFF, 0xFF, 0x01, 0x00, 0x08, 0x04, 0x01, 0x00, 0x01, 0x00, 0x01, 0x00, 0x10, '#'
#define AURA_RED			0xEF, 0x01, 0xFF, 0xFF, 0xFF, 0xFF, 0x01, 0x00, 0x07, 0x35, 0x03, 0x0F, 0x01, 0x7D, 0x00, 0xCD, '#'
#define AURA_BLUE			0xEF, 0x01, 0xFF, 0xFF, 0xFF, 0xFF, 0x01, 0x00, 0x07, 0x35, 0x03, 0x0F, 0x02, 0x7D, 0x00, 0xCE, '#'
#endif /* HAL_FINGER_PRINT_FINGER_PRINT_CFG_H_ */