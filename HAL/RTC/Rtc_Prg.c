/*
 * Rtc_Prg.c
 *
 *  Created on: Nov 3, 2023
 *      Author: lenovo
 */




#include"../../Private/Types.h"
#include"../../Private/Macros.h"
#include"../../MCAL/I2c/I2c.h"

#include"util/delay.h"
#include"../../MCAL/USART/Usart.h"
#include"Rtc_Priv.h"
#include"Rtc_Intf.h"



void H_Rtc_Init(void)
{
    M_I2c_Init(I2C_SCL_FREQ_100_KHZ);
}

I2c_ErrorType H_Rtc_SetTime(const Rtc_TimeType* time)
{
    u8 status;
    M_I2c_sendStart();
    /*Check status of start condition*/
    M_I2c_getStatus(&status);
    if(status != I2C_STATUS_MASTER_START_SENT)
    {
        return I2C_ERROR_START_NOT_SENT;
    }

    /*Send address of RTC and write*/
    M_I2c_sendByte(RTC_ADRESS | 0);
    /*Check status of sent data*/
    M_I2c_getStatus(&status);
    if(status != I2C_STATUS_MASTER_SA_W_ACK)
    {
        return I2C_ERROR_SLA_NACK;
    }

    /*Send address of byte in the RTC*/
    M_I2c_sendByte(SECONDS_ADRESS);
    /*Check status of send data*/
    M_I2c_getStatus(&status);
    if(status != I2C_STATUS_MASTER_DATA_SENT_ACK)
    {
        return I2C_ERROR_DATA_NACK;
    }

    /*Convert Decimal of Second To BCD*/
    u8 sec = H_Rtc_DecimalToBcd(time->RTC_SECOND);
    /*Send data of seconds*/
    M_I2c_sendByte(sec);
    //M_I2c_sendByte(0b01000101);
    /*Check status of sent data*/
    M_I2c_getStatus(&status);
    if(status != I2C_STATUS_MASTER_DATA_SENT_ACK)
    {
        return I2C_ERROR_DATA_NACK;
    }

    /*Convert Decimal of Minute To BCD*/
    u8 min = H_Rtc_DecimalToBcd(time->RTC_MINUTE);
    /*Send data of minutes*/
    M_I2c_sendByte(min);
    //M_I2c_sendByte(0b01110011);
    /*Check status of sent data*/
    M_I2c_getStatus(&status);
    if(status != I2C_STATUS_MASTER_DATA_SENT_ACK)
    {
        return I2C_ERROR_DATA_NACK;
    }

    /*Convert Decimal of Minute To BCD*/
    u8 hour = H_Rtc_DecimalToBcd(time->RTC_HOUR);
    /*Send data of hours*/
    M_I2c_sendByte(hour);
    //M_I2c_sendByte(0b01110011);
    /*Check status of sent data*/
    M_I2c_getStatus(&status);
    if(status != I2C_STATUS_MASTER_DATA_SENT_ACK)
    {
        return I2C_ERROR_DATA_NACK;
    }

    /*Send stop condition*/
    M_I2c_sendStop();

    return I2C_NO_ERROR;
}

I2c_ErrorType H_Rtc_GetTime(u8* second, u8* minute, u8* hour)
{
    /*Status variable to check I2c conditions*/
    u8 status;

    /*Send satrt condition*/
    M_I2c_sendStart();
    /*Check status of start condition*/
    M_I2c_getStatus(&status);
    if(status != I2C_STATUS_MASTER_START_SENT)
    {
        return I2C_ERROR_START_NOT_SENT;
    }

    M_I2c_sendByte(RTC_ADRESS | 0);
    /*Check status of sent data*/
    M_I2c_getStatus(&status);
    if(status != I2C_STATUS_MASTER_SA_W_ACK)
    {
        return I2C_ERROR_SLA_NACK;
    }

    /*Send address of byte in the RTC*/
    M_I2c_sendByte(SECONDS_ADRESS);
    /*Check status of send data*/
    M_I2c_getStatus(&status);
    if(status != I2C_STATUS_MASTER_DATA_SENT_ACK)
    {
        return I2C_ERROR_DATA_NACK;
    }

    /*Send repeated start*/
    M_I2c_sendStart();
    /*check status of repeated start*/
    M_I2c_getStatus(&status);
    if(status != I2C_STATUS_MASTER_REP_START_SENT)
    {
        return I2C_ERROR_START_NOT_SENT;
    }

    /*Send address of RTC and read*/
    M_I2c_sendByte(RTC_ADRESS | 1);
    /*Check status of sent data*/
    M_I2c_getStatus(&status);
    if(status != I2C_STATUS_MASTER_SA_R_ACK)
    {
        return I2C_ERROR_SLA_NACK;
    }

    /*Read the data of the second and send ACK*/
    M_I2c_receiveByte_ACK(second);
    //M_Usart_Transmit('1');
    M_I2c_getStatus(&status);
    if(status != I2C_STATUS_MASTER_DATA_RECEIVED_ACK)
    {
        return I2C_ERROR_DATA_NOT_RECEIVED;
    }
    _delay_ms(5);

    /*Read the data of minute and send ACK*/
    M_I2c_receiveByte_ACK(minute);
    //M_Usart_Transmit('2');
    M_I2c_getStatus(&status);
    if(status != I2C_STATUS_MASTER_DATA_RECEIVED_ACK)
    {
        return I2C_ERROR_DATA_NOT_RECEIVED;
    }

    /*Read the data of hour and send NACK*/
    M_I2c_receiveByte_NoACK(hour);
    //M_Usart_Transmit('3');
    M_I2c_getStatus(&status);
    if(status != I2C_STATUS_MASTER_DATA_RECEIVED_NACK)
    {
        return I2C_ERROR_DATA_NOT_RECEIVED;
    }

    /*Send Stop*/
    M_I2c_sendStop();
    return I2C_NO_ERROR;
}





static u8 H_Rtc_DecimalToBcd(u8 decimal)
{
    u8 units, tenth;
    u8 result;
    units = decimal % 10;
    tenth = (decimal / 10);

    result = units | (tenth << 4);
    return result;
}
