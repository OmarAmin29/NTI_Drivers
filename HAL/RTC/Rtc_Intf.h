/*
 * Rtc_Intf.h
 *
 *  Created on: Nov 3, 2023
 *      Author: lenovo
 */

#ifndef HAL_RTC_RTC_INTF_H_
#define HAL_RTC_RTC_INTF_H_


typedef enum{
    RTC_HOUR_AM = 0,
    RTC_HOUR_PM = 1  
}Rtc_TimeFormatType;



typedef struct{
    u8 RTC_SECOND;
    u8 RTC_MINUTE;
    u8 RTC_HOUR;
    Rtc_TimeFormatType format;
}Rtc_TimeType;


void H_Rtc_Init(void);
I2c_ErrorType H_Rtc_SetTime(const Rtc_TimeType* time);
I2c_ErrorType H_Rtc_GetTime(u8* second, u8* minute, u8* hour);
void H_Rtc_SetDate(void);
void H_Rtc_GetDate(void);

static u8 H_Rtc_DecimalToBcd(u8 decimal);
#endif /* HAL_RTC_RTC_INTF_H_ */
