/*
 * Ssd.h
 *
 *  Created on: Oct 21, 2023
 *      Author: lenovo
 */

#ifndef HAL_SEVEN_SEGMENT_SSD_H_
#define HAL_SEVEN_SEGMENT_SSD_H_

#include "../../Private/Types.h"
#include"Ssd_Cfg.h"
#include"Ssd_Priv.h"

void SS_Init(void);
void SS_DisplayNumber(u8 number);


#endif /* HAL_SEVEN_SEGMENT_SSD_H_ */
