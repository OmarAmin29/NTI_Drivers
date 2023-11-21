/*
 * Wdt_Intf.h
 *
 *  Created on: Nov 5, 2023
 *      Author: lenovo
 */

#ifndef MCAL_WDT_WDT_INTF_H_
#define MCAL_WDT_WDT_INTF_H_


typedef enum{
    WDT_TIME_OUT_16_3_MS = 0,
    WDT_TIME_OUT_32_5_MS = 1,
    WDT_TIME_OUT_65_MS = 2,
    WDT_TIME_OUT_130_MS = 3,
    WDT_TIME_OUT_260_MS = 4,
    WDT_TIME_OUT_520_MS = 5,
    WDT_TIME_OUT_1000_MS = 6,
    WDT_TIME_OUT_2100_MS = 7    
}Wdt_SleepTimeType;

void M_WDT_Enable(void);
void M_WDT_Disable(void);
void M_WDT_sleep(Wdt_SleepTimeType sleepTime);
void M_WDT_refresh(void);

#endif /* MCAL_WDT_WDT_INTF_H_ */
